/* Reading a .jww drawing.
 *
 * The shape of the file is CJw_winDoc::Serialize's, worked out in
 * tools/jww.py -- that script is the readable version of this and the two are
 * kept in step.  Nothing here opens a file: both front ends hand over the
 * bytes, so the browser build needs no file system.
 */
#ifndef JW_JWW_H
#define JW_JWW_H

enum {
    JW_SEN,         /* line          */
    JW_ENKO,        /* arc           */
    JW_TEN,         /* point         */
    JW_MOJI,        /* text          */
    JW_SOLID,       /* filled shape  */
    JW_BLOCK,       /* a figure standing for one of the definitions */
    JW_LIST,        /* one of those definitions: elements of its own       */
    JW_NCLASS
};

typedef struct {
    unsigned char cls;
    /* +0x28 is the line type for a line, the shape for a point, the size
       class for a text; +0x2a is the colour, which CDataSolid confirms --
       it checks for 10, Jw_cad's "any colour" pen. */
    unsigned char ltype;        /* +0x28 */
    unsigned short color;       /* +0x2a */
    unsigned short width;       /* +0x2c */
    unsigned short layer;       /* +0x2e  which layer, 0..15              */
    unsigned short lgroup;      /* +0x2f  which layer group, 0..15        */
    unsigned short flags;       /* +0x44                                  */
    /* Whether this element is picked *now*.  Not the same thing as bit 1 of
       flags, which is what the original writes to the file for whatever was
       picked when it was saved -- 天空率表.jww ships with 245 elements
       carrying it.  Opening that drawing in the original draws none of them
       pink, and saving it straight back leaves all 245 bits exactly as they
       were, so the bit is data the original carries rather than the selection
       it is showing.  The port keeps the two in step whenever it picks or
       drops something, so a drawing it saves still says what was picked. */
    unsigned char sel;          /* not in the file */
    int id;                     /* +0x04  a serial number, not the layer  */
    double d[8];                /* the geometry, class by class           */
    int n;                      /* the trailing long some classes carry   */
    /* JW_BLOCK: which definition it stands for.  A definition (JW_LIST)
       carries its own number in list[0], and this is that number. */
    int block;
    /* JW_LIST: the three numbers it keeps before its name -- its own
       number, a flag, and the moment it was made. */
    int list[3];
    /* JW_TEN with ltype 100 -- 任意点, which is what a point read from an
       SFC is: which marker, how far round it is turned, and how big. */
    int mark;
    double turn, size;
    int text, face;             /* byte offsets into the string pool, -1  */
} jw_obj;

typedef struct {
    int state, state2;
} jw_layer;

typedef struct {
    int state;                  /* 0 hidden, 1 shown, 2 editable, 3 write */
    int write_layer;            /* which of the 16 is being written to    */
    int c;
    double scale;
    jw_layer layer[16];
    int name;                   /* offset into the pool                   */
    int layer_name[16];
} jw_group;

