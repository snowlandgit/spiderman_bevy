// Read-only selected swing-state decompilation. Names are recovered RTTI class + vtable slot.
// @category SpiderMan
import ghidra.app.script.GhidraScript;
import ghidra.app.decompiler.*;
import ghidra.program.model.address.Address;
import ghidra.program.model.listing.Function;
import java.nio.file.*;
import java.util.*;

public class DecompileSwing extends GhidraScript {
    public void run() throws Exception {
        String[] args = getScriptArgs();
        List<String> rows = Files.readAllLines(Paths.get(args[0]));
        DecompInterface decompiler = new DecompInterface();
        decompiler.openProgram(currentProgram);
        StringBuilder code = new StringBuilder("/* Decompiled from the locally installed Spider-Man.exe.\n" +
            " * Class names come from RTTI. Vtable slot names are labels, not recovered source names.\n" +
            " * Types and unnamed callees are incomplete. This is research, not recompilable source. */\n\n");
        int count = 0;
        for (String row : rows) {
            if (monitor.isCancelled()) break;
            String[] fields = row.trim().split("\\s+");
            if (fields.length != 2) continue;
            Address address = toAddr(fields[0]);
            disassemble(address);
            Function function = getFunctionAt(address);
            if (function == null) function = createFunction(address, fields[1]);
            if (function == null) { code.append("/* Failed function at " + fields[0] + " */\n"); continue; }
            DecompileResults result = decompiler.decompileFunction(function, 20, monitor);
            code.append("/* " + fields[1] + " @ " + fields[0] + " */\n");
            if (result.decompileCompleted() && result.getDecompiledFunction() != null) {
                code.append(result.getDecompiledFunction().getC()).append("\n");
                count++;
            } else code.append("/* " + result.getErrorMessage() + " */\n");
            println("Decompiled " + fields[1]);
        }
        Files.writeString(Paths.get(args[1]), code.toString());
        println("SWING_DECOMPILE_COMPLETE: " + count + " functions");
        decompiler.dispose();
    }
}
