// Decompile every function whose name contains one of the given patterns.
//
//   -postScript DecompileNamed <outFile.c> <pat1> <pat2> ...
//
// DecompileRange takes a slice of the address space, which is what you want
// when the whole image has to come out.  This is the other case: a binary with
// symbols, where the handful of functions worth reading is known by name --
// win32kfull.sys's arc and Bezier code, say.  Matching is case-insensitive and
// on a substring, so `BEZIER` finds BEZIER32::vInit and BEZIER64::bNext alike.
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

public class DecompileNamed extends GhidraScript {

    private static final int MAX_C = 192 * 1024;
    private static final int TIMEOUT = 300;

    @Override
    public void run() throws Exception {
        String[] args = getScriptArgs();
        String outFile = args[0];
        String[] pats = new String[args.length - 1];
        for (int i = 1; i < args.length; i++) {
            pats[i - 1] = args[i].toLowerCase();
        }

        DecompInterface decomp = new DecompInterface();
        decomp.setOptions(new DecompileOptions());
        decomp.toggleCCode(true);
        decomp.toggleSyntaxTree(true);
        decomp.setSimplificationStyle("decompile");
        if (!decomp.openProgram(currentProgram)) {
            println("decompiler failed to open: " + decomp.getLastMessage());
            return;
        }

        PrintWriter out = new PrintWriter(new BufferedWriter(
            new FileWriter(outFile)));
        ConsoleTaskMonitor mon = new ConsoleTaskMonitor();
        FunctionIterator it =
            currentProgram.getFunctionManager().getFunctions(true);
        int ok = 0, fail = 0;
        while (it.hasNext()) {
            Function f = it.next();
            if (f.isThunk() || f.isExternal()) {
                continue;
            }
            // the fully qualified name: BEZIER32::bNext is called just
            // "bNext" by getName(), so a pattern naming the class would miss
            // it -- and the class is what one wants to ask for
            String name = f.getName(true);
            String lower = name.toLowerCase();
            boolean want = false;
            for (String p : pats) {
                if (lower.contains(p)) {
                    want = true;
                    break;
                }
            }
            if (!want) {
                continue;
            }
            String addr = f.getEntryPoint().toString();
            long size = f.getBody().getNumAddresses();
            int callers = f.getCallingFunctions(mon).size();
            println("decompiling " + addr + " " + name);

            DecompileResults res = decomp.decompileFunction(f, TIMEOUT, mon);
            boolean good = res != null && res.decompileCompleted()
                           && res.getDecompiledFunction() != null;
            out.println();
            out.println("/* " + addr + "  " + name + "  " + size
                        + " bytes, " + callers + " callers */");
            if (good) {
                String c = res.getDecompiledFunction().getC();
                if (c.length() > MAX_C) {
                    c = c.substring(0, MAX_C) + "\n/* ... truncated */\n";
                }
                out.println(c);
                ok++;
            } else {
                out.println("/* did not decompile: "
                            + (res == null ? "null" : res.getErrorMessage())
                            + " */");
                fail++;
            }
        }
        out.close();
        println("DecompileNamed: " + ok + " decompiled, " + fail + " failed");
    }
}
