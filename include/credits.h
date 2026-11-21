#ifndef CREDITS_H
#define CREDITS_H

#include "common.h"

/* Paired string addresses in the credits table (size 0x8).
 * The shifted view based at D_801EAF04 starts with a heading instead. */
typedef struct unkEAF00 {
    /* 0x0 */ u32 unk0; /* Name address in the D_801EAF00 view. */
    /* 0x4 */ u32 unk4; /* Heading address in the D_801EAF00 view. */
} unkEAF00;

/* Heading-first view at D_801EAF04; each step advances one credit pair. */
typedef struct CreditsHeadingEntry {
    /* 0x0 */ u32 headingText;
    /* 0x4 */ u32 nextNameText;
} CreditsHeadingEntry; /* size 0x8 */

/* func_80114F64 (credits_update_exit) keeps drawing credits until the menu
 * transition completes, then restores the requested retrace interval and text scale.
 * D_801E64C8 is the menu-transition completion flag.
 * D_801EFC92 is the requested paced-message retrace interval.
 * D_801ED3BC scales both dimensions of queued text.
 * D_80100694 and D_80100698 are the exit text scale and restored scale (both 1).
 * func_8010E558 is an empty hook; its original purpose is unknown.
 */

/* func_80114CC0 updates the scrolling credits menu.
 * D_801E6680 is the scroll distance in pixels; D_801E668C is row spacing.
 * D_801EAF00 holds name/heading pairs; D_801EAF0C starts at the next heading.
 * D_801F9214 is the menu cursor X position; D_801F652B is text opacity.
 * func_801469E4 queues text; func_801100B8 updates menu input and the cursor.
 * func_8010E400 starts the closing menu transition.
 * D_80100688/68C/690 are cursor target bias (32), easing divisor (4),
 * and credit text scale (1).
 */
enum CreditsScrollConstants {
    CREDITS_END_MARKER_CHAR = ' ',
    CREDITS_SCROLL_START_Y = 260,
    CREDITS_SCROLL_VISIBLE_SPAN = 279,
    CREDITS_SCROLL_TOP_Y = -19,
    CREDITS_SCROLL_NAME_X = 55,
    CREDITS_SCROLL_HEADING_X = 36,
    CREDITS_SCROLL_HEADING_GB = 155,
    CREDITS_EXIT_MENU_ID = 3,
    CREDITS_EXIT_RETRACE_INTERVAL = 2,
    CREDITS_SCROLL_RETRACE_INTERVAL = 3 /* requested by func_80114C5C (credits_scroll_init) */
};

/* func_80114C5C (credits_scroll_init) resets the scroll distance, selects the
 * alternate font, enables menu buttons (D_801E5898), starts the opening
 * transition and makes the text opaque. D_80100684 is its text scale. */

#endif
