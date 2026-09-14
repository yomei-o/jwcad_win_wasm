// Decompile every function whose entry point falls in [lo, hi) to C.
//
// The range exists so the 5.5 MB of .text can be split across several
// headless processes: the decompiler itself is single threaded, so one run
// over the whole image would leave 19 of the build box's 20 cores idle.  Each
// shard opens the same already-analysed project read-only with -process.
//
//   -postScript DecompileRange <outDir> <loHex> <hiHex>
import ghidra.app.decompiler.DecompInterface;
import ghidra.app.decompiler.DecompileOptions;
import ghidra.app.decompiler.DecompileResults;
import ghidra.app.script.GhidraScript;
import ghidra.program.model.listing.Function;
import ghidra.program.model.listing.FunctionIterator;
import ghidra.util.task.ConsoleTaskMonitor;

import java.io.BufferedWriter;
import java.io.FileWriter;
import java.io.PrintWriter;

public class DecompileRange extends GhidraScript {

    /** Cap on one function's C.  Ghidra occasionally explodes on a big
     *  switch-heavy CRT routine and turns 500 bytes of code into megabytes. */
    private static final int MAX_C = 192 * 1024;

    /** Seconds to spend on one function before giving up on it. */
    private static final int TIMEOUT = 120;

    @Override
    public void run() throws Exception {
        String[] args = getScriptArgs();
        String outDir = args[0];
        long lo = Long.parseLong(args[1], 16);
        long hi = Long.parseLong(args[2], 16);
        new java.io.File(outDir).mkdirs();

        DecompInterface decomp = new DecompInterface();
        decomp.setOptions(new DecompileOptions());
        decomp.toggleCCode(true);
        decomp.toggleSyntaxTree(true);
        decomp.setSimplificationStyle("decompile");
        if (!decomp.openProgram(currentProgram)) {
            println("decompiler failed to open: " + decomp.getLastMessage());
            return;
        }

        String tag = String.format("%08x", lo);
        PrintWriter all = new PrintWriter(new BufferedWriter(
            new FileWriter(outDir + "/all_" + tag + ".c")));
        PrintWriter index = new PrintWriter(new BufferedWriter(
            new FileWriter(outDir + "/index_" + tag + ".csv")));
        index.println("address,name,size,callers,decompiled,clen");

        ConsoleTaskMonitor mon = new ConsoleTaskMonitor();
        FunctionIterator it =
            currentProgram.getFunctionManager().getFunctions(true);
        int ok = 0, fail = 0, skip = 0;
        while (it.hasNext()) {
            Function f = it.next();
            long at = f.getEntryPoint().getOffset();
            if (at < lo || at >= hi) {
                continue;
            }
            if (f.isThunk() || f.isExternal()) {
                skip++;
                continue;
            }
            String addr = f.getEntryPoint().toString();
            String name = f.getName();
            long size = f.getBody().getNumAddresses();
            int callers = f.getCallingFunctions(mon).size();

            DecompileResults res = decomp.decompileFunction(f, TIMEOUT, mon);
            boolean good = res != null && res.decompileCompleted()
                           && res.getDecompiledFunction() != null;
            int clen = 0;
            if (good) {
                String c = res.getDecompiledFunction().getC();
                clen = c.length();
                if (clen > MAX_C) {
                    c = c.substring(0, MAX_C) + "\n/* ... truncated: "
                        + clen + " bytes of C for this function. */\n";
                }
                all.println();
                all.println("/* " + addr + "  " + name + "  " + size
                            + " bytes, " + callers + " callers */");
                all.println(c);
                ok++;
            } else {
                fail++;
            }
            index.println(addr + "," + name + "," + size + "," + callers + ","
                          + (good ? 1 : 0) + "," + clen);
            if ((ok + fail) % 250 == 0) {
                all.flush();
                index.flush();
                println("[" + tag + "] " + (ok + fail) + " done");
            }
        }
        all.close();
        index.close();
        decomp.dispose();
        println("[" + tag + "] decompiled " + ok + ", failed " + fail
                + ", skipped " + skip);
    }
}
