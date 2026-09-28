// Print a run of 4-byte floats starting at a named symbol.
//
//   -postScript DumpFloats <outFile> <symbol> <count>
//
// GDI keeps its arctangent as a table it interpolates (`vArctan` in
// win32kfull.sys), and the port cannot match GDI's arcs to the pixel
// without the same numbers.  DecompileNamed gets the code; this gets the
// data beside it.
import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.Address;
import ghidra.program.model.symbol.Symbol;
import ghidra.program.model.symbol.SymbolIterator;

import java.io.PrintWriter;

public class DumpFloats extends GhidraScript {

    @Override
    public void run() throws Exception {
        String[] args = getScriptArgs();
        if (args.length < 3) {
            println("DumpFloats <outFile> <symbol> <count>");
            return;
        }
        String out = args[0];
        String want = args[1];
        int count = Integer.parseInt(args[2]);

        PrintWriter w = new PrintWriter(out);
        int found = 0;
        SymbolIterator it = currentProgram.getSymbolTable().getAllSymbols(true);
        while (it.hasNext() && !monitor.isCancelled()) {
            Symbol s = it.next();
            String n = s.getName();
            if (!n.toLowerCase().contains(want.toLowerCase()))
                continue;
            found++;
            Address a = s.getAddress();
            w.println("# " + n + " at " + a);
            for (int i = 0; i < count; i++) {
                try {
                    int bits = currentProgram.getMemory()
                            .getInt(a.add((long) i * 4));
                    w.println(i + " " + bits + " "
                              + Float.intBitsToFloat(bits));
                } catch (Exception e) {
                    w.println(i + " -");
                    break;
                }
            }
            if (found > 4)
                break;
        }
        w.close();
        println("DumpFloats: " + found + " symbols matched " + want);
    }
}