typedef struct {
    int version;
    int name;                   /* offset into the pool                   */
    jw_group group[16];

    /* the sheet: its half width and half height in millimetres, from the
       corner the header keeps (an A2 sheet is -297,-210) */
    double paper_hw, paper_hh;
    int paper_size;

    /* 目盛 -- the grid of dots the original puts under a drawing.  Five
       doubles at the end of the settings block, which this reader used to
       step over: the smallest spacing in pixels it will draw at, the spacing
       across and down in paper millimetres, and where the grid starts.
       木造平面例.jww is the only one of the fifteen with 9 mm rather than 5,
       and the only one the original draws a grid for: 9 mm at its A4 scale
       is 29.4 pixels and the minimum is 15, while 5 mm comes to 11.5 at
       best. */
    double mesh_min, mesh_ix, mesh_iy, mesh_ox, mesh_oy;

    /* the ten screen pens.  The file stores a COLORREF, 0x00bbggrr. */
    unsigned int pen_rgb[10];
    int pen_width[10];
    /* and the ten printing pens, kept as the file has them (0x00bbggrr).
       Reading a DXF matches its colours against these, not the screen ones
       -- DXF colour 1, pure red, comes out as 線色8 because 線色8 prints
       red, though it is pink on screen. */
    unsigned int print_rgb[10];
    /* and the width it prints at, in screen dots.  Writing an SFC turns it
       into millimetres with dots * 25.4/300. */
    int print_width[10];

    /* The 257 「任意色」 -- colour numbers 100 to 356.  An element whose
       colour is 100 or more is asking for one of these rather than a pen.
       A drawing from the original's own template has the first sixteen
       named (black, red, ... darkgray) and the rest unused; reading a DXF
       fills the ones after that with the colours it finds. */
    unsigned int xcolor[257];
    int xcolor_n;               /* how many are in use: the named ones    */
    /* The rest of each colour's record, kept so it can be written back.
       The colour is in the file twice -- once here and once in the block of
       names -- and reading a DXF changes both. */
    struct {
        int pair;               /* the long beside the colour             */
        int name;               /* offset into the pool                   */
        unsigned int rgb2;      /* the colour again                       */
        int b;
        double w;
    } xcolor_rest[257];

    /* The 33 「任意線種」, which is where a DXF's line types end up too.
       pat[1..n] are the dash and gap lengths in paper millimetres. */
    struct {
        int n;
        int name;               /* offset into the pool                   */
        double pat[11];
    } sxf[33];
    int sxf_n;                  /* how many are in use                    */

    jw_obj *obj;
    int nobj, cobj;
    /* The file holds two lists: the drawing itself, then the block
       definitions.  Only the first is drawn -- a definition only appears
       through a reference to it. */
    int ndrawn;

    char *pool;                 /* flag byte, CP932 text, NUL, repeated   */
    int npool, cpool;

    /* Everything before the element list, kept exactly as it came in so it
       can be written back untouched.  There is far more in the header than
       this reader looks at, and copying it is the only way to save a drawing
       without inventing the parts it does not understand. */
    unsigned char *head;
    long nhead;
    /* Where the parts of it this reader does understand sit, so that a
       drawing can be written back with them changed.  A name is not a fixed
       size, so a block that holds names is written out again from what is
       above rather than copied; the numbers beside them are copied through
       that same code.  -1 means the version has no such block. */
    long off_scale[16];         /* each layer group's scale, eight bytes  */
    long off_names, end_names;  /* the 16 by 16 layer names, then 16 more */
    long off_ctab, end_ctab;    /* the 257 colours: numbers, then names   */
    long off_sxf, end_sxf;      /* the 33 任意線種                         */
    /* The ten text styles (文字種 1..10) and the one in force.  They sit
       just before the hatch and dimension settings at the end of the header
       -- ten records of three doubles and a long, then one more of the same
       shape, which is the current one (FUN_004eee80).  A text placed in
       Jw_cad comes out with exactly those numbers: Test1's current style is
       10/10/1 colour 5 and that is what its new text got, Test5's is
       20/20/0 colour 1 and so was its. */
    struct {
        double w, h, sp;
        int color;
    } style[10], cur_style;

    /* The pen new elements get.  Jw_cad starts every session with line type
       1 and colour 2 -- it is not kept in the file: saving a drawing with
       the pen set to line type 6 and opening it again gives 1 back, while
       the write layer, which is in the file, comes back as it was.  属性取得
       is what changes it. */
    unsigned char write_ltype;
    unsigned short write_color;
    unsigned short write_width;

    /* the schema number CArchive wrote with each class name */
    unsigned short schema[JW_NCLASS];
    /* version 700 only: the count of embedded images that follows the two
       lists.  Only 0 is understood, and it is written back as it came. */
    int nimage;

    const char *error;
} jw_drawing;

/* Parse `n` bytes.  Returns 0 and sets d->error on a malformed file. */
int  jw_parse(jw_drawing *d, const unsigned char *b, long n);
void jw_free(jw_drawing *d);

/* Add an element to the drawing, before the block definitions.  It comes out
   the way CData's constructor leaves one: line type 1, colour 2, no width,
   and on the write layer of the write layer group.  Returns NULL if the
   array could not grow. */
jw_obj *jw_add(jw_drawing *d, int cls);

/* Write the drawing back out, header and all.  The caller frees *out.
   Returns 0 if it could not (no header kept, or out of memory). */
int jw_write(const jw_drawing *d, unsigned char **out, long *n);

