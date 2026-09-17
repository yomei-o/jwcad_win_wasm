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
    int id;                     /* +0x04  a serial number, not the layer  */
    double d[8];                /* the geometry, class by class           */
    int n;                      /* the trailing long some classes carry   */
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

    /* the ten screen pens.  The file stores a COLORREF, 0x00bbggrr. */
    unsigned int pen_rgb[10];
    int pen_width[10];

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

/* Take element `i` out of the drawing. */
void jw_remove(jw_drawing *d, int i);

/* The box an element fits in, and moving one.  Which of an element's numbers
   are a place and which are a size is the class's business -- an arc keeps
   its radius and its angles, a text its size, a solid has four corners. */
void jw_obj_box(const jw_obj *o, double *x0, double *y0,
                double *x1, double *y1);
void jw_obj_move(jw_obj *o, double dx, double dy);

/* Put a string in the drawing's pool and return its offset, for a new text.
   Returns -1 if it could not. */
int jw_add_str(jw_drawing *d, const char *s);

/* The text of an object, as CP932 bytes. */
const char *jw_str(const jw_drawing *d, int off);

/* Whether the file held that string as UTF-16 (version 700 does). */
int jw_str_wide(const jw_drawing *d, int off);

#endif
