// One CSV row per function: where it is, how big, who calls it, and whether
// Ghidra recognised it as library code.
//
// Jw_win.exe is 5.5 MB of .text with MFC and the CRT linked in statically, so
// the first question is not "what does this function do" but "which of these
// are even Jw_cad's".  Ghidra's Function ID and the MSVC demangler answer that
// for most of the runtime, and this dumps the answer in one pass.
//
//   -postScript Inventory <outFile>
import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.Address;
import ghidra.program.model.listing.Function;
import ghidra.program.model.listing.FunctionIterator;
import ghidra.program.model.symbol.SourceType;
import ghidra.util.task.ConsoleTaskMonitor;

import java.io.BufferedWriter;
import java.io.FileWriter;
import java.io.PrintWriter;

public class Inventory extends GhidraScript {

    private static String csv(String s) {
        if (s == null) {
            return "";
        }
        if (s.indexOf(',') >= 0 || s.indexOf('"') >= 0) {
            return '"' + s.replace("\"", "\"\"") + '"';
        }
        return s;
    }

    @Override
    public void run() throws Exception {
        String[] args = getScriptArgs();
        String out = args.length > 0 ? args[0] : "inventory.csv";
        PrintWriter w = new PrintWriter(new BufferedWriter(new FileWriter(out)));
        w.println("address,size,callers,callees,source,thunk,external,name,qualified");

        ConsoleTaskMonitor mon = new ConsoleTaskMonitor();
        FunctionIterator it =
            currentProgram.getFunctionManager().getFunctions(true);
        int n = 0;
        long bytes = 0;
        while (it.hasNext()) {
            Function f = it.next();
            Address a = f.getEntryPoint();
            long size = f.getBody().getNumAddresses();
            SourceType st = f.getSymbol() == null ? SourceType.DEFAULT
                                                  : f.getSymbol().getSource();
            w.println(a + "," + size + ","
                      + f.getCallingFunctions(mon).size() + ","
                      + f.getCalledFunctions(mon).size() + ","
                      + st + "," + (f.isThunk() ? 1 : 0) + ","
                      + (f.isExternal() ? 1 : 0) + "," + csv(f.getName())
                      + "," + csv(f.getName(true)));
            n++;
            bytes += size;
        }
        w.close();
        println("Inventory: " + n + " functions, " + bytes + " bytes of body");
    }
}