/* Write the drawing out as DXF, the way 「DXF形式で保存」 does (src/dxf.c).
   The caller frees *out. */
int jw_dxf_write(const jw_drawing *d, unsigned char **out, long *n);

/* Read a JWC into the drawing, the way 「JWCファイルを開く」 does
   (src/jwcread.c).  Returns 0 if the bytes are not a JWC. */
int jw_jwc_read(jw_drawing *d, const unsigned char *b, long n);

/* 包絡処理 (src/houraku.c): what the box does to the lines it catches.
   One entry per piece that comes out -- `at` says which element it came
   from, and `drop` says the element goes altogether.  An element with two
   entries was cut in two. */
typedef struct {
    int at;
    double x0, y0, x1, y1;
    int drop;
} jw_hou_out;

/* `erase` is the right button's 範囲内消去: what the box holds goes and
   what sticks out of it stays. */
int jw_houraku(const jw_drawing *d, double x0, double y0, double x1,
               double y1, const int *ltypes, int nltype, int erase,
               jw_hou_out **outp);

/* 「JWC形式で保存」 (src/jwcwrite.c). */
int jw_jwc_write(const jw_drawing *d, unsigned char **out, long *n);

/* Write the drawing out as SFC, the way 「SFC形式で保存」 does
   (src/sfcwrite.c).  `name` goes in FILE_NAME and `stamp` is the moment it
   claims to have been written, which the caller supplies because the
   original asks the clock.  The caller frees *out. */
int jw_sfc_write(const jw_drawing *d, const char *name, const char *stamp,
                 unsigned char **out, long *n);

/* Read an SFC into the drawing, the way 「SFCファイルを開く」 does
   (src/sfcread.c).  What it draws lands inside a 図形, which is what the
   original does with one.  Returns 0 if the bytes are not an SFC. */
int jw_sfc_read(jw_drawing *d, const unsigned char *b, long n);

/* Read a DXF into the drawing, the way 「DXFファイルを開く」 does
   (src/dxfread.c).  What was drawn goes; the header stays, except that the
   scale of every layer group is taken from the DXF's extents.  Returns 0 if
   the bytes are not a DXF. */
int jw_dxf_read(jw_drawing *d, const unsigned char *b, long n);

/* Take element `i` out of the drawing. */
void jw_remove(jw_drawing *d, int i);

/* The box an element fits in, and moving one.  Which of an element's numbers
   are a place and which are a size is the class's business -- an arc keeps
   its radius and its angles, a text its size, a solid has four corners. */
void jw_obj_box(const jw_obj *o, double *x0, double *y0,
                double *x1, double *y1);
void jw_obj_mirror(jw_obj *o, double px, double py, double ux, double uy);
void jw_obj_xform(jw_obj *o, double cx, double cy, double sc, double ang,
                  double dx, double dy);
void jw_obj_move(jw_obj *o, double dx, double dy);

/* Put a string in the drawing's pool and return its offset, for a new text.
   Returns -1 if it could not. */
int jw_add_str(jw_drawing *d, const char *s);

/* The text of an object, as CP932 bytes. */
const char *jw_str(const jw_drawing *d, int off);

/* Whether the file held that string as UTF-16 (version 700 does). */
int jw_str_wide(const jw_drawing *d, int off);

/* A 円ソリッド is a CDataSolid whose line type is 101, and its eight numbers
 * are an arc's rather than four corners: centre, radius, how flat, the turn,
 * where it starts, how far it goes, and a 5.  This fills *arc in as though
 * it were a CDataEnko, so that whoever writes an arc can write one of these
 * the same way -- which is what the original does in all three of its
 * formats.  Returns 0 when o is not one.
 */
int jw_round_solid(const jw_obj *o, jw_obj *arc);

/* Whether a text has a baseline with some length to it.  The original leaves
 * out of a DXF, an SFC and a JWC any text whose two ends are the same point,
 * which is how the six memo texts a DXF import leaves behind (Printer_
 * Orientation and the rest, at 0,-1000 with no length) stay out of them.
 * Driving it bears it out: of four texts differing one field at a time, the
 * one with no length was the only one missing from the DXF -- 補助線色 and
 * 文字種9 both came out.
 */
int jw_text_drawn(const jw_obj *o);

#endif
