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
    unsigned short f2e, f2f, flags;
    int id;                     /* +0x04                                  */
    double d[8];                /* the geometry, class by class           */
    int n;                      /* the trailing long some classes carry   */
    int text, face;             /* byte offsets into the string pool, -1  */
} jw_obj;

typedef struct {
    int state, state2;
} jw_layer;

typedef struct {
    int a, b, c;
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

    char *pool;                 /* NUL-separated CP932 strings            */
    int npool, cpool;

    const char *error;
} jw_drawing;

/* Parse `n` bytes.  Returns 0 and sets d->error on a malformed file. */
int  jw_parse(jw_drawing *d, const unsigned char *b, long n);
void jw_free(jw_drawing *d);

/* The text of an object, as CP932 bytes. */
const char *jw_str(const jw_drawing *d, int off);

#endif
