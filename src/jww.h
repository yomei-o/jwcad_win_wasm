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

    char *pool;                 /* NUL-separated CP932 strings            */
    int npool, cpool;

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

/* Take element `i` out of the drawing. */
void jw_remove(jw_drawing *d, int i);

/* The text of an object, as CP932 bytes. */
const char *jw_str(const jw_drawing *d, int off);

#endif
