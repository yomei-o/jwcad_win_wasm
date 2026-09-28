u"""GDI's own arctangent table, `gaefArctan`, as it sits in win32kbase.sys.

Taken with tools/ghidra_scripts/DumpFloats.java from
`C:\Windows\System32\win32kbase.sys` (10.0.26100), symbol `gaefArctan` at
1402af470.  Thirty-three single-precision **degrees**: entry i is
atan(i/32) in degrees, and entry 32 is 45.  `vArctan` divides
`lo * FP_ARCTAN_TABLE_SIZE / hi` -- the size is 32, not 64, which is what
the port had guessed -- truncates that to an index, and interpolates
between entry i and entry i+1 by the fraction.

Kept as the raw 4-byte patterns so the numbers are the ones GDI has, to
the last bit.
"""
import struct

SIZE = 32

BITS = [
    0, 1071979466, 1080353450, 1084973803, 1088684066, 1091442478,
    1093265948, 1095068903, 1096848500, 1098602133, 1099617547, 1100464997,
    1101296328, 1102110758, 1102907639, 1103686447, 1104446778, 1105188343,
    1105910958, 1106614536, 1107297667, 1107630460, 1107953850, 1108267943,
    1108572870, 1108868788, 1109155869, 1109434302, 1109704291, 1109966047,
    1110219788, 1110465739, 1110704128, 0,
]

TABLE = [struct.unpack('<f', struct.pack('<I', b))[0] for b in BITS]


# gaefSin at 1402af3a0: sin(i * 90/32 degrees) for i = 0..32, in single
# precision.  `efSin` and `vCosSin` walk this one the same way `vArctan`
# walks the other -- truncate, look up, interpolate -- and the constants
# that follow it in the image are the ones they divide by.
SIN_BITS = [
    0, 1028193072, 1036565814, 1041645699, 1044891074, 1048104908,
    1049927729, 1051491540, 1053028117, 1054533760, 1056004842, 1057201213,
    1057896922, 1058570176, 1059219353, 1059842890, 1060439283, 1061007097,
    1061544963, 1062051586, 1062525745, 1062966298, 1063372184, 1063742424,
    1064076126, 1064372488, 1064630795, 1064850424, 1065030846, 1065171628,
    1065272429, 1065333007, 1065353216,
]

SIN = [struct.unpack('<f', struct.pack('<I', b))[0] for b in SIN_BITS]

SINE_FACTOR = struct.unpack('<f', struct.pack('<I', 1052117857))[0]
EPSILON = struct.unpack('<f', struct.pack('<I', 931135488))[0]
FOUR_THIRDS = struct.unpack('<f', struct.pack('<I', 1068149419))[0]
ALPHA_Q = 0x729d7775          # (1 - kappa) as a 0.32 fraction
AXIS_COORD = [0.0, 1.0, 0.0, -1.0]
AXIS_ANGLE = [0.0, 90.0, 180.0, 270.0]
