/*
 * File: z-color.h
 * Purpose: Color constants
 */

#ifndef INCLUDED_Z_COLOR_H
#define INCLUDED_Z_COLOR_H

/*
 * Angband "attributes" (with symbols, and base (R,G,B) codes)
 *
 * The "(R,G,B)" codes are given in "fourths" of the "maximal" value,
 * and should be "gamma corrected" on most (non-Macintosh) machines.
 */
#define COLOUR_DARK           0   /* d */     /* 0 0 0 */
#define COLOUR_WHITE          1   /* w */     /* 4 4 4 */
#define COLOUR_SLATE          2   /* s */     /* 2 2 2 */
#define COLOUR_ORANGE         3   /* o */     /* 4 2 0 */
#define COLOUR_RED            4   /* r */     /* 3 0 0 */
#define COLOUR_GREEN          5   /* g */     /* 0 2 1 */
#define COLOUR_BLUE           6   /* b */     /* 0 0 4 */
#define COLOUR_UMBER          7   /* u */     /* 2 1 0 */
#define COLOUR_L_DARK         8   /* D */     /* 1 1 1 */
#define COLOUR_L_WHITE        9   /* W */     /* 3 3 3 */
#define COLOUR_L_PURPLE       10  /* P */
#define COLOUR_YELLOW         11  /* y */     /* 4 4 0 */
#define COLOUR_L_RED          12  /* R */     /* 4 0 0 */
#define COLOUR_L_GREEN        13  /* G */     /* 0 4 0 */
#define COLOUR_L_BLUE         14  /* B */     /* 0 4 4 */
#define COLOUR_L_UMBER        15  /* U */     /* 3 2 1 */

#define COLOUR_PURPLE         16  /* p */
#define COLOUR_VIOLET         17  /* v */     /* 4 0 4 */
#define COLOUR_TEAL           18  /* t */
#define COLOUR_MUD            19  /* m */
#define COLOUR_L_YELLOW       20  /* Y */
#define COLOUR_MAGENTA        21  /* i */
#define COLOUR_L_TEAL         22  /* T */
#define COLOUR_L_VIOLET       23  /* V */
#define COLOUR_L_PINK         24  /* I */
#define COLOUR_MUSTARD        25  /* M */
#define COLOUR_BLUE_SLATE     26  /* z */
#define COLOUR_DEEP_L_BLUE    27  /* Z */
#define COLOUR_SHADE          28  /* for shaded backgrounds */
#define COLOUR_MULTI          29  /* for object shimmering code */
#define COLOUR_SPECIAL        30  /* special coloring */
#define COLOUR_SYMBOL         31  /* special coloring */

/*
 * The following allow color 'translations' to support environments with a limited color depth
 * as well as translate colours to alternates for e.g. menu highlighting.
 */
#define ATTR_FULL   0   /* full color translation */
#define ATTR_MONO   1   /* mono color translation */
#define ATTR_VGA    2   /* 16 color translation */
#define ATTR_BLIND  3   /* "Blind" color translation */
#define ATTR_LITE   4   /* "Torchlit" color translation */
#define ATTR_DARK   5   /* "Dark" color translation */
#define ATTR_HIGH   6   /* "Highlight" color translation */
#define ATTR_METAL  7   /* "Metallic" color translation */
#define ATTR_MISC   8   /* "Miscellaneous" - see misc_to_attr */
#define ATTR_DOOR   9   /* "Door" color translation */

#define MAX_ATTR    10

/*
 * Maximum number of colours, and number of "basic" Angband colours
 */
#define MAX_COLORS      256
#define BASIC_COLORS    28

#define BG_BLACK    0   /* The set number for the black-background glyphs */
#define BG_SAME     1   /* The set number for the same-background glyphs */
#define BG_DARK     2   /* The set number for the dark-background glyphs */
#define BG_MAX      3   /* The max number of backgrounds */

/*
 * A game color.
 */
typedef struct
{
    char index_char;                /* Character index:  'r' = red, etc. */
    char name[32];                  /* Color name */
    uint8_t color_translate[MAX_ATTR]; /* Index for various in-game translations */
} color_type;

extern uint8_t angband_color_table[MAX_COLORS][4];
extern color_type color_table[MAX_COLORS];

extern int color_char_to_attr(char c);
extern int color_text_to_attr(const char *name);
extern uint8_t get_color(uint8_t a, int attr, int n);

extern void build_gamma_table(int gamma);
extern uint8_t gamma_table[256];

#endif
