"""Bake chosen strings out of the original's string table.

    python tools/mkstr.py

The status line's prompts are string-table entries: the 線 command shows
5320 while it waits for the first point and 5321 while it waits for the
second (CZukeiSen calls FUN_004efbb0(0x14c8) and (0x14c9) at those two
points), 点 shows 5376 (CZukeiTen, FUN_004efbb0(0x1500)), and 円 shows 5309
then 5301 (CZukeiEnko, FUN_004efbb0(0x14bd) and (0x14b5)), and 消去 shows
10111 (CZukeiShoukyo, FUN_004efbb0(0x277f)), which is also where the two
buttons' jobs are written down: (L) is a partial erase, (R) deletes the
whole element.  They are written out as CP932 bytes because that is how the font
is indexed, and as escapes so this file stays plain ASCII.
"""
WANT = [
    (5320, 'the first point of a line'),
    (5321, 'the second point of a line'),
    (5376, 'where to put a point'),
    (5503, 'which temporary point to delete'),
    (5623, 'the first line or circle to cross'),
    (5624, 'the second one'),
    (5309, 'the centre of a circle'),
    (5347, 'choose a fitting (tategu plan)'),
    (5478, 'the reference line, or two points (tategu plan)'),
    (5541, 'set a measuring point (shadow diagram)'),
    (5712, 'set a measuring point (sky diagram)'),
    (5713, 'position of the sky diagram circle centre'),
    (5582, 'where to write the measuring conditions (shadow diagram)'),
    (5650, 'pick a circle or polyline to make solid'),
    (5560, 'where to write the result (shadow diagram tables)'),
    (5403, 'choose an item (shadow diagram sub-bar)'),
    (5525, 'set the true north (shadow diagram)'),
    (5435, 'AUTO: a line picked -- partial erase, stretch, corner'),
    (5490, 'choose a symbol (line symbol change)'),
    (5362, 'the first line to point at (line symbol change)'),
    (5363, 'the second line to point at (line symbol change)'),
    (5365, 'type or change the text (line symbol change)'),
    (5346, 'where the fitting goes (tategu plan)'),
    (5364, 'a position pointed with the mouse (polygon, base point not the centre)'),
    (5310, 'which side to draw the triangle on (polygon, two sides)'),
    (5301, 'a point the circle passes through'),
    (10111, 'what the two buttons do when erasing'),
    (10112, 'the first end of the piece to take out of a line'),
    (10113, 'the second end of it'),
    (10114, 'the first end of the piece to take out of a circle'),
    (10115, 'the second end of it'),
    (5340, 'the first line of a corner'),
    (5341, 'the second line of it'),
    (5336, 'the line to stretch or shorten'),
    (5338, 'where its end should go'),
    (5337, 'the line to stretch to the reference line'),
    (5339, 'the right button down once: move to cut, right again for a reference line'),
    (5305, 'the line to make a parallel of'),
    (5366, 'which side to put it'),
    (5263, 'the element to take the pen and layer from'),
    (5316, 'before anything is typed'),
    (5318, 'where the typed text goes'),
    (5383, 'the first corner of a range'),
    (5326, 'the second one -- the right button takes the texts too'),
    (5314, 'the point a copy or a move is measured from'),
    (5325, 'the box is made: click to add or take away (range commands)'),
    (5828, 'Enter confirms the range (copy, move, data tidy)'),
    (5829, 'Shift-Enter changes the base point (copy, move)'),
    (5762, 'the tail of the second-corner prompt'),
    (5304, 'the start of an arc'),
    (5312, 'parallel line: type the interval or click where it goes'),
    (5708, 'parallel line: the tail of the direction prompt'),
    (5307, 'where the copy goes'),
    (5311, 'where the move goes'),
    (5329, 'a dimension: where its extension lines start'),
    (5330, 'where its line goes'),
    (5331, 'the first point it measures'),
    (5332, 'the second'),
    (5333, 'and again, once one dimension is in'),
    (5367, 'the circle the circumference mode wants indicated first'),
    (5345, 'the line the angle and length grabs want pointed at'),
    (10119, 'the far end of the two-point length grab'),
    (10117, 'the base point of the two-point angle grab'),
    (10118, 'and its angle point, which X-axis angle shows for both'),
    (10043, 'the number grabs: point at a number written in the drawing'),
    (10020, 'and the axis-angle grab leads with this'),
    (5323, 'the next point of a measuring run'),
    (5462, 'what the point-at-a-distance command asks for once its start is down'),
    (5264, 'which layer to hide: point at something on it'),
    (5405, 'and the point whose coordinates are wanted'),
    (6159, 'the tail those two modes put on: anticlockwise'),
    (6158, 'and the name of the one, the circumference'),
    (6157, 'and of the other, the angle'),
    (5576, 'the dimension-value button: its start point, and what R and RR do'),
    (5391, 'the first line the batch mode takes'),
    (5392, 'the last one'),
    (5393, 'the ones to add or drop, and what confirms'),
    (5473, 'the text join/cut mode of the text bar'),
    (5474, 'and once one text is picked, what the two buttons do'),
    (5327, 'the first corner of the box the weld works in'),
    (5328, 'the second one, and what the two buttons do there'),
    (5357, 'the first line or circle a division takes'),
    (5358, 'the second one, once the first is a line'),
    (5359, 'the second one, once the first is a circle'),
    (5360, 'two points taken by (R)(R): the line or circle to divide them along'),
    (5361, 'once the first thing taken is a point: the second, or a whole circle'),
    (5819, 'continuous point division, under two points so far'),
    (5820, 'continuous point division, two or more points so far'),
    (5434, 'AUTO mode, nothing in hand'),
    (5519, 'set the height and depth of a line end (2.5D)'),
    (5524, 'set the height of a building at a line end (shadow)'),
    (5368, 'the second circle a tangent takes'),
    (5372, 'the first line or circle a tangent circle takes'),
    (5373, 'the second one'),
    (5374, 'the third one, when no radius was typed'),
    (5375, 'and where to put the circle, once the radius settles it'),
    (5377, 'the first line or arc of the ring a hatch fills'),
    (5378, 'the next one, once the chain has started'),
    (5487, 'the element whose attributes are to be changed'),
    (5353, 'where a figure goes'),
    (5354, 'and what it says when no figure has been read'),
    (5404, 'the origin of a sine or quadratic curve'),
    (5416, 'the middle point of a quadratic curve, or of a spline'),
    (5417, 'the amplitude point of a sine curve'),
    (5418, 'and the point one cycle of it reaches'),
    (5401, 'where a double line starts, once its base line is picked'),
    (5402, 'and where it ends'),
    (5420, 'which cleanup to run, once a selection is settled'),
    (5409, 'a picture read: where its lower left goes'),
    (10147, 'trim: the first corner of the part to keep'),
    (10148, 'trim: the opposite corner'),
    (10149, 'fit: the first point on the picture'),
    (10150, 'fit: the second point on the picture'),
    (10151, 'fit: where the first goes'),
    (10152, 'fit: where the second goes'),
    (10153, 'untrim: the picture to restore'),
    (10154, 'move: the picture to move'),
    (10155, 'move: where it goes'),
    (10160, 'embed the pictures: are you sure'),
    (10161, 'N pictures embedded'),
    (10162, 'too many pictures to embed'),
    (10167, 'separate them into this folder'),
    (10168, 'a new drawing must be saved first'),
    (10169, 'N pictures separated'),
    (10171, 'transparent colour: the picture to set it on'),
    (5410, 'parametric: a typed offset -- confirm with (L) or Enter'),
    (6010, 'parametric: done (the message after each change)'),
    (5201, 'notice: there is no element'),
    (5205, 'notice: it cannot be worked out'),
    (5207, 'notice: a whole circle -- cut it into an arc first'),
    (5214, 'notice: an ellipse cannot be worked out'),
    (5231, 'notice: it is a block'),
    (5262, 'notice: it is the layer being written'),
    (5342, 'notice: not a straight line'),
    (5343, 'notice: the same point'),
    (5351, 'notice: the same line'),
    (5498, 'notice: blocks, dimension figures and protected layers do not move (parallel)'),
    (5522, 'notice: there is no data'),
    (6009, 'notice: the figure was moved'),
    (10038, 'notice: figure registered'),
    (5529, 'notice: the data does not fit (shadow diagram wall)'),
    (5208, 'notice: it is a circle'),
    (5611, 'notice: reverse division (division helper)'),
    (5612, 'notice: division by length ratio (division helper)'),
    (5388, 'the base line of a stretch all at once'),
    (5389, 'the first base line of an erase all at once, or its first line'),
    (5390, 'the second base line of an erase all at once'),
    (5601, 'point: free (LL), Read (R)'),
    (5352, 'the base point of text position (range select, 1071)'),
    (5472, 'text count write, appended to 5318 (range select, 1121)'),
    (6238, 'base point button (range select, 1072)'),
    (6177, '(bottom left)'),
    (6178, '(bottom centre)'),
    (6179, '(bottom right)'),
    (6180, '(middle left)'),
    (6181, '(middle centre)'),
    (6182, '(middle right)'),
    (6183, '(top left)'),
    (6184, '(top centre)'),
    (6185, '(top right)'),
]

