#ifndef SAVE_MENU_H
#define SAVE_MENU_H

/* func_80112338 initializes the save-file menu; func_80110598 draws and
 * updates it. D_801EAB24 is the selected save slot, D_801F65A8 holds six
 * 0x74-byte slot sprites, and D_801E65B4 is their baseline Y.
 * D_801003B4/D_801003C0 name the model/slot texture resources.
 * D_80269F44/48 alias model slots 1/2 in D_80269F40.
 * D_801E65AC suppresses the selected entry's callback when leaving via Cancel.
 * func_8010E560 starts the menu transition effect; func_8010EEF8 appends a
 * model, func_80142700 enables components, func_80133998 queues animation,
 * func_8014A50C initializes a sprite, and func_8010F0B8 saves slide origins.
 * Pool roles: D_801003D0 = model Z; D_801003D4 = rotation angle;
 * D_801003D8/DC = Y/Z scales; D_801003E0/E8 = first/second animation speed;
 * D_801003E4 = initial X scale; D_801003EC = third model's creation X scale.
 */
/* func_801126C4: save_menu_finish_exit.
 * D_801E65AC: skip callback after Cancel; D_801E65B0: menu input enabled.
 * D_801E65A4: save-menu confirmation mode, cleared on exit.
 * D_801F6C88: selected callback pending; D_801E58A4: destination menu ID.
 * func_8010F23C slides models out; func_8010E558 is an empty hook.
 * func_80155A44 disables drawing and waits for the drawing task to stop.
 * func_8011FF08 unlinks a sprite and releases its resources.
 * func_8010F94C releases all menu models and their components.
 * Symbol names are retained because rename_symbol does not support N64 yet.
 */
/* func_80110520: save_menu_toggle_copy, the Copy entry's action.
 * D_801E65A0: copy mode active (a source slot has been picked).
 * D_801F6864: copy source slot, compared with D_801EAB24 (the target).
 * D_801E65A4 values: SaveMenuConfirm below.
 */
enum SaveMenuConfirm {
    SAVE_MENU_CONFIRM_NONE = 0,
    SAVE_MENU_CONFIRM_COPY = 1,       /* ask before copying over the selected slot */
    SAVE_MENU_CONFIRM_ERASE = 2,      /* ask before overwriting a non-empty slot with New Game */
    SAVE_MENU_CONFIRM_ERASE_DONE = 3  /* erase confirmed; exit into New Game on next step */
};

enum SaveMenuConstants {
    SAVE_MENU_MODEL_COUNT = 3,
    SAVE_MENU_SPRITE_BYTES = 0x74,
    SAVE_MENU_ICON_Y_OFFSET = 5,
    SAVE_MENU_INITIAL_ENTRY = 1,
    SAVE_MENU_SLOT_COUNT = 6,
    SAVE_MENU_WORLD_COUNT = 6,
    SAVE_MENU_SLOT_STRIDE = 0x1C,
    SAVE_MENU_EMPTY_MARKER = 0xD,
    SAVE_MENU_CMD_CONFIRM = 4,
    SAVE_MENU_CMD_BACK = 5,
    SAVE_MENU_CMD_IDLE = 6,
    SAVE_MENU_STICK_COOLDOWN = 8,
    SAVE_MENU_STICK_THRESHOLD = 20,
    SAVE_MENU_SFX_MOVE = 0xD4,
    SAVE_MENU_SFX_CONFIRM = 0xD8
};

/* func_8010E6AC: menu_transition_update.
 * The two 0x74-byte sprites use the ScreenParticle prefix:
 * D_801F644C/64C0 are left/right X, D_801F6450/64C4 their shared Y.
 * D_801E64CC: sprites initialized; D_801E64C0: movement direction.
 * D_801E64C4: accelerating X step; D_801E64C8: transition complete.
 * D_801E5894 enables the visible transition and closing audio fade.
 * D_801F6528 is text opacity (its low byte is D_801F652B).
 * D_801E7658 is the current volume for audio group 2.
 * func_801C066C sets master volume for each group selected by its bitmask.
 * Pool values: D_80100118 = hidden Y (520), D_8010011C = visible Y (120),
 * D_80100120 = open left-X limit (-250), D_80100124 = closed X (160),
 * D_80100128 = per-update speed multiplier (1.16).
 */
/* func_8010E400: startMenuClosingTransition.
 * func_8014A50C initializes a screen sprite and inserts it in draw order.
 * D_801F6440/D_801F64B4 are the left/right curtain sprites (0x74 bytes each).
 * Their image names D_801000D0/DC are "fade1.bmp"/"fade2.bmp".
 * D_801F6458/64CC are X scales; D_801F645C/64D0 are Y scales, in 1/1024 units.
 * D_801F6460/61/62 and D_801F64D4/D5/D6 are left/right RGB.
 * D_801F64AC/6520 are their draw-enable words, initially cleared.
 * D_801000F0/F4 are initial left/right X (-250/550);
 * D_801000F8/FC are closing start X (-220/520); D_80100100 is X step (1.2).
 * Symbol names remain address-based because N64 rename_symbol is unsupported.
 */
/* func_8010E560: startMenuOpeningTransition.
 * D_80100104/108 are initial left/right X (-250/550);
 * D_8010010C/110 are opening start X (178/122), overlapping at the center;
 * D_80100114 is the opening X step (1.5 pixels before acceleration).
 * The sprite globals and their component aliases retain their declared types.
 */
enum MenuTransitionConstants {
    MENU_TRANSITION_CENTER_X = 160,
    MENU_TRANSITION_CENTER_Y = 120,
    MENU_TRANSITION_SCALE_X = 13000,
    MENU_TRANSITION_SCALE_Y = 9300,
    MENU_TRANSITION_IDLE_DIRECTION = 0,
    MENU_TRANSITION_CLOSE_DIRECTION = 1,
    MENU_TRANSITION_TEXT_OPAQUE = 255,
    MENU_TRANSITION_OPEN_DIRECTION = -1,
    MENU_TRANSITION_AUDIO_GROUP = 2,
    MENU_TRANSITION_VOLUME_FADE_STEP = 1000,
    MENU_TRANSITION_TEXT_FADE_STEP = 10
};

/* func_8010E174: menu_start_practice.
 * Wait for D_801E64C8 (menu transition complete), then start practice level 9.
 * D_801E589C enables practice mode; D_801000C4 is the "practice" drawing tag.
 * D_801EAB24 selects the save slot; D_801EAAEC is temporary slot 6's
 * 28-byte record, and D_801EAA55 addresses the difficulty byte of slot 0.
 * D_80092030/D_800B7830 are the two 320x240 16-bit framebuffers.
 * D_801E753C/753E hold the current/target screen transition extent.
 * D_801E58A4 is the destination menu ID; D_801E747C is the menu frame counter.
 * func_8012A738 sets the backdrop RGB; func_80122F9C updates transition values.
 * func_80155A44 pauses drawing; func_8012C2B0 fills bytes.
 * func_8010EBE8 releases scene resources and resets the scene heap.
 * func_8013FBC0 clears bytes; func_8011F9F4 resets new-game progress;
 * func_8011FF40 initializes the requested level. func_8010E558 is empty.
 */
enum PracticeMenuConstants {
    PRACTICE_SAVE_SLOT = 6,
    PRACTICE_DIFFICULTY_NORMAL = 1,
    PRACTICE_LEVEL = 9
};

#endif