STRINGS = 'decomp/res/string.txt'
OUT = 'src/gen/prompts.h'


def strings():
    import re
    out, cur = {}, None
    for line in open(STRINGS, encoding='utf-8'):
        m = re.match(r'\s*(\d+) 0x[0-9a-f]+  (.*)$', line)
        if m:
            cur = int(m.group(1))
            out[cur] = m.group(2)
        elif cur is not None and line.strip():
            pass          # the second line is the tooltip, not wanted here
    return out


def esc(s):
    BS = chr(92)
    keep = '"' + BS + '?'
    out = []
    b = s.encode('cp932')
    for i, c in enumerate(b):
        if c > 0x7e or c < 0x20 or chr(c) in keep:
            out.append(BS + 'x%02x' % c)
            # C eats as many hex digits as it can, so stop the escape
            # if a hex digit comes next
            if i + 1 < len(b) and chr(b[i + 1]) in '0123456789abcdefABCDEF':
                out.append('" "')
        else:
            out.append(chr(c))
    return ''.join(out)


def main():
    st = strings()
    with open(OUT, 'w', encoding='ascii', newline='\n') as f:
        f.write('/* Generated by tools/mkstr.py from the original\'s string table. */\n')
        f.write('#ifndef JW_PROMPTS_H\n#define JW_PROMPTS_H\n\n')
        f.write('/* CP932, which is how src/text.c indexes the font. */\n')
        for num, what in WANT:
            f.write('/* %d: %s */\n' % (num, what))
            f.write('#define JW_STR_%d "%s"\n' % (num, esc(st[num])))
        f.write('\n#endif\n')
    print('wrote', OUT)
    for num, _ in WANT:
        print(' %d %s' % (num, st[num]))


main()
