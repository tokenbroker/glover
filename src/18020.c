#include "common.h"
#include "structs.h"
#include "math_types.h"

extern f32 D_8028FB3C;
extern s16 D_8028FB40;
extern u8 D_80202218;
extern s16 D_801FAA90;
extern s16 D_801FAA92;
extern u8 D_801FAAC6;
void func_8015C350(u8 *, s32 *);

extern s32 D_801E64C8;
extern u8 D_801EAA55;
extern s8 D_801E7532;
extern s32 D_801E693C[][14];
extern u8 D_801E6792[][6];
void func_80132C04(void);
void func_80132DA8(void);
void func_8010E0D8(s32, s32);
extern u8 D_801F7578[];
extern u8 D_801F6E38[];
extern u8 D_801F6DC0[];
extern u8 D_801F7CB8[];
void func_8010F23C(s32);
void func_8010E558(void);
void func_8010F94C(void);
void func_8011FF08(s32);

void func_8010EBE8();
extern s32 D_80100AF4;
extern u8 D_801E6700;
extern u8 D_801E6701;
extern u8 D_801E6702;
extern u8 D_801EAA44;
extern u8 D_801EAA45;
extern u8 D_801EAA46;
extern s16 D_801EAB24;
extern u8 D_801FA9A8;
extern u8 D_801FA9A9;
extern u8 D_801FA9AA;
void func_801335A8(s32, u8);

u32 func_80139CA0(u8 *);
extern s32 D_802902D8;
extern s16 D_801E753C;
void func_80155A44(s32 *);
void func_8011F9F4();
void func_8011FF40(s32);
extern s32 D_8028FB7C;
extern u8 D_8028F914[];
extern f32 D_8029F9AC;
void func_80167604(s32);
extern s32 D_801ED3C4;
extern s32 D_8029F468;
extern s32 D_8029F9A4;
extern s16 D_801E753E;
extern s8 D_801EC7A7;
extern u8 D_80092030[];
extern u8 D_800B7830[];
void func_8012A738(u8, u8, u8);
void func_80122F9C(void);
void func_8012C2B0(u8 *, s32, s32);
void func_8010FB30(void);
void func_8010FB80(s32);

extern s32 D_802004E0;
extern s32 D_801F7D80;
extern s32 D_8028F908;
extern f32 D_8028FA00;
extern f32 D_8028FA04;
extern f32 D_8028FA08;
extern Vec3F D_8028FAFC;
extern u8 *D_802903AC;
extern f32 D_80299A40;
extern u8 D_802999E8[];
extern f32 D_80290360;
extern f32 D_80290314;
extern f32 D_80290330;
extern f32 D_80290334;
extern f32 D_80290338;
extern s32 D_80290300;
extern u8 D_8029030C[];
extern f32 D_801E677C;
extern f32 D_801E6780;
extern const f32 D_80100D88;
extern const f32 D_80100D8C;
extern const f32 D_80100D90;
extern const f32 D_80100D94;
extern const f32 D_80100D98;
extern const f32 D_80100D9C;
extern const f32 D_80100DA0;
extern const f32 D_80100DA4;
extern const f32 D_80100DA8;
extern const f32 D_80100DAC;
extern const f32 D_80100DB0;
extern const f32 D_80100DB4;
extern const f32 D_80100DB8;
extern const f32 D_80100DBC;
void *func_8017DBA0(s32);
void *func_801A9054();
void func_80197794(u8 *, s32, s32);
void func_80149398(void *, void *, f32, void *, f32);
f32 func_80148EBC(void *, s32);
void func_80133998(void *, s32, s32, s32, f32);

/* sound_options_finish_exit: while the menu transition (D_801E64C8) runs, keep
 * updating the sound options menu and sliding its models out; once it is done,
 * free the menu models, the music/effects volume bar segments (D_801F6E38 /
 * D_801F7578) and the note/horn sprites (D_801F6DC0 / D_801F7CB8).
 * Returns 1 when the menu has been released. */
s32 func_80117020(void) {
    s32 segment;
    u8 *effectsSegment;
    u8 *musicSegment;

    if (D_801E64C8 == 0) {
        func_801170DC(); /* sound options update/draw */
        func_8010F23C(4); /* slide menu models out */
        func_8010E558();
        return 0;
    }
    func_8010F94C(); /* release menu models */
    segment = 0;
    effectsSegment = D_801F7578;
    musicSegment = D_801F6E38;
    do {
        func_8011FF08(musicSegment);
        func_8011FF08(effectsSegment);
        effectsSegment += SOUND_OPTIONS_SPRITE_SIZE;
        musicSegment += SOUND_OPTIONS_SPRITE_SIZE;
        segment++;
    } while (segment < SOUND_OPTIONS_SEGMENT_COUNT);
    func_8011FF08(D_801F6DC0);
    func_8011FF08(D_801F7CB8);
    return 1;
}

static inline u32 func_801170DC_alpha(f32 value, f32 limit) {
    u32 result;
    if (!(limit <= value)) {
        result = (s32)value;
    } else {
        result = (s32)(value - limit);
        result |= 0x80000000;
    }
    return result;
}

extern const f32 D_801008A8;
extern const f32 D_801008AC;
extern const f32 D_801008B0;
extern const f32 D_801008B4;
extern const f64 D_801008B8;
extern const f32 D_801008C0;
extern s32 D_801E65C0;
extern s32 D_801E65C4;
extern s32 D_801F6138;
extern s32 D_801F6E44;
extern u8 D_801F6E5B[];
extern s32 D_801F7584;
extern u8 D_801F759B[];

/* Update and draw the Sound Options menu: wobble the four wave models, adjust
 * music/SFX volumes (D_801E65C4 / D_801E65C0, 0..160) from stick input with
 * test SFX feedback, update the 16-segment volume bars and pulsing icon/text
 * alphas, advance menu navigation via func_801100B8, decay rotation impulses
 * (D_801E6614..20), and return 1 when leaving the menu. */
s32 func_801170DC(u32 *menuCommand, void *menuContext) {
#define FIELD_AT(t,p,o) (*(t *)((u8 *)(p)+(o)))
#define FLOAT_TO_U8_ALPHA(v, lim) ({ u32 r_; if (!((lim) <= (v))) { r_ = (s32)(v); } else { r_ = (s32)((v) - (lim)); r_ |= highBit; } r_; })
    extern const f32 D_80100864;
    extern const s32 D_80100868;
    extern const f32 D_8010086C;
    extern const f64 D_80100870;
    extern const f64 D_80100878;
    extern const f64 D_80100880;
    extern const f64 D_80100888;
    extern const f64 D_80100890;
    extern const f64 D_80100898;
    extern const f32 D_801008A0;
    extern const f32 D_801008A4;
    extern const f32 D_801008CC;
    extern const f32 D_801008D0;
    extern const f32 D_801008D4;
    extern const f32 D_801008D8;
    extern const f32 D_801008DC;
    extern const f32 D_801008E0;
    extern const f32 D_801008E4;
    extern const f32 D_801008E8;
    extern const f32 D_801008EC;
    extern const f32 D_801008F0;
    extern const f32 D_801008F4;
    extern const s32 D_801008F8;
    extern const f32 D_80100904;
    extern const f32 D_80100908;
    extern const f32 D_8010090C;
    extern const f32 D_80100910;
    extern const f32 D_80100914;
    extern const f32 D_80100918;
    extern const f32 D_8010091C;
    extern const f32 D_80100920;
    extern const f32 D_80100924;
    extern const f32 D_80100928;
    extern const f32 D_8010092C;
    extern const s32 D_80100930;
    extern const f32 D_8010093C;
    extern const f32 D_80100940;
    extern const f32 D_80100944;
    extern const f32 D_80100948;
    extern const f32 D_8010094C;
    extern const f32 D_80100950;
    extern const f32 D_80100954;
    extern const f32 D_80100958;
    extern const f32 D_8010095C;
    extern const f32 D_80100964;
    extern const f32 D_80100968;
    extern const f32 D_8010096C;
    extern const f32 D_80100970;
    extern const f32 D_80100974;
    extern const f32 D_80100978;
    extern const f64 D_80100980;
    extern const f32 D_80100988;
    extern const f32 D_8010098C;
    extern const f32 D_80100990;
    extern const f32 D_80100994;
    extern const f32 D_80100998;
    extern const f32 D_8010099C;
    extern const f32 D_801009A0;
    extern const f32 D_801009A4;
    extern const f32 D_801009A8;
    extern const f32 D_801009B0;
    extern const f32 D_801009B4;
    extern const f32 D_801009B8;
    extern const f32 D_801009BC;
    extern const f32 D_801009C0;
    extern const f32 D_801009C4;
    extern const f32 D_801009CC;
    extern const f32 D_801009D0;
    extern const f32 D_801009D4;
    extern const f32 D_801009D8;
    extern const s32 D_801009DC;
    extern const s32 D_801009E0;
    extern const f32 D_801009EC;
    extern f32 D_801E58A0;
    extern s32 D_801E64C0;
    extern s32 D_801E6608;
    extern s32 D_801E6614;
    extern s32 D_801E6618;
    extern s32 D_801E661C;
    extern s32 D_801E6620;
    extern s32 D_801E66B4;
    extern s16 D_801E7586;
    extern s32 D_801EAD38;
    extern s32 D_801EAE70[];
    extern s32 D_801EC860;
    extern f32 D_801F60A0;
    extern f32 D_801F60A4;
    extern s32 D_801F60A8;
    extern f32 D_801F6DCC;
    extern s8 D_801F6DE3;
    extern f32 D_801F7CC4;
    extern s8 D_801F7CDB;
    extern u8 *D_80269F40[];
    extern u8 *D_80269F44;
    extern void *D_80269F48;
    extern void *D_80269F4C;
    extern void *D_80269F50;
    void func_8010E400(void);
    void func_8010F1AC(s32);
    void func_8010F520(s32);
    s32 func_801100B8();
    void func_8012519C();
    void func_8012643C(void);
    void func_80145680(s32);
    void func_801469E4(s32, s32, s32, s32, s32, s32, f32, f32, s32, s32, s32);
    void func_801C08E4(s32, s32, s32, s32, s32);
    f32 func_801C6000(f32);
    f32 sfxPulseSlide;
    f32 sfxFadeSlide;
    f32 musicPulseSlide;
    f32 musicFadeSlide;
    f32 modePulseSlide;
    f32 modeFadeSlide;
    f32 backPulseSlide;
    f32 backFadeSlide;
    f32 titleFadeSlide;
    f32 zero;
    s32 *fadeModePtr;
    f32 *slideBase;
    f32 phase;
    f32 wave;
    f32 sfxFade;
    f32 musicFade;
    f32 barAlpha;
    f32 conversionLimit;
    f32 fadeStart;
    f32 fadeMax;
    f32 fadeEnd;
    f32 sfxBarSlide;
    f32 sfxBarAlpha;
    f32 musicDimSlide;
    f32 musicDimAlpha;
    f32 sfxDimSlide;
    f32 sfxDimAlpha;
    f32 sfxPulse;
    f32 musicPulse;
    f32 modePulse;
    f32 backPulse;
    f32 sfxIntensity;
    f32 unusedUnsignedAlpha;
    f32 musicIntensity;
    f32 unusedUnsignedAlpha2;
    f32 sfxMaxAlpha;
    f32 sfxScaledAlpha;
    f32 musicMaxAlpha;
    f32 musicScaledAlpha;
    f64 wobbleAmplitude;
    f64 wobbleFreqSlow;
    f64 wobbleBaseYaw;
    f64 wobbleFreqFast;
    s16 drawX;
    s16 drawY;
    s32 controllerOffset;
    s32 selectedOption;
    s32 spriteOffset;
    s32 segmentIndex;
    s32 unusedX;
    s32 modelIndex;
    u32 musicBarAlpha;
    u32 sfxBarAlphaByte;
    u32 musicBarDimAlpha;
    u32 sfxBarDimAlpha;
    s32 sfxIconAlpha;
    s32 musicIconAlpha;
    u32 command;
    void **unusedModels;
    void *model;
    void *waveModel0Y;
    void *waveModel0Z;
    void *waveModel1Y;
    void *waveModel1Z;
    void *waveModel2Y;
    void *waveModel2Z;
    void *waveModel3Y;
    void *waveModel3Z;

    func_80145680(1);
    func_801469E4(0x104, (s16)((D_801F60A0 / D_80100864) + D_8010086C), MENU_OBJECT_OPAQUE, MENU_OBJECT_OPAQUE, MENU_OBJECT_OPAQUE, MENU_OBJECT_OPAQUE, (*(const f32 *)&D_80100868), (*(const f32 *)&D_80100868), 1, FIELD_AT(s32,&D_801EAE70,(D_801E7586 * 4)), 1);
    func_80145680(0);
    if (D_801E6608 == 0) {
        phase = D_801E58A0 * (wobbleFreqFast = D_80100870);
        FIELD_AT(f32,D_80269F40[0],MENU_OBJECT_ROTATION_X_OFFSET) = *(f32 *)&D_801E6618;
        wobbleAmplitude = D_80100878;
        waveModel0Y = FIELD_AT(u8 *, &D_80269F44, -4);
        wave = func_801C6000(phase);
        phase = D_801E58A0 * (wobbleFreqSlow = D_80100880);
        wobbleBaseYaw = D_80100888;
        FIELD_AT(f32,waveModel0Y,MENU_OBJECT_ROTATION_Y_OFFSET) = wave * wobbleAmplitude + wobbleBaseYaw;
        waveModel0Z = D_80269F40[0];
        wave = func_801C6000(phase);
        phase = D_801E58A0 * D_80100890;
        FIELD_AT(f32,waveModel0Z,MENU_OBJECT_ROTATION_Z_OFFSET) = wave * wobbleAmplitude;
        FIELD_AT(f32,D_80269F44,MENU_OBJECT_ROTATION_X_OFFSET) = (*(f32 *)&D_801E6614);
        waveModel1Y = FIELD_AT(u8 *, &D_80269F48, -4);
        wave = func_801C6000(phase);
        phase = D_801E58A0 * wobbleFreqSlow;
        FIELD_AT(f32,waveModel1Y,MENU_OBJECT_ROTATION_Y_OFFSET) = wave * wobbleAmplitude + wobbleBaseYaw;
        waveModel1Z = FIELD_AT(u8 *, &D_80269F44, 0);
        wave = func_801C6000(phase);
        phase = D_801E58A0 * wobbleFreqSlow;
        FIELD_AT(f32,waveModel1Z,MENU_OBJECT_ROTATION_Z_OFFSET) = wave * wobbleAmplitude;
        FIELD_AT(f32,D_80269F48,MENU_OBJECT_ROTATION_X_OFFSET) = *(f32 *)&D_801E6620;
        waveModel2Y = FIELD_AT(u8 *, &D_80269F4C, -4);
        wave = func_801C6000(phase);
        phase = D_801E58A0 * wobbleFreqFast;
        FIELD_AT(f32,waveModel2Y,MENU_OBJECT_ROTATION_Y_OFFSET) = wave * wobbleAmplitude + wobbleBaseYaw;
        waveModel2Z = FIELD_AT(u8 *, &D_80269F48, 0);
        wave = func_801C6000(phase);
        phase = D_801E58A0 * D_80100898;
        FIELD_AT(f32,waveModel2Z,MENU_OBJECT_ROTATION_Z_OFFSET) = wave * wobbleAmplitude;
        FIELD_AT(f32,D_80269F4C,MENU_OBJECT_ROTATION_X_OFFSET) = *(f32 *)&D_801E661C;
        waveModel3Y = FIELD_AT(u8 *, &D_80269F50, -4);
        wave = func_801C6000(phase);
        phase = D_801E58A0 * wobbleFreqFast;
        FIELD_AT(f32,waveModel3Y,MENU_OBJECT_ROTATION_Y_OFFSET) = wave * wobbleAmplitude + wobbleBaseYaw;
        waveModel3Z = FIELD_AT(u8 *, &D_80269F4C, 0);
        FIELD_AT(f32,waveModel3Z,MENU_OBJECT_ROTATION_Z_OFFSET) = func_801C6000(phase) * wobbleAmplitude;
    }
    selectedOption = FIELD_AT(s32,menuContext,SOUND_OPTIONS_CONTEXT_SELECTION_OFFSET);
    switch (selectedOption) {
        case SOUND_OPTIONS_OPTION_MUSIC:
        D_801E65C4 += (s16)(FIELD_AT(s16,&D_801FAA90,(D_80202218 * SOUND_OPTIONS_CONTROLLER_STRIDE)) / SOUND_OPTIONS_STICK_DIVISOR);
        break;
        case SOUND_OPTIONS_OPTION_SFX:
        controllerOffset = D_80202218 * SOUND_OPTIONS_CONTROLLER_STRIDE;
        { s32 volumeDelta = (s16)(FIELD_AT(s16,&D_801FAA90,controllerOffset) / SOUND_OPTIONS_STICK_DIVISOR);
            s16 *stickPtr = (s16 *)((s32)&D_801FAA90 + controllerOffset);
            s32 stickX = *stickPtr;
            D_801E65C0 += volumeDelta;
            if (stickX != 0) {
                if (D_801E66B4 == 0) {
                    func_801C08E4(SOUND_OPTIONS_SFX_TEST_ID, 0x64, 0x80, 0, -1);
                    D_801E66B4 = SOUND_OPTIONS_SFX_REPEAT_DELAY;
                } else {
                    D_801E66B4--;
                }
            }
        }
        break;
    }
    slideBase = (f32 *)&D_801F60A8;
    { f32 noteSlide = 2.0f * slideBase[0];
        f32 hornSlide = D_801F60A4;
    f32 hornX = D_801008A0 - hornSlide;
        D_801F7CC4 = hornX;
        D_801F6DCC = noteSlide + D_801008A4; }
    if (D_801E65C0 < 0) {
        D_801E65C0 = 0;
    }
    if (D_801E65C0 >= SOUND_OPTIONS_VOLUME_MAX + 1) {
        D_801E65C0 = SOUND_OPTIONS_VOLUME_MAX;
    }
    if (D_801E65C4 < 0) {
        s32 *musicVolPtr = &D_801E65C4;
        *musicVolPtr = 0;
    }
    if (D_801E65C4 > SOUND_OPTIONS_VOLUME_MAX) {
        D_801E65C4 = SOUND_OPTIONS_VOLUME_MAX;
    }
    segmentIndex = 0;
    fadeModePtr = &D_801F6138;
    {
    f32 *loopSlideBase;
    f32 *sfxSlidePtr;
    f32 *fadeSlidePtr;
    u32 highBit;
    f64 volumeStep;
    fadeStart = D_801008A8;
    fadeMax = D_801008AC;
    fadeEnd = D_801008B0;
    conversionLimit = D_801008B4;
    highBit = 0x80000000;
    loopSlideBase = slideBase;
    sfxSlidePtr = loopSlideBase - 1;
    volumeStep = D_801008B8;
    fadeSlidePtr = loopSlideBase - 2;
    zero = 0.0f;
    do {
        spriteOffset = segmentIndex * SOUND_OPTIONS_SPRITE_SIZE;
        barAlpha = SOUND_OPTIONS_BAR_BASE_X + segmentIndex * SOUND_OPTIONS_SEGMENT_SPACING;
        barAlpha += loopSlideBase[0];
        FIELD_AT(f32,&D_801F6E44,spriteOffset) = barAlpha;
        do {
        if ((*fadeModePtr < 2) && !(fadeMax < (((fadeStart - loopSlideBase[-2]) * fadeMax) / fadeEnd))) {
            barAlpha = ((fadeEnd - loopSlideBase[-2]) * fadeMax) / fadeEnd;
            musicBarAlpha = 0;
            if (!(barAlpha < zero)) {
                musicBarAlpha = FLOAT_TO_U8_ALPHA(barAlpha, conversionLimit);
            }
        }
        else { musicBarAlpha = MENU_OBJECT_OPAQUE; }
        } while (0);
        do { s32 alphaOffset = spriteOffset;
        *(volatile u8 *)((s32)&D_801F6E5B + spriteOffset) = musicBarAlpha;
        FIELD_AT(f32,&D_801F7584,spriteOffset) = (SOUND_OPTIONS_BAR_BASE_X + segmentIndex * SOUND_OPTIONS_SEGMENT_SPACING) - (2.0f * sfxSlidePtr[0]);
        if ((*fadeModePtr < 2) && (sfxBarSlide = sfxSlidePtr[-1], !(fadeMax < (((fadeStart - sfxBarSlide) * fadeMax) / fadeEnd)))) {
            sfxBarAlpha = ((fadeEnd - sfxBarSlide) * fadeMax) / fadeEnd;
            sfxBarAlphaByte = 0;
            if (!(sfxBarAlpha < zero)) {
                sfxBarAlphaByte = FLOAT_TO_U8_ALPHA(sfxBarAlpha, conversionLimit);
            }
        } else {
            sfxBarAlphaByte = MENU_OBJECT_OPAQUE;
        }
        *(volatile u8 *)((s32)&D_801F759B + alphaOffset) = sfxBarAlphaByte;
        } while (0);
        if (((f32)(D_801E65C4 - SOUND_OPTIONS_VOLUME_HALF_STEP) / volumeStep) < segmentIndex) {
        do { s32 alphaOffset = spriteOffset;
            if ((*fadeModePtr < 2) && (musicDimSlide = *fadeSlidePtr, !(fadeMax < (((fadeStart - musicDimSlide) * fadeMax) / fadeEnd)))) {
                phase = ((fadeEnd - musicDimSlide) * fadeMax) / fadeEnd;
                musicBarDimAlpha = 0;
                if (!(phase < zero)) {
                    musicDimAlpha = phase / D_801008C0;
                    musicBarDimAlpha = FLOAT_TO_U8_ALPHA(musicDimAlpha, conversionLimit);
                }
            } else {
                musicBarDimAlpha = SOUND_OPTIONS_BAR_DIM_ALPHA;
            }
            *(volatile u8 *)((s32)&D_801F6E5B + alphaOffset) = musicBarDimAlpha;
        } while (0);
        }
        if (((f32)(D_801E65C0 - SOUND_OPTIONS_VOLUME_HALF_STEP) / volumeStep) < segmentIndex) {
        do { s32 alphaOffset = spriteOffset;
            if ((*fadeModePtr < 2) && (sfxDimSlide = *fadeSlidePtr, !(fadeMax < (((fadeStart - sfxDimSlide) * fadeMax) / fadeEnd)))) {
                wave = ((fadeEnd - sfxDimSlide) * fadeMax) / fadeEnd;
                sfxBarDimAlpha = 0;
                if (!(wave < zero)) {
                    sfxDimAlpha = wave / D_801008C0;
                    sfxBarDimAlpha = FLOAT_TO_U8_ALPHA(sfxDimAlpha, conversionLimit);
                }
            } else {
                sfxBarDimAlpha = SOUND_OPTIONS_BAR_DIM_ALPHA;
            }
            *(volatile u8 *)((s32)&D_801F759B + alphaOffset) = sfxBarDimAlpha;
        } while (0);
        }
        { f64 zeroKeep = zero; zero = zeroKeep; }
        segmentIndex += 1;
    } while (segmentIndex < SOUND_OPTIONS_SEGMENT_COUNT);
    }
    modelIndex = 0;
    func_8012643C();
    for (; modelIndex < D_801EC860; modelIndex++) {
        model = D_80269F40[modelIndex];
        func_8015C350(model + MENU_OBJECT_QUATERNION_OFFSET, model + MENU_OBJECT_ROTATION_X_OFFSET);
    }
    if (FIELD_AT(s32,menuContext,SOUND_OPTIONS_CONTEXT_SELECTION_OFFSET) == SOUND_OPTIONS_OPTION_SFX) {
        sfxPulse = (func_801C6000(D_801E58A0 * FIELD_AT(const f64,&D_801008C0,4)) * D_801008CC) + D_801008D0 + D_801008D4;
        if (D_801F6138 < 2) {
                sfxPulseSlide = D_801F60A0;
            sfxMaxAlpha = D_801008DC;
            if (sfxMaxAlpha < (((D_801008D8 - sfxPulseSlide) * sfxMaxAlpha) / D_801008E0)) {
                sfxIntensity = sfxPulse * sfxMaxAlpha;
pulse_done:
                sfxScaledAlpha = sfxIntensity / sfxMaxAlpha;
                sfxIconAlpha = func_801170DC_alpha(sfxScaledAlpha, D_801008E4);
                goto alpha_store;
            } else {
                sfxFade = ((D_801008E0 - sfxPulseSlide) * sfxMaxAlpha) / D_801008E0;
                sfxIntensity = (sfxFade < 0.0f ? 0.0f : sfxFade) * sfxPulse;
                goto pulse_done;
            }
        } else {
            sfxMaxAlpha = D_801008E8;
            sfxIntensity = sfxPulse * sfxMaxAlpha;
            goto pulse_done;
        }
    }
    sfxIconAlpha = D_801F6138 >= 2 ? MENU_OBJECT_OPAQUE :
        (sfxFadeSlide = D_801F60A0, D_801008F0 < (((D_801008EC - sfxFadeSlide) * D_801008F0) / D_801008F4) ? MENU_OBJECT_OPAQUE :
        (((D_801008F4 - sfxFadeSlide) * D_801008F0) / D_801008F4) < 0.0f ? 0 : func_801170DC_alpha((((D_801008F4 - sfxFadeSlide) * D_801008F0) / D_801008F4), (*(const f32 *)&D_801008F8)));
alpha_store:
    D_801F7CDB = sfxIconAlpha;
    if (FIELD_AT(s32,menuContext,SOUND_OPTIONS_CONTEXT_SELECTION_OFFSET) == SOUND_OPTIONS_OPTION_MUSIC) {
        musicPulse = (func_801C6000(D_801E58A0 * FIELD_AT(const f64,&D_801008F8,4)) * D_80100904) + D_80100908 + D_8010090C;
        if (D_801F6138 < 2) {
                musicPulseSlide = D_801F60A0;
            musicMaxAlpha = D_80100914;
            if (musicMaxAlpha < (((D_80100910 - musicPulseSlide) * musicMaxAlpha) / D_80100918)) {
                musicIntensity = musicPulse * musicMaxAlpha;
pulse2_done:
                musicScaledAlpha = musicIntensity / musicMaxAlpha;
                musicIconAlpha = func_801170DC_alpha(musicScaledAlpha, D_8010091C);
                goto alpha2_store;
            } else {
                musicFade = ((D_80100918 - musicPulseSlide) * musicMaxAlpha) / D_80100918;
                musicIntensity = (musicFade < 0.0f ? 0.0f : musicFade) * musicPulse;
                goto pulse2_done;
            }
        } else {
            musicMaxAlpha = D_80100920;
            musicIntensity = musicPulse * musicMaxAlpha;
            goto pulse2_done;
        }
    }
    musicIconAlpha = D_801F6138 >= 2 ? MENU_OBJECT_OPAQUE :
        (musicFadeSlide = D_801F60A0, D_80100928 < (((D_80100924 - musicFadeSlide) * D_80100928) / D_8010092C) ? MENU_OBJECT_OPAQUE :
        (((D_8010092C - musicFadeSlide) * D_80100928) / D_8010092C) < 0.0f ? 0 : func_801170DC_alpha((((D_8010092C - musicFadeSlide) * D_80100928) / D_8010092C), (*(const f32 *)&D_80100930)));
alpha2_store:
    D_801F6DE3 = musicIconAlpha;
    if (FIELD_AT(s32,menuContext,SOUND_OPTIONS_CONTEXT_SELECTION_OFFSET) == SOUND_OPTIONS_OPTION_MODE) {
        modePulse = (func_801C6000(D_801E58A0 * FIELD_AT(const f64,&D_80100930,4)) * D_8010093C) + D_80100940 + D_80100944;
        { f32 scaledAlpha, maxAlpha, product; s32 labelAlpha;
            if (D_801F6138 < 2) {
                modePulseSlide = D_801F60A0;
                maxAlpha = D_8010094C;
                if (maxAlpha < ((D_80100948 - modePulseSlide) * maxAlpha) / D_80100950) {
                    product = modePulse * maxAlpha;
pulse3_convert:
                    scaledAlpha = product / maxAlpha;
                    labelAlpha = (u8)func_801170DC_alpha(scaledAlpha, D_80100954);
                    goto pulse3_draw;
                } else {
                    f32 fadeAlpha = ((D_80100950 - modePulseSlide) * maxAlpha) / D_80100950;
                    product = (fadeAlpha < 0.0f ? 0.0f : fadeAlpha) * modePulse;
                    goto pulse3_convert;
                }
            } else {
                maxAlpha = D_80100958;
                scaledAlpha = (modePulse * maxAlpha) / maxAlpha;
                labelAlpha = (u8)func_801170DC_alpha(scaledAlpha, D_8010095C);
            }
pulse3_draw:
            drawX = D_801F60A0 + D_80100964;
            func_801469E4(drawX, 0xA1,MENU_OBJECT_OPAQUE,MENU_OBJECT_OPAQUE,MENU_OBJECT_OPAQUE,labelAlpha,FIELD_AT(const f32,&D_8010095C,4),FIELD_AT(const f32,&D_8010095C,4),1,FIELD_AT(s32,&D_801EAD38,0xB4 + D_801E7586 * 4),1);
        }
    } else {
        f32 *slideTimePtr = &D_801F60A0;
        drawX = *slideTimePtr + D_80100968;
        func_801469E4(drawX, 0xA1,MENU_OBJECT_OPAQUE,MENU_OBJECT_OPAQUE,MENU_OBJECT_OPAQUE,D_801F6138 >= 2 ? MENU_OBJECT_OPAQUE : ((modeFadeSlide = *(volatile f32 *)slideTimePtr, D_80100970 < ((D_8010096C - modeFadeSlide) * D_80100970) / D_80100974) ? MENU_OBJECT_OPAQUE : ((((D_80100974 - modeFadeSlide) * D_80100970) / D_80100974) < 0.0f ? 0 : (u8)({ f32 v = (((D_80100974 - modeFadeSlide) * D_80100970) / D_80100974); u32 r; if (!(D_80100978 <= v)) { r = (s32)v; } else { r = (s32)(v - D_80100978); r |= 0x80000000; } r; }))),FIELD_AT(const f32,&D_80100978,4),FIELD_AT(const f32,&D_80100978,4),1,FIELD_AT(s32,&D_801EAD38,0xB4 + D_801E7586 * 4),1);
    }
    if (FIELD_AT(s32,menuContext,SOUND_OPTIONS_CONTEXT_SELECTION_OFFSET) == SOUND_OPTIONS_OPTION_BACK) {
        backPulse = (func_801C6000(D_801E58A0 * D_80100980) * D_80100988) + D_8010098C + D_80100990;
        { f32 scaledAlpha, maxAlpha, product; s32 labelAlpha;
            if (D_801F6138 < 2) {
                backPulseSlide = D_801F60A0;
                maxAlpha = D_80100998;
                if (maxAlpha < ((D_80100994 - backPulseSlide) * maxAlpha) / D_8010099C) {
                    product = backPulse * maxAlpha;
pulse4_convert:
                    scaledAlpha = product / maxAlpha;
                    labelAlpha = (u8)func_801170DC_alpha(scaledAlpha, D_801009A0);
                    goto pulse4_draw;
                } else {
                    f32 fadeAlpha = ((D_8010099C - backPulseSlide) * maxAlpha) / D_8010099C;
                    product = (fadeAlpha < 0.0f ? 0.0f : fadeAlpha) * backPulse;
                    goto pulse4_convert;
                }
            } else {
                maxAlpha = D_801009A4;
                scaledAlpha = (backPulse * maxAlpha) / maxAlpha;
                labelAlpha = (u8)func_801170DC_alpha(scaledAlpha, D_801009A8);
            }
pulse4_draw:
            drawY = D_801F60A4 + D_801009B0;
            func_801469E4(0xAF, drawY,MENU_OBJECT_OPAQUE,MENU_OBJECT_OPAQUE,MENU_OBJECT_OPAQUE,labelAlpha,FIELD_AT(const f32,&D_801009A8,4),FIELD_AT(const f32,&D_801009A8,4),1,FIELD_AT(s32,&D_801EAD38,0x54 + D_801E7586 * 4),1);
        }
    } else {
        drawY = D_801F60A4 + D_801009B4;
        func_801469E4(0xAF, drawY,MENU_OBJECT_OPAQUE,MENU_OBJECT_OPAQUE,MENU_OBJECT_OPAQUE,D_801F6138 >= 2 ? MENU_OBJECT_OPAQUE : ((backFadeSlide = D_801F60A0, D_801009BC < ((D_801009B8 - backFadeSlide) * D_801009BC) / D_801009C0) ? MENU_OBJECT_OPAQUE : ((((D_801009C0 - backFadeSlide) * D_801009BC) / D_801009C0) < 0.0f ? 0 : (u8)({ f32 v = (((D_801009C0 - backFadeSlide) * D_801009BC) / D_801009C0); u32 r; if (!(D_801009C4 <= v)) { r = (s32)v; } else { r = (s32)(v - D_801009C4); r |= 0x80000000; } r; }))),FIELD_AT(const f32,&D_801009C4,4),FIELD_AT(const f32,&D_801009C4,4),1,FIELD_AT(s32,&D_801EAD38,0x54 + D_801E7586 * 4),1);
    }
    {
        func_801469E4(0xA0,0x1E,MENU_OBJECT_OPAQUE,MENU_OBJECT_OPAQUE,MENU_OBJECT_OPAQUE,D_801F6138 >= 2 ? MENU_OBJECT_OPAQUE : ((titleFadeSlide = D_801F60A0, D_801009D0 < ((D_801009CC - titleFadeSlide) * D_801009D0) / D_801009D4) ? MENU_OBJECT_OPAQUE : ((((D_801009D4 - titleFadeSlide) * D_801009D0) / D_801009D4) < 0.0f ? 0 : (u8)({ f32 v = (((D_801009D4 - titleFadeSlide) * D_801009D0) / D_801009D4); u32 r; if (!(D_801009D8 <= v)) { r = (s32)v; } else { r = (s32)(v - D_801009D8); r |= 0x80000000; } r; }))),(*(const f32 *)&D_801009DC),(*(const f32 *)&D_801009DC),1,FIELD_AT(s32,&D_801EAD38,D_801E7586 * 4),1);
    }
    func_8012519C();
    func_801100B8(menuCommand, menuContext);
    if (*menuCommand < 2) {
        ((f32 *)&D_801E6614)[FIELD_AT(s32,menuContext,SOUND_OPTIONS_CONTEXT_SELECTION_OFFSET)] = (*(const f32 *)&D_801009E0);
    }
    {
        f64 decay = FIELD_AT(const f64,&D_801009E0,4);
        f32 rot0 = (*(f32 *)&D_801E6614) * decay;
        f32 rot1 = FIELD_AT(f32,(s32)&D_801E6614,4) * decay;
        f32 rot2 = FIELD_AT(f32,(s32)&D_801E6614,8) * decay;
        f32 rot3 = FIELD_AT(f32,(s32)&D_801E6614,12) * decay;
        (*(f32 *)&D_801E6614) = rot0;
        FIELD_AT(f32,(s32)&D_801E6614,4) = rot1;
        FIELD_AT(f32,(s32)&D_801E6614,8) = rot2;
        FIELD_AT(f32,(s32)&D_801E6614,12) = rot3;
    }
    command = *menuCommand;
    if ((command - 4) < 2) {
      if (FIELD_AT(s32,menuContext,SOUND_OPTIONS_CONTEXT_SELECTION_OFFSET) < 2) {
          if (command != 5) goto leave_menu;
      }
        if ((D_801E64C0 != 1) || (D_801E64C8 != 0)) {
            func_8010E400();
            func_8010F1AC(SOUND_OPTIONS_ITEM_COUNT);
            *(s32 *)(FIELD_AT(s32,D_80269F50,SOUND_OPTIONS_GLOVE_ANIM_OFFSET) + 8) = 0;
            func_80133998(((void **)&D_80269F4C)[1], 1, 0, 0, D_801009EC);
            return 1;
        }
    } else {
leave_menu:
        func_8010F520(SOUND_OPTIONS_ITEM_COUNT);
    }
    return 0;
}

extern s32 D_801E6608;

/* Menu callback: clears the menu transition flags (D_801E6608) and reports the menu as handled. */
s32 func_80118580(void) {
    D_801E6608 = 0;
    return 1;
}

/* Initialize the sound-options volume bars, animated models and icons, then update the menu. */
s32 func_80118590(s32 menuStateAddress, s32 menuContextAddress) {
    extern s32 D_801E6614; /* Option 0 X rotation (float bits). */
    extern s32 D_801E6618; /* Option 1 X rotation (float bits). */
    extern s32 D_801E661C; /* Option 2 X rotation (float bits). */
    extern s32 D_801E6620; /* Option 3 X rotation (float bits). */
    extern s32 D_801E65C4; /* Music volume, 0..160. */
    extern s32 D_801E65C0; /* Sound-effect volume, 0..160. */
    extern s32 D_801E650C;
    extern s32 D_801E6510;
    extern s32 D_801E6514;
    extern s32 D_801E6518;
    extern u8 D_801009F0[]; /* "sliderbit.bmp" */
    extern u8 D_80100A00[]; /* "newwave.ndo" */
    extern u8 D_80100A0C[]; /* "newglove.ndo" */
    extern u8 D_80100A1C[]; /* "horn0001.bmp" */
    extern u8 D_80100A2C[]; /* "note0001.bmp" */
    extern const f64 D_80100A3C; /* 10.0: volume units per segment. */
    extern const f32 D_80100A44; /* -25.0: wave model X. */
    extern const f32 D_80100A48; /* 500.0: wave model Z. */
    extern const f32 D_80100A4C; /* 0.1: wave model X rotation. */
    extern const f32 D_80100A50; /* 1.2: initial first wave X scale. */
    extern const f32 D_80100A54; /* 0.7: volume wave Y scale. */
    extern const f32 D_80100A58; /* 1.0: unit scale / animation speed. */
    extern const f32 D_80100A5C; /* 1.3: wave X scale override. */
    extern const f32 D_80100A60; /* 1.1: second wave animation speed. */
    extern const f32 D_80100A64; /* 0.9: lower wave scale / animation speed. */
    extern const f32 D_80100A68; /* 3.5: glove Y rotation. */
    extern u8 D_801F6E50[]; /* Music segments: scaleX. */
    extern u8 D_801F6E54[]; /* Music segments: scaleY. */
    extern u8 D_801F6E58[]; /* Music segments: red. */
    extern u8 D_801F6E59[]; /* Music segments: green. */
    extern u8 D_801F6E5A[]; /* Music segments: blue. */
    extern u8 D_801F6E5B[]; /* Music segments: alpha. */
    extern u8 D_801F7590[]; /* SFX segments: scaleX. */
    extern u8 D_801F7594[]; /* SFX segments: scaleY. */
    extern u8 D_801F7598[]; /* SFX segments: red. */
    extern u8 D_801F7599[]; /* SFX segments: green. */
    extern u8 D_801F759A[]; /* SFX segments: blue. */
    extern u8 D_801F759B[]; /* SFX segments: alpha. */
    extern u8 *D_80269F40[]; /* Menu model pointers. */
    extern u8 D_801F1D34[]; /* Horn and note animation descriptors, 16 bytes each. */
    extern u8 *D_801F7D28; /* Horn sprite animation descriptor. */
    extern s32 D_801F7D24; /* Horn sprite animation state. */
    extern u8 *D_801F6E30; /* Note sprite animation descriptor. */
    extern s32 D_801F6E2C; /* Note sprite animation state. */
    void func_8010E560(void);
    void func_80145680(s32);
    void func_8014A50C(void *, void *, s32, s32, s32, s32); /* Initialize a sprite and insert it in the render list. */
    void func_8010EEF8(void *, f32, f32, f32, f32, f32, f32, f32, f32, f32, s32); /* Create a menu model with position, rotation, scale and opacity. */
    void func_80142700(void *, s32); /* Initialize requested object components. */
    void func_80133998(void *, s32, s32, s32, f32); /* Select or queue an animation (index, loop, queue, speed). */
    void func_8010F0B8(s32); /* Capture menu transforms and initialize transition state. */
    s32 segment;
    f64 volumeSegmentThreshold;

    func_8010E560();
    D_801E6614 = 0;
    D_801E6618 = 0;
    D_801E661C = 0;
    D_801E6620 = 0;
    func_80145680(0);
    for (segment = 0; segment < SOUND_OPTIONS_SEGMENT_COUNT; segment++) {
        s32 spriteOffset = segment * SOUND_OPTIONS_SPRITE_SIZE;
        func_8014A50C(D_801F6E38 + spriteOffset, D_801009F0, SOUND_OPTIONS_FIRST_SEGMENT_X + segment * SOUND_OPTIONS_SEGMENT_SPACING, SOUND_OPTIONS_MUSIC_BAR_Y, 0, 1);
        D_801F6E5B[spriteOffset] = 0xFF;
        D_801F6E58[spriteOffset] = 0xFF;
        D_801F6E59[spriteOffset] = 0x50;
        D_801F6E5A[spriteOffset] = 0xFF;
        volumeSegmentThreshold = (f32)(D_801E65C4 - SOUND_OPTIONS_VOLUME_HALF_STEP) / D_80100A3C; *(s32 *)(D_801F6E50 + spriteOffset) = SOUND_OPTIONS_SEGMENT_SCALE_X; *(s32 *)(D_801F6E54 + spriteOffset) = SOUND_OPTIONS_SEGMENT_SCALE_Y_END - (SOUND_OPTIONS_SEGMENT_COUNT - segment) * SOUND_OPTIONS_SEGMENT_SCALE_Y_STEP; if (volumeSegmentThreshold < (f64)segment) { D_801F6E5B[spriteOffset] = SOUND_OPTIONS_DIM_ALPHA; }
        func_8014A50C(D_801F7578 + spriteOffset, D_801009F0, SOUND_OPTIONS_FIRST_SEGMENT_X + segment * SOUND_OPTIONS_SEGMENT_SPACING, SOUND_OPTIONS_SFX_BAR_Y, 0, 1);
        D_801F759B[spriteOffset] = 0xFF;
        D_801F7598[spriteOffset] = 0x50;
        D_801F7599[spriteOffset] = 0xFF;
        D_801F759A[spriteOffset] = 0x50;
        volumeSegmentThreshold = (f32)(D_801E65C0 - SOUND_OPTIONS_VOLUME_HALF_STEP) / D_80100A3C; *(s32 *)(D_801F7590 + spriteOffset) = SOUND_OPTIONS_SEGMENT_SCALE_X; *(s32 *)(D_801F7594 + spriteOffset) = SOUND_OPTIONS_SEGMENT_SCALE_Y_END - (SOUND_OPTIONS_SEGMENT_COUNT - segment) * SOUND_OPTIONS_SEGMENT_SCALE_Y_STEP; if (volumeSegmentThreshold < (f64)segment) { D_801F759B[spriteOffset] = SOUND_OPTIONS_DIM_ALPHA; }
    }
    func_8010EEF8(D_80100A00, D_80100A44, 18.0f, D_80100A48, D_80100A4C, 0.0f, 3.14f, D_80100A50, D_80100A54, D_80100A58, 0xFF);
    func_80142700(D_80269F40[0], MENU_OBJECT_ANIMATION_COMPONENT);
    func_80133998(D_80269F40[0], 0, 1, 1, D_80100A58);
    *(f32 *)(D_80269F40[0] + MENU_OBJECT_SCALE_X_OFFSET) = D_80100A5C;
    func_8010EEF8(D_80100A00, D_80100A44, 70.0f, D_80100A48, D_80100A4C, 0.0f, 3.14f, D_80100A58, D_80100A54, D_80100A58, 0xFF);
    func_80142700(D_80269F40[1], MENU_OBJECT_ANIMATION_COMPONENT);
    func_80133998(D_80269F40[1], 0, 1, 1, D_80100A60);
    *(f32 *)(D_80269F40[1] + MENU_OBJECT_SCALE_X_OFFSET) = D_80100A5C;
    func_8010EEF8(D_80100A00, D_80100A44, -125.0f, D_80100A48, D_80100A4C, 0.0f, 3.14f, D_80100A64, D_80100A64, D_80100A58, 0xFF);
    func_80142700(D_80269F40[2], MENU_OBJECT_ANIMATION_COMPONENT);
    func_80133998(D_80269F40[2], 0, 1, 1, D_80100A64);
    *(f32 *)(D_80269F40[2] + MENU_OBJECT_SCALE_X_OFFSET) = D_80100A5C;
    func_8010EEF8(D_80100A00, D_80100A44, -70.0f, D_80100A48, D_80100A4C, 0.0f, 3.14f, D_80100A64, D_80100A64, D_80100A58, 0xFF);
    func_80142700(D_80269F40[3], MENU_OBJECT_ANIMATION_COMPONENT);
    func_80133998(D_80269F40[3], 0, 1, 1, D_80100A64);
    *(f32 *)(D_80269F40[3] + MENU_OBJECT_SCALE_X_OFFSET) = D_80100A5C;
    func_8010EEF8(D_80100A0C, 360.0f, 396.0f, 550.0f, 0.0f, D_80100A68, 0.0f, D_80100A58, D_80100A58, D_80100A58, 0xFF);
    func_80142700(D_80269F40[4], MENU_OBJECT_ANIMATION_COMPONENT);
    func_80133998(D_80269F40[4], 0, 0, 0, D_80100A58);
    func_80133998(D_80269F40[4], 2, 1, 1, D_80100A58);
    func_8014A50C(D_801F7CB8, D_80100A1C, 0x10E, 0x70, 0, 1);
    D_801F7D28 = D_801F1D34;
    D_801F7D24 = 0;
    func_8014A50C(D_801F6DC0, D_80100A2C, 0x104, 0x46, 0, 1);
    D_801F6E30 = D_801F1D34 + 0x10;
    D_801F6E2C = 0;
    func_8010F0B8(SOUND_OPTIONS_ITEM_COUNT);
    D_801E650C = 3;
    D_801E6510 = 0;
    D_801E6514 = 1;
    D_801E6518 = 2;
    func_801170DC(menuStateAddress, menuContextAddress);
    return 1;
}

/* Original compiler padding. */
const u32 D_80118B68_padding[] __attribute__((section(".text"))) = {
    0x74637374, 0x6F6B005F
};

/* Initialize the name-entry grid and title-box models, then update the screen once. */
s32 func_80118B70(s32 inputCommandAddress, s32 menuContextAddress) {
    extern s32 D_801E65B0;
    extern s32 D_801E6704;
    extern s32 D_801E6724;
    extern s32 D_801F7D34;
    extern u32 D_801E6708;
    extern u8 D_801E66C0[];
    extern u8 D_80100A94[];
    extern u8 D_80100AA4[];
    extern u8 D_80100AB4[];
    extern f32 D_80100AC0;
    extern f32 D_80100AC4;
    extern f32 D_80100AC8;
    extern f32 D_80100ACC;
    extern f32 D_80100AD0;
    f32 zero;
    f32 modelY;
    f32 modelZ;
    f32 modelPitch;
    f32 modelRoll;
    f32 modelScaleX;
    u32 columnCount;

    void func_8010E560(void);
    void func_80145680(s32);
    s32 func_801D20F8(u8 *);
    void func_8010EEF8(void *, f32, f32, f32, f32, f32, f32, f32, f32, f32, s32);
    void func_8010F0B8(s32);
    void func_80155AE4(void *);
    s32 func_801198D0(s32 *, s32 *);

    D_801E65B0 = 1;
    func_8010E560();
    func_80145680(0);
    columnCount = (u32)func_801D20F8(D_801E66C0) / D_801E6708; D_801E6704 = 0; D_801E6724 = 0; modelY = D_80100AC0; modelZ = D_80100AC4; modelPitch = D_80100AC8; modelRoll = D_80100ACC; modelScaleX = D_80100AD0; zero = 0.0f; D_801F7D34 = columnCount;
    func_8010EEF8(D_80100A94, zero, modelY, modelZ, modelPitch, zero, modelRoll, modelScaleX, 3.8f, 1.0f, NAME_ENTRY_MODEL_OPAQUE);
    func_8010EEF8(D_80100AA4, zero, modelY, modelZ, modelPitch, zero, modelRoll, modelScaleX, 3.8f, 1.0f, NAME_ENTRY_MODEL_TRANSLUCENT_ALPHA);
    func_8010F0B8(NAME_ENTRY_MODEL_COUNT);
    func_8012C2B0(&D_801E6700, 0, NAME_ENTRY_BUFFER_BYTES);
    func_80155AE4(D_80100AB4);
    func_801198D0(inputCommandAddress, menuContextAddress);
    return 1;
}

/* Initialize the difficulty menu with two animated waves and Normal selected. */
s32 func_80118D54(s32 *inputCommand, s32 *menuWords) {
    extern s32 D_801E5898;
    extern s32 D_801E6614[];
    u8 **modelResourceSlot;
    extern s32 D_801E6618;
    extern s32 D_801E661C;
    extern s32 D_801E6620;
    u8 **secondModelSlot;
    extern s32 D_801E6720;
    extern s32 D_801E6510;
    extern s32 D_801E6514;
    extern s32 D_801E6518;
    extern s32 D_801E650C;
    extern u8 D_80100AD4[];
    extern f32 D_80100AE0;
    extern f32 D_80100AE4;
    extern f32 D_80100AE8;
    extern f32 D_80100AEC;
    extern f32 D_80100AF0;
    extern u8 *D_80269F40[];
    extern u8 *D_80269F44;
    f32 zeroRotation;
    f32 modelZ;
    f32 rotationX;
    f32 rotationZ;
    f32 unitScale;
    s32 initialSelection;
    u16 *nodeFlags;
    u16 savedNodeFlags;

    void func_8010E560(void);
    void func_80145680(s32);
    void func_8010EEF8(void *, f32, f32, f32, f32, f32, f32, f32, f32, f32, s32);
    void func_80142700(void *, s32);
    void func_80133998(void *, s32, s32, s32, f32);
    void func_8010F0B8(s32);
    void func_801190BC();

    D_801E5898 = 0;
    func_8010E560();
    func_80145680(0);
    D_801E6614[0] = 0;
    zeroRotation = *(f32 *)D_801E6614;
    modelZ = D_80100AE0;
    rotationX = D_80100AE4;
    rotationZ = D_80100AE8;
    unitScale = D_80100AEC;
    secondModelSlot = &D_80269F44;
    D_801E6618 = 0;
    D_801E661C = 0;
    D_801E6620 = 0;
    func_8010EEF8(D_80100AD4, zeroRotation, -30.0f, modelZ, rotationX, zeroRotation, rotationZ, unitScale, unitScale, unitScale, MENU_OBJECT_OPAQUE);
    func_80142700(D_80269F40[0], MENU_OBJECT_ANIMATION_COMPONENT);
    func_80133998(D_80269F40[0], 0, 1, 1, unitScale);
    *(u16 *)(*(u8 **)(*(u8 **)(D_80269F40[0] + MENU_OBJECT_MODEL_OFFSET) + MENU_MODEL_ROOT_OFFSET) + MENU_MODEL_NODE_FLAGS_OFFSET) |= MENU_MODEL_NODE_ALPHA_FLAG;
    func_8010EEF8(D_80100AD4, zeroRotation, 25.0f, modelZ, rotationX, zeroRotation, rotationZ, unitScale, unitScale, unitScale, MENU_OBJECT_OPAQUE);
    func_80142700(D_80269F44, MENU_OBJECT_ANIMATION_COMPONENT);
    func_80133998(*secondModelSlot, 0, 1, 1, D_80100AF0);
    nodeFlags = (u16 *)(*(u8 **)(*(modelResourceSlot = (u8 **)(D_80269F44 + MENU_OBJECT_MODEL_OFFSET)) + MENU_MODEL_ROOT_OFFSET) + MENU_MODEL_NODE_FLAGS_OFFSET);
    initialSelection = DIFFICULTY_MENU_NORMAL_ENTRY;
    savedNodeFlags = *nodeFlags;
    D_801E6720 = 0;
    *nodeFlags = savedNodeFlags | MENU_MODEL_NODE_ALPHA_FLAG;
    menuWords[MENU_STATE_SELECTION_WORD] = initialSelection;
    func_8010F0B8(DIFFICULTY_MENU_MODEL_COUNT);
    D_801E6510 = MENU_SLIDE_POSITIVE_X;
    D_801E6518 = MENU_SLIDE_NEGATIVE_X;
    D_801E650C = initialSelection;
    D_801E6514 = MENU_SLIDE_POSITIVE_Y;
    *inputCommand = MENU_INPUT_NONE;
    func_801190BC(inputCommand, menuWords);
    return 1;
}

/* strncmp-like: returns 1 if the first maxLen bytes of the strings differ, 0 if they match up to maxLen or a NUL. */
s32 func_80118FA4(u8 *str1, u8 *str2, s32 maxLen) {
    if (maxLen > 0) {
        maxLen += (s32)str2;
        do {
            if (*str1 != *str2) {
                return 1;
            }
            if (*str2 == 0) {
                return 0;
            }
            str2++;
            str1++;
        } while ((s32)str2 < maxLen);
    }
    return 0;
}

/* Start a new game: reset scene and progress, store the entered initials as the
 * player name and in the selected save slot, save, and load the first level. */
void func_80118FE4(void) {
    u8 firstInitial;
    u8 secondInitial;
    u8 thirdInitial;

    func_8010EBE8();
    func_80155A44(&D_80100AF4);
    func_8011F9F4();
    firstInitial = D_801E6700;
    D_801FA9A8 = firstInitial;
    *(&D_801EAA44 + (D_801EAB24 * LEVEL_SAVE_SLOT_BYTES)) = firstInitial;
    secondInitial = D_801E6701;
    D_801FA9A9 = secondInitial;
    *(&D_801EAA45 + (D_801EAB24 * LEVEL_SAVE_SLOT_BYTES)) = secondInitial;
    thirdInitial = D_801E6702;
    D_801FA9AA = thirdInitial;
    *(&D_801EAA46 + (D_801EAB24 * LEVEL_SAVE_SLOT_BYTES)) = thirdInitial;
    func_801335A8(0, thirdInitial);
    func_8011FF40(DIFFICULTY_MENU_START_LEVEL);
}

/*
 * Two-choice menu screen update (choice in menu[7]): draws the title and option
 * sprites with the selected one pulsing, bobs and decays the tilt of the two
 * 3D option objects (D_80269F40 / D_80269F44), then handles input: 5 = back,
 * 4 = confirm (option 0/1 resets the current save slot with that setting).
 * Returns 1 when the screen is left.
 */
s32 func_801190BC(s32 *input, s32 *menu)
{
  extern f32 D_801F60A0;
  extern f32 D_801F60A4;
  extern s16 D_801E7586;
  extern s32 D_801EAE70[];
  extern s32 D_801EAEA0[];
  extern s32 D_801EADE0[];
  extern s32 D_801EADB0[];
  extern s32 D_801EADBC[];
  extern u8 D_801E672F;
  extern s32 D_801E672C;
  extern f32 D_801E58A0;
  extern s32 D_801E58A4;
  extern s32 D_801E5894;
  extern s32 D_801E64C0;
  extern s32 D_801E64C8;
  extern s32 D_801E6720;
  extern s32 D_801E6614;
  extern s32 D_801E6618;
  extern f32 D_801E661C;
  extern f32 D_801E6620;
  extern u8 *D_80269F40;
  extern u8 *D_80269F44;
  extern f32 D_80100AFC;
  extern f32 D_80100B00;
  extern f32 D_80100B04;
  extern f32 D_80100B08;
  extern f32 D_80100B0C;
  extern f32 D_80100B10;
  extern f32 D_80100B1C;
  extern f32 D_80100B20;
  extern f32 D_80100B24;
  extern f32 D_80100B28;
  extern f32 D_80100B2C;
  extern f32 D_80100B30;
  extern f32 D_80100B34;
  extern f32 D_80100B38;
  extern f32 D_80100B3C;
  extern f64 D_80100B40;
  extern f32 D_80100B48;
  extern f32 D_80100B4C;
  extern f32 D_80100B50;
  extern f32 D_80100B54;
  extern f32 D_80100B58;
  extern f32 D_80100B5C;
  extern f32 D_80100B60;
  extern f32 D_80100B64;
  extern f32 D_80100B68;
  extern f32 D_80100B70;
  extern f32 D_80100B78;
  extern f32 D_80100B80;
  extern f32 D_80100B88;
  extern f32 D_80100B94;
  extern f64 D_80100B98;
  extern u8 D_801EAA44;
  extern s16 D_801EAB24;
  extern u8 D_801EAA55;
  void func_80145680(s32);
  void func_801469E4(s32, s32, s32, s32, s32, s32, f32, f32, s32, s32, s32);
  f32 func_801C6000(f32);
  s32 func_801100B8(s32 *, s32 *);
  void func_8010E400(void);
  void func_8010F1AC(s32);
  void func_8010F520(s32);
  void func_8013FBC0(u8 *, s32);
  f32 pad[2];
  f32 *scroll;
  s16 *language;
  f32 scale;
  s32 full;
  s32 one;
  f32 *tilt;
  f32 *tiltSecond;
  s32 fade;
  u32 bits;
  int alpha8;
  f32 alpha;
  f32 phase;
  f32 wave;
  f64 amplitude;
  f64 frequency;
  f64 height;
  void *object;
  u8 *first;
  func_80145680(1);
  {
    scroll = &D_801F60A0;
    scale = D_80100B00;
    language = &D_801E7586;
    full = 0xFF;
    one = 1;
    func_801469E4(0x104, (s16) ((scroll[0] / D_80100AFC) + D_80100B04), full, full, full, full, scale, scale, one, D_801EAE70[*language], one);
    func_801469E4((s16) (scroll[0] + D_80100B08), 0xBE, full, full, full, D_801E672F, scale, scale, one, D_801EAEA0[*language], one);
  }
  /* Fade the hint in while option 0 is selected, out otherwise. */
  if (menu[7] == 0)
  {
    fade = D_801E672C + 0x1E;
    if (fade > 0xFF)
    {
      fade = 0xFF;
    }
  }
  else
  {
    fade = D_801E672C;
    fade -= 0x1E;
    if (fade < 0)
    {
      fade = 0;
    }
  }
  D_801E672C = fade;
  func_80145680(0);
  func_801469E4(0xA0, (s16) (D_80100B10 - D_801F60A0), 0xFF, 0xFF, 0x37, 0xFF, D_80100B0C, D_80100B0C, 1, D_801EADE0[D_801E7586], 1);
  if (menu[7] == 0)
  {
    alpha = ((func_801C6000(D_801E58A0 * (*((f64 *) (((u8 *) (&D_80100B10)) + 4)))) * D_80100B1C) + D_80100B20) + D_80100B24;
    if (!(alpha >= D_80100B28))
    {
      bits = (s32) alpha;
    }
    else
    {
      bits = ((s32) (alpha - D_80100B28)) | 0x80000000;
    }
    alpha8 = (u8) bits;
  }
  else
  {
    alpha8 = 0xFF;
  }
  func_801469E4((s16) (D_801F60A4 + D_80100B2C), 0x64, 0xFF, 0xFF, 0xFF, alpha8, (menu[7]) ? (D_80100B30) : (D_80100B34), (menu[7]) ? (D_80100B38) : (D_80100B3C), 1, D_801EADB0[D_801E7586], 1);
  if (menu[7] == 1)
  {
    alpha = ((func_801C6000(D_801E58A0 * D_80100B40) * D_80100B48) + D_80100B4C) + D_80100B50;
    if (!(alpha >= D_80100B54))
    {
      bits = (s32) alpha;
    }
    else
    {
      bits = ((s32) (alpha - D_80100B54)) | 0x80000000;
    }
    alpha8 = (u8) bits;
  }
  else
  {
    alpha8 = 0xFF;
  }
  {
    f32 x = D_801F60A0;
    func_801469E4((s16) (D_80100B58 - x), 0x8B, 0xFF, 0xFF, 0xFF, alpha8, (menu[7] != 1) ? (D_80100B5C) : (D_80100B60), (menu[7] != 1) ? (D_80100B64) : (D_80100B68), 1, D_801EADBC[D_801E7586], 1);
  }
  if (D_801E64C8 != 0)
  {
    func_801100B8(input, menu);
  }
  /* Bob the two option objects and apply their tilt. */
  phase = D_801E58A0 * (*((f64 *) (((u8 *) (&D_80100B68)) + 4)));
  first = (u8 *) &D_80269F40;
  first = ((struct { u8 *p; } *) first)->p;
  tiltSecond = (f32 *) (&D_801E6618);
  amplitude = *((f64 *) (((u8 *) (&D_80100B70)) + 4));
  *((f32 *) (first + 0x78)) = tiltSecond[0];
  object = D_80269F40;
  wave = func_801C6000(phase);
  phase = D_801E58A0 * (frequency = *((f64 *) (((u8 *) (&D_80100B78)) + 4)));
  height = *((f64 *) (((u8 *) (&D_80100B80)) + 4));
  *((f32 *) ((u8 *) object + 0x7C)) = wave * amplitude + height;
  object = D_80269F40;
  wave = func_801C6000(phase);
  phase = D_801E58A0 * (*((f64 *) (((u8 *) (&D_80100B88)) + 4)));
  *((f32 *) ((u8 *) object + 0x80)) = wave * amplitude;
  tilt = tiltSecond - 1;
  *((f32 *) (((struct { u8 *p; } *) &D_80269F44)->p + 0x78)) = tilt[0];
  object = D_80269F44;
  wave = func_801C6000(phase);
  phase = D_801E58A0 * frequency;
  *((f32 *) ((u8 *) object + 0x7C)) = wave * amplitude + height;
  object = D_80269F44;
  *((f32 *) ((u8 *) object + 0x80)) = func_801C6000(phase) * amplitude;
  /* Stick left/right kicks the selected option's tilt. */
  if (((u32) (*input)) < 2)
  {
    tilt[menu[7]] = D_80100B94;
  }
  {
    f64 decay = D_80100B98;
    f32 a0 = tiltSecond[-1] * decay;
    f32 b0 = tiltSecond[0] * decay;
    f32 c0 = D_801E661C * decay;
    f32 d0 = D_801E6620 * decay;
    tiltSecond[-1] = a0;
    tiltSecond[0] = b0;
    D_801E661C = c0;
    D_801E6620 = d0;
  }
  if ((*input) == 5)
  {
    D_801E58A4 = *input;
    D_801E6720 = 0;
    func_8010E400();
    func_8010F1AC(2);
    return 1;
  }
  if ((*input) == 4)
  {
    if ((D_801E64C0 == 1) && (D_801E64C8 == 0))
    {
      return 0;
    }
    switch (menu[7])
    {
      case 0:
        func_8013FBC0((&D_801EAA44) + (D_801EAB24 * 0x1C), 0x1C);
        (&D_801EAA55)[D_801EAB24 * 0x1C] = 0;
        D_801E6720 = 1;
        D_801E5894 = 1;
        break;

      case 1:
        func_8013FBC0((&D_801EAA44) + (D_801EAB24 * 0x1C), 0x1C);
        (&D_801EAA55)[D_801EAB24 * 0x1C] = 1;
        D_801E6720 = 1;
        D_801E5894 = 1;
        break;

      case 2:
        break;

    }

    func_8010F1AC(2);
    func_8010E400();
    return 1;
  }
  func_8010F520(2);
  return 0;
}

/* Updates the 3-character name-entry screen: animates the titlebox models and fades, draws the character grid, entered initials, and prompt, and handles stick navigation, backspace/delete, confirm, and cancel. */
s32 func_801198D0(s32 *inputCommand, s32 *menuContext) {
    typedef struct {
        u8 pad0[0x26];
        s16 alpha;
        u8 pad28[0xC];
        s32 posX;
        f32 posY;
        u8 pad3C[0x3C];
        s32 rotX;
        s32 rotY;
        f32 rotZ;
        u8 pad84[0x18];
        u8 quaternion[4];
    } NameEntryModel;
    typedef struct { s8 c[2]; } CharPair;
    extern f32 D_801F60A0;
    extern f32 D_801F60A4;
    extern s16 D_801E7586;
    extern s32 D_801EAE70[];
    extern s32 D_801EAD98[];
    extern s32 D_801EAD44[];
    extern f32 D_801E58A0;
    extern s32 D_801E58A4;
    extern s32 D_801E5898;
    extern s32 D_801E64C0;
    extern NameEntryModel *D_80269F40[];
    extern NameEntryModel *D_80269F44[];
    extern s32 D_801F6138;
    extern s32 D_801EC860;
    extern s32 D_801E6704;
    extern u32 D_801E6708;
    extern u32 D_801E670C;
    extern u32 D_801E6710;
    extern s16 D_801E6716;
    extern u32 D_801E6718;
    extern s32 D_801E671C;
    extern s32 D_801E6724;
    extern s32 D_801F7D34;
    extern u8 D_801E66C0[];
    extern u8 D_801E66F4[];
    extern u8 D_801E66F8[];
    extern u8 D_801E66FC[];
    extern u8 D_801E66FF;
    extern f32 D_801F9214[];
    extern u8 D_80202218;
    extern s16 D_801FAA90;
    extern s16 D_801FAA92;
    extern u8 D_801FAAC6;
    extern u8 D_801FAAC8;
    extern s8 D_80100BA0;
    extern s8 D_80100BA1;
    extern u8 D_80100BA4;
    extern const f32 D_80100BA8;
    extern const f32 D_80100BAC;
    extern const f32 D_80100BB0;
    extern const f32 D_80100BB4;
    extern const f32 D_80100BB8;
    extern const f32 D_80100BC0;
    extern const f32 D_80100BCC;
    extern const f32 D_80100BD0;
    extern const f32 D_80100BD4;
    extern const f32 D_80100BD8;
    extern const f32 D_80100BDC;
    extern const f32 D_80100BE0;
    extern const f32 D_80100BE4;
    extern const f32 D_80100BF0;
    extern const f32 D_80100BF4;
    extern const f64 D_80100BF8;
    extern const f32 D_80100C08;
    extern const f32 D_80100C0C;
    extern const f32 D_80100C10;
    extern const f32 D_80100C14;
    extern const f32 D_80100C18;
    extern const f32 D_80100C1C;
    extern const f32 D_80100C20;
    extern const f64 D_80100BE8;
    extern const f64 func_80100C00;
    void func_80145680(s32);
    void func_801469E4(s32, s32, s32, s32, s32, s32, f32, f32, s32, s32, s32);
    f32 func_801C6000(f32);
    void func_8010E400(void);
    void func_8010F1AC(s32);
    void func_8010F520(s32);
    void func_8012643C(void);
    void func_8015C350(u8 *, s32 *);
    s32 func_801D20F8(u8 *);
    void func_801D211C(u8 *, u8 *, s32);
    void func_801793DC(s32, s32, s32, s32);
    u8 cellText[20];
    u8 *str;
    f64 bias;
    u32 row;
    u32 col;
    s32 cellIndex;
    s32 i;
    s16 alpha;
    s32 stickAxis;
    f32 slideDist;
    f32 fadeAlpha;
    f32 textScale;
    NameEntryModel *o;

    func_8010F520(NAME_ENTRY_MODEL_COUNT);
    func_80145680(1);
    cellIndex = 0;
    if ((&D_801EAA55)[D_801EAB24 * LEVEL_SAVE_SLOT_BYTES] != NAME_ENTRY_TIME_TRIAL_MODE) {
        func_801469E4(0x104, (s16)(D_801F60A0 / D_80100BA8 + D_80100BB0), 0xFF, 0xFF, 0xFF, 0xFF, D_80100BAC, D_80100BAC, 1, D_801EAE70[D_801E7586], 1);
    }
    func_80145680(0);
    func_8012643C();
    D_80269F40[0]->posX = 0;
    D_80269F44[0]->posX = 0;
    D_80269F40[0]->posY = D_80100BB8;
    D_80269F44[0]->posY = D_80100BB8;
    D_80269F40[0]->rotX = 0;
    D_80269F44[0]->rotX = 0;
    D_80269F40[0]->rotY = 0;
    D_80269F44[0]->rotY = 0;
    D_80269F40[0]->rotZ = ({ func_801C6000(D_801E58A0 / D_80100BB4) * *(const f64 *)((u8 *)&D_80100BB8 + 4) + *(const f64 *)((u8 *)&D_80100BC0 + 4); });
    *(f32 *)((s32)D_80269F44[0] + 0x80) = ({ func_801C6000(D_801E58A0 / D_80100BB4) * *(const f64 *)((u8 *)&D_80100BB8 + 4) + *(const f64 *)((u8 *)&D_80100BC0 + 4); });

    {
        NameEntryModel *model = D_80269F40[0];

        if (D_801F6138 < 2) {
            slideDist = D_801F60A0;
            if ((D_80100BCC - slideDist) * D_80100BD0 / D_80100BD4 > D_80100BD0) {
                alpha = NAME_ENTRY_MODEL_OPAQUE;
            } else {
                fadeAlpha = (D_80100BD4 - slideDist) * D_80100BD0 / D_80100BD4;
                if (fadeAlpha < 0.0f) {
                    alpha = 0;
                } else {
                    model->alpha = alpha = fadeAlpha;
                    goto set_primary_alpha;
                }
            }
        } else {
            alpha = NAME_ENTRY_MODEL_OPAQUE;
        }
        model->alpha = alpha;
    set_primary_alpha:;
    }

    {
        NameEntryModel *shadowModel = D_80269F44[0];

        alpha = NAME_ENTRY_SHADOW_MAX_ALPHA;
        if (D_801F6138 < 2) {
            slideDist = D_801F60A0;
            if ((D_80100BD8 - slideDist) * D_80100BDC / D_80100BE0 > D_80100BDC) {
                alpha = NAME_ENTRY_SHADOW_MAX_ALPHA;
            } else {
                fadeAlpha = (D_80100BE0 - slideDist) * D_80100BDC / D_80100BE0;
                if (fadeAlpha < 0.0f) {
                    alpha = 0;
                } else {
                    alpha = fadeAlpha / D_80100BE4;
                }
            }
        }
        shadowModel->alpha = alpha;
    }

    for (i = 0; i < D_801EC860; i++) {
        func_8015C350(D_80269F40[i]->quaternion, &D_80269F40[i]->rotX);
    }

    for (row = 0; row < D_801E6708; row++) {
        for (col = 0; col < D_801F7D34; col++) {
            *(CharPair *)cellText = *(CharPair *)&D_80100BA0;
            func_8012C2B0(cellText + 2, 0, 0x12);
            cellText[0] = D_801E66C0[cellIndex];
            textScale = D_80100BF4;
            switch (D_801E66C0[cellIndex]) {
                case NAME_ENTRY_KEY_BACKSPACE:
                    func_801D211C(cellText, D_801E66F4, func_801D20F8(D_801E66F4));
                    break;
                case NAME_ENTRY_KEY_CONFIRM:
                    func_801D211C(cellText, D_801E66FC, func_801D20F8(D_801E66FC));
                    break;
                case NAME_ENTRY_KEY_SPACE:
                    func_801D211C(cellText, D_801E66F8, func_801D20F8(D_801E66F8));
                    break;
                case NAME_ENTRY_KEY_BLANK:
                    cellText[0] = D_80100BA4;
                    break;
            }
            if (cellIndex == D_801E6704) {
                textScale *= D_80100BF8;
            }
            if (row & 1) {
                func_801469E4((s16)((f32)({ s32 u_ = D_801E670C + col * NAME_ENTRY_CELL_SPACING; f64 d_ = u_; if (u_ < 0) d_ += D_80100BE8; d_; }) - D_801F60A4), (s16)(D_801E6710 + row * NAME_ENTRY_CELL_SPACING), 0xFF, 0xFF, 0xFF, 0xFF, textScale, textScale, 1, (s32)cellText, 1);
            } else {
                func_801469E4((s16)((f32)({ s32 u_ = D_801E670C + col * NAME_ENTRY_CELL_SPACING; f64 d_ = u_; if (u_ < 0) d_ += D_80100BE8; d_; }) + D_801F60A4), (s16)(D_801E6710 + row * NAME_ENTRY_CELL_SPACING), 0xFF, 0xFF, 0xFF, 0xFF, textScale, textScale, 1, (s32)cellText, 1);
            }
            if (cellIndex == D_801E6704) {
                D_801F9214[0] -= (D_801F9214[0] - (f32)({ s32 u_ = D_801E670C + col * NAME_ENTRY_CELL_SPACING - 10; f64 d_ = u_; if (u_ < 0) d_ += D_80100BE8; d_; })) / D_80100BF0;
                D_801F9214[1] -= (D_801F9214[1] - (f32)({ s32 u_ = D_801E6710 + row * NAME_ENTRY_CELL_SPACING - 10; f64 d_ = u_; if (u_ < 0) d_ += D_80100BE8; d_; })) / D_80100BF0;
            }
            cellIndex++;
        }
    }

    func_801469E4(D_801E6716, (s16)((f32)({ s32 u_ = D_801E6718; f64 d_ = u_; if (u_ < 0) d_ += func_80100C00; d_; }) + D_801F60A0), 0xFF, 0xFF, 0xFF, 0xFF, D_80100C08, D_80100C08, 1, (s32)&D_801E6700, 0);
    if ((&D_801EAA55)[D_801EAB24 * LEVEL_SAVE_SLOT_BYTES] == NAME_ENTRY_TIME_TRIAL_MODE) {
        func_801469E4(0xA0, (s16)(D_80100C14 - D_801F60A4 / D_80100C0C), 0xFF, 0xFF, 0x37, 0xFF, D_80100C10, D_80100C10, 1, D_801EAD98[D_801E7586], 1);
    } else {
        func_801469E4(0xA0, (s16)(D_80100C20 - D_801F60A4 / D_80100C18), 0xFF, 0xFF, 0x37, 0xFF, D_80100C1C, D_80100C1C, 1, D_801EAD44[D_801E7586], 1);
    }

    {
        u8 *stickBase = (u8 *)&D_801FAA90;
        stickAxis = *(s16 *)(stickBase + D_80202218 * NAME_ENTRY_CONTROLLER_STRIDE);
        stickBase = NULL;
    }
    if ((stickAxis < 0 ? -stickAxis : stickAxis) > NAME_ENTRY_STICK_DEADZONE && D_801E671C == 0) {
        func_801793DC(MENU_SOUND_MOVE, MENU_SOUND_VOLUME, MENU_SOUND_CENTER_PAN, MENU_SOUND_NORMAL_PITCH);
        if (*(s16 *)((u8 *)&D_801FAA90 + D_80202218 * NAME_ENTRY_CONTROLLER_STRIDE) > 0) {
            if ((u32)D_801E6704 % (u32)D_801F7D34 == D_801F7D34 - 1) {
                D_801E6704 -= 9;
            } else {
                D_801E6704++;
            }
            while (D_801E66C0[D_801E6704] == NAME_ENTRY_KEY_BLANK) {
                D_801E6704++;
            }
        } else {
            D_801E6704 = ((u32)D_801E6704 % (u32)D_801F7D34 == 0) ? D_801E6704 + 9 : D_801E6704 - 1;
        }
        while (D_801E66C0[D_801E6704] == NAME_ENTRY_KEY_BLANK) {
            D_801E6704--;
        }
        D_801E671C = NAME_ENTRY_REPEAT_DELAY;
    }

    {
        u8 *stickBase = (u8 *)&D_801FAA92;
        stickAxis = *(s16 *)(stickBase + D_80202218 * NAME_ENTRY_CONTROLLER_STRIDE);
        stickBase = NULL;
    }
    if ((stickAxis < 0 ? -stickAxis : stickAxis) > NAME_ENTRY_STICK_DEADZONE && D_801E671C == 0) {
        func_801793DC(MENU_SOUND_MOVE, MENU_SOUND_VOLUME, MENU_SOUND_CENTER_PAN, MENU_SOUND_NORMAL_PITCH);
        if (*(s16 *)((u8 *)&D_801FAA92 + D_80202218 * NAME_ENTRY_CONTROLLER_STRIDE) > 0) {
            if ((u32)D_801E6704 < (u32)D_801F7D34) {
                D_801E6704 += 40;
            } else {
                D_801E6704 -= D_801F7D34;
            }
            while (D_801E66C0[D_801E6704] == NAME_ENTRY_KEY_BLANK) {
                D_801E6704 -= D_801F7D34;
            }
        } else {
            D_801E6704 = ((u32)D_801E6704 < (u32)(func_801D20F8(D_801E66C0) - D_801F7D34)) ? D_801E6704 + D_801F7D34 : D_801E6704 - 40;
        }
        while (D_801E66C0[D_801E6704] == NAME_ENTRY_KEY_BLANK) {
            D_801E6704++;
        }
        D_801E671C = NAME_ENTRY_REPEAT_DELAY;
    }

    if (D_801E64C8 != 0 || D_801E64C0 != 1) {
        if (D_801E5898 != 0 && (&D_801FAAC8)[D_80202218 * NAME_ENTRY_CONTROLLER_STRIDE] != 0) {
            if (func_801D20F8(&D_801E6700) != 0) {
                (&D_801E66FF)[func_801D20F8(&D_801E6700)] = 0;
                func_801793DC(MENU_SOUND_CANCEL, MENU_SOUND_VOLUME, MENU_SOUND_CENTER_PAN, MENU_SOUND_NORMAL_PITCH);
            }
        }
    }
    if (D_801E5898 != 0 && (&D_801FAAC6)[D_80202218 * NAME_ENTRY_CONTROLLER_STRIDE] != 0 && D_801E6724 == 0) {
        func_801793DC(MENU_SOUND_CONFIRM, MENU_SOUND_VOLUME, MENU_SOUND_CENTER_PAN, MENU_SOUND_NORMAL_PITCH);
        if (D_801E66C0[D_801E6704] == NAME_ENTRY_KEY_BACKSPACE) {
            if (func_801D20F8(&D_801E6700) != 0) {
                (&D_801E66FF)[func_801D20F8(&D_801E6700)] = 0;
            }
        } else if (D_801E66C0[D_801E6704] == NAME_ENTRY_KEY_CONFIRM) {
            func_8010E400();
            D_801E58A4 = NAME_ENTRY_NEXT_MENU_CONFIRM;
            func_8010F1AC(NAME_ENTRY_MODEL_COUNT);
            D_801E6724 = 1;
            return 1;
        } else if ((u32)func_801D20F8(&D_801E6700) < NAME_ENTRY_MAX_CHARS) {
            (&D_801E6700)[func_801D20F8(&D_801E6700)] = D_801E66C0[D_801E6704];
            (&D_801E6701)[func_801D20F8(&D_801E6700)] = 0;
            if (func_801D20F8(&D_801E6700) == NAME_ENTRY_MAX_CHARS) {
                D_801E6704 = func_801D20F8(D_801E66C0) - 1;
            }
        } else {
            D_801E6704 = func_801D20F8(D_801E66C0) - 1;
        }
    }
    if (D_801E671C != 0) {
        D_801E671C--;
    }
    if (*inputCommand == NAME_ENTRY_CMD_CANCEL) {
        if (D_801E58A4 != NAME_ENTRY_NEXT_MENU_CANCEL) {
            func_801793DC(MENU_SOUND_CANCEL, MENU_SOUND_VOLUME, MENU_SOUND_CENTER_PAN, MENU_SOUND_NORMAL_PITCH);
            D_801E58A4 = NAME_ENTRY_NEXT_MENU_CANCEL;
            func_8010E400();
            func_8010F1AC(NAME_ENTRY_MODEL_COUNT);
            return 1;
        }
        return 0;
    }
    return 0;
}


/* Finish the name-entry transition and copy time-trial initials before returning to selection. */
s32 func_8011A6EC(s32 menuCommandAddress, s32 menuContextAddress) {
    s8 *departingLevel;

    if (D_801E64C8 == 0) {
        func_8010F23C(NAME_ENTRY_MODEL_COUNT);
        func_801198D0(menuCommandAddress, menuContextAddress);
        func_8010E558();
        return 0;
    }
    func_8010F94C();
    if (*(&D_801EAA55 + D_801EAB24 * LEVEL_SAVE_SLOT_BYTES) == NAME_ENTRY_TIME_TRIAL_MODE) {
        departingLevel = &D_801E7532;
        D_801E6792[D_801E693C[departingLevel[0]][0]][0] = D_801E6700;
        D_801E6792[D_801E693C[departingLevel[0]][0]][1] = D_801E6701;
        D_801E6792[D_801E693C[departingLevel[0]][0]][2] = D_801E6702;
        func_80132C04();
        func_80132DA8();
        func_8010E0D8(menuCommandAddress, menuContextAddress);
    }
    return 1;
}

/* Start-up step gated by D_801E64C8: if it is clear, call the empty stub
 * func_8010E558 and return 0. Otherwise reset state (D_801EC7A7, func_8012A738),
 * set both 0x12C (300) timers, run func_80122F9C, clear both 320x240x16-bit
 * framebuffers (0x25800 bytes each, func_8012C2B0 = memset), call func_8010FB30
 * and return 1. */
s32 func_8011A85C(void) {
    if (D_801E64C8 == 0) {
        func_8010E558();
        return 0;
    }
    D_801EC7A7 = 0;
    func_8012A738(0, 0, 0);
    D_801E753C = 0x12C;
    D_801E753E = 0x12C;
    func_80122F9C();
    func_8012C2B0(D_80092030, 0, 0x25800);
    func_8012C2B0(D_800B7830, 0, 0x25800);
    func_8010FB30();
    return 1;
}

/* Once the menu transition has finished, black out the screen and switch to the level-select game state. */
s32 func_8011A900(void) {
    if (D_801E64C8 == 0) {
        func_8010E558();
        return 0;
    }
    func_8012A738(0, 0, 0);
    D_801E753C = MENU_TRANSITION_FULL_EXTENT;
    D_801E753E = MENU_TRANSITION_FULL_EXTENT;
    func_80122F9C();
    func_8012C2B0(D_80092030, 0, MENU_FRAMEBUFFER_BYTES);
    func_8012C2B0(D_800B7830, 0, MENU_FRAMEBUFFER_BYTES);
    func_8010FB80(GAME_STATE_LEVEL_SELECT);
    return 1;
}

extern s32 D_801E6720;
extern s32 D_801E5894;

/* Finish the difficulty-menu exit and start a confirmed new game with the entered initials. */
s32 func_8011A99C(void) {
    u8 firstInitial;
    u8 secondInitial;
    s32 thirdInitial;

    if (D_801E64C8 == 0) {
        ((void (*)(void))func_801190BC)();
        func_8010F23C(DIFFICULTY_MENU_MODEL_COUNT);
        if (D_801E6720 != 0) {
            D_801E5894 = 1;
        }
        return 0;
    }
    func_8010F94C();
    if (D_801E6720 != 0) {
        func_8012A738(0, 0, 0);
        D_801E753C = SCENE_RESET_TRANSITION_EXTENT;
        D_801E753E = SCENE_RESET_TRANSITION_EXTENT;
        func_80122F9C();
        func_8012C2B0(D_80092030, 0, MENU_FRAMEBUFFER_BYTES);
        func_8012C2B0(D_800B7830, 0, MENU_FRAMEBUFFER_BYTES);
        func_8010EBE8();
        func_80155A44(&D_80100AF4);
        func_8011F9F4();
        firstInitial = D_801E6700;
        D_801FA9A8 = firstInitial;
        *(&D_801EAA44 + (D_801EAB24 * LEVEL_SAVE_SLOT_BYTES)) = firstInitial;
        secondInitial = D_801E6701;
        D_801FA9A9 = secondInitial;
        *(&D_801EAA45 + (D_801EAB24 * LEVEL_SAVE_SLOT_BYTES)) = secondInitial;
        thirdInitial = D_801E6702;
        D_801FA9AA = thirdInitial;
        *(&D_801EAA46 + (D_801EAB24 * LEVEL_SAVE_SLOT_BYTES)) = thirdInitial;
        func_801335A8(0, thirdInitial);
        func_8011FF40(DIFFICULTY_MENU_START_LEVEL);
    }
    return 1;
}

/* Original compiler padding. */
const u32 D_8011AB24_padding[] __attribute__((section(".text"))) = {
    0x24350000, 0x00000400, 0x00000301
};

extern s16 D_802902FE;
extern f32 D_80290394;
extern f32 D_80290398;
extern f32 D_8029039C;
extern u8 *D_8028FAC8;
extern u8 *D_8028FAD0;
extern f32 D_80100D3C;
extern s32 D_801EC740;
void func_801364D0(void);
extern f32 D_8028F918;
extern s32 D_8028F91C;
extern s32 D_8028FAF4;
extern s32 D_8028FAF8;
extern s16 D_8028FBF4;
void func_8011BCB8(void);
void func_80162EAC(f32, f32, s32, s32, s32, s32, s32);
extern f64 D_80100D30;
extern f32 D_8029F9B4;
extern f32 D_80100D38;
void func_80128DF8(s32, s32, s32);

extern s32 D_801F7D88, D_801F7D74, D_801F7D84, D_801F7D70;
extern f32 D_801F7D4C, D_801F7D50, D_801F7D54, D_801F7D78;
extern f32 D_801F7D40, D_801F7D44, D_801F7D48;
extern f32 D_801F7D58, D_801F7D5C, D_801F7D60;
extern f32 D_801F7D64, D_801F7D68, D_801F7D6C;
extern u8 *D_80290304;
extern u8 D_8029F978[];
extern s16 D_801E7542;
extern u8 D_801EC7D2;
extern u8 *D_801F9628;
extern f32 D_801E6730, D_801E6734, D_801E6738, D_801E673C, D_801E6740;
extern s32 D_801E6744, D_801E6748;
extern f32 D_801E674C;
extern s16 D_801E6752;
extern u8 D_8029014C[];
extern s32 D_80290150;
extern f32 D_80290310;
extern u32 D_80290374[];
extern s32 D_8029F394;
extern u8 *D_801F0118, *D_801F011C, *D_801F0120;
extern f32 D_801EE1F8, D_801EE248, D_801EE298;
f32 func_801496C8(f32);
f32 func_8014944C(f32, f32);
s32 func_80147000(s32);
void func_801785E0(void *, s32, s32, void *, s32);
void func_80178704(void *);
void func_801490AC(void *, void *, f32);
void func_801499A0(void *, void *, void *);
void func_80151FD0(void *, u32, u8 *, s32);
void func_80178134(s32, void *, s32, s16);
void *func_801B66D4(s32, void *, void *, s32, s32);
void func_8014915C(void *, void *, f32, s32);
extern f64 D_80100C60;
extern f64 D_80100C68;
extern f32 D_80100C80;
extern f64 D_80100CB8;
extern f64 D_80100CC0;
extern f64 D_80100CD0;
extern f64 D_80100CD8;
extern f64 D_80100CE0;
extern f64 D_80100CF0;
extern f64 D_80100CF8;
extern f64 D_80100D00;
extern f64 D_80100D10;
extern f64 D_80100D18;
extern f64 D_80100D20;
extern f32 D_80100C54;
extern f32 D_80100C58;
extern f32 D_80100C5C;
extern f32 D_80100C70;
extern f32 D_80100C74;
extern f32 D_80100C78;
extern f32 D_80100C7C;
extern f32 D_80100C8C;
extern f32 D_80100C90;
extern f32 D_80100C94;
extern f32 D_80100C98;
extern f32 D_80100C9C;
extern f32 D_80100CA0;
extern f32 D_80100CA4;
extern f32 D_80100CA8;
extern f32 D_80100CAC;
extern f32 D_80100CB0;
extern f32 D_80100CB4;
extern f32 D_80100CC8;
extern f32 D_80100CCC;
extern f32 D_80100CE8;
extern f32 D_80100CEC;
extern f32 D_80100D08;
extern f32 D_80100D0C;
extern f32 D_80100D28;
extern f32 D_80100D2C;
/* Per-frame update for the Shooting Gallery bonus stage (level 19 / 0x13).
 * Tracks knocked-down targets across three rows of 10 (IDs 70..79, 90..99,
 * 110..119), steers the player-mounted cannon turret from the analog stick,
 * updates turret sound, rumble, camera aim, and side wheels, fires cannon
 * shots with recoil and muzzle particles, and ramps target-track speeds. */
void func_8011AB30(void)
{
  u8 *cannon = func_8017DBA0(SHOOTING_GALLERY_CANNON_ID);
  u8 *stickYPtr;
  f32 *shotMeshScale;
  s32 hitCount = 0;
  s32 i;
  u8 *object;
  u8 *rotation;
  u8 *projectile;
  const f32 wheelOffsetZ;
  f32 yawDelta;
  f32 pitchDelta;
  f32 maxTurnDelta;
  f32 *scratchVec;
  u32 *playerQuat;
  f32 wheelOffsetY;
  const f32 *recoilPtr;
  f32 savedWheelOffsetZ;
  f32 initWheelOffsetY;
  f32 *scratchVecAddr;
  u8 inputDisabled;

  /* First-frame initialization for the shooting gallery turret and counters. */
  if (D_802004E0 == 0)
  {
    typedef struct { s32 v; } IntBox;
    typedef struct { u8 pad[0x2C]; u8 *rotation; } PlatformRotPtr;
    typedef struct { u8 pad[0x38]; f32 pitch; } RotAnglesPitch;
    typedef struct { u8 *v; } PtrBox;
    u8 **playerMount = &D_80290304;
    s32 *cameraFlags = &D_8028F908;
    ((IntBox *) cameraFlags)->v &= ~0x10;
    rotation = ((PlatformRotPtr *) cannon)->rotation;
    D_801F7D88 = 0; /* displayed knocked-down target count */
    D_801F7D74 = 0; /* stage-clear delay timer */
    D_801F7D84 = 0; /* shots fired */
    D_801F7D70 = 0; /* fire cooldown */
    ((RotAnglesPitch *) rotation)->pitch = *((const f32 *) (&D_80100C54));
    ((PtrBox *) playerMount)->v = D_8029F978;
    func_80133998(((u8 *) playerMount) - 0x2C, 15, 0, 0, 0.0f);
    *((s32 *) (&D_801F7D4C)) = 0;
    *((s32 *) (&D_801F7D78)) = 0;
    D_801F7D50 = *((const f32 *) (&D_80100C58));
    D_801F7D54 = *((const f32 *) (&D_80100C5C));
  }

  /* Zero player velocity and count knocked-down targets across the three rows. */
  D_80290330 = (D_80290334 = (D_80290338 = 0.0f));
  for (i = SHOOTING_GALLERY_ROW1_FIRST_TARGET; i < SHOOTING_GALLERY_ROW1_END_TARGET; i++)
  {
    u8 *targetState;
    u8 *target = func_8017DBA0(i);
    targetState = *((u8 **) (target + 0x38));
    if ((targetState[0x56] == 1) || ((targetState[0x57] == 1) && ((*((f32 *) (target + 0xF4))) == 0.0f)))
    {
      hitCount++;
    }
  }

  for (i = SHOOTING_GALLERY_ROW2_FIRST_TARGET; i < SHOOTING_GALLERY_ROW2_END_TARGET; i++)
  {
    u8 *targetState;
    u8 *target = func_8017DBA0(i);
    targetState = *((u8 **) (target + 0x38));
    if ((targetState[0x56] == 1) || ((targetState[0x57] == 1) && ((*((f32 *) (target + 0xF4))) == 0.0f)))
    {
      hitCount++;
    }
  }

  scratchVecAddr = &D_801F7D64;
  for (i = SHOOTING_GALLERY_ROW3_FIRST_TARGET; i < SHOOTING_GALLERY_ROW3_END_TARGET; i++)
  {
    u8 *targetState;
    u8 *target = func_8017DBA0(i);
    targetState = *((u8 **) (target + 0x38));
    if ((targetState[0x56] == 1) || ((targetState[0x57] == 1) && ((*((f32 *) (target + 0xF4))) == 0.0f)))
    {
      hitCount++;
    }
  }

  /* Step displayed hit counter toward hitCount and clear stage once all 30 are down. */
  if (D_801F7D88 != hitCount)
  {
    if (hitCount < D_801F7D88)
    {
      D_801F7D88--;
    }
    else
    {
      D_801F7D88++;
    }
  }
  if (D_801F7D88 == SHOOTING_GALLERY_TOTAL_TARGETS)
  {
    if (D_801F7D74 == 0)
    {
      D_801F7D74 = SHOOTING_GALLERY_WIN_DELAY_FRAMES;
    }
    else
      if ((--D_801F7D74) == 0)
    {
      func_80128DF8(5, 1, 1);
    }
  }
  else
  {
    D_801F7D74 = 0;
  }
  if (D_801E7542)
  {
    D_8028FB3C = 0;
    D_8028FB40 = 5;
  }

  /* Lock player in turret action and save previous yaw/pitch for delta speed. */
  D_80290300 = 0;
  *((s16 *) (D_802903AC + 4)) = SHOOTING_GALLERY_PLAYER_ACTION;
  *((s32 *) (cannon + 0xA8)) |= 0x4000;
  {
    u8 *yawRot = *((u8 **) (cannon + 0x2C));
    *((f32 *) (yawRot + 0x48)) = *((f32 *) (yawRot + 0x3C));
  }
  {
    u8 *pitchRot = *((u8 **) (cannon + 0x2C));
    inputDisabled = D_801EC7D2;
    *((f32 *) (pitchRot + 0x44)) = *((f32 *) (pitchRot + 0x38));
  }

  /* Steer cannon yaw and clamped pitch from the active controller stick. */
  if ((!inputDisabled) && ((!D_801F9628) || (!(*((s32 *) (D_801F9628 + 8))))))
  {
    f32 newPitch;
    f32 newYaw;
    rotation = *((u8 **) (cannon + 0x2C));
    newYaw = func_801496C8((*((f32 *) (rotation + 0x3C))) - (((f32) (*((s16 *) (((u8 *) (&D_801FAA90)) + (D_80202218 * PHYSICS_CONTROLLER_RECORD_STRIDE))))) / (*((const f32 *) (&D_801E6730)))));
    stickYPtr = ((u8 *) (&D_801FAA92)) + (D_80202218 * PHYSICS_CONTROLLER_RECORD_STRIDE);
    *((f32 *) ((*((u8 **) (cannon + 0x2C))) + 0x3C)) = newYaw;
    rotation = *((u8 **) (cannon + 0x2C));
    newPitch = (*((f32 *) (rotation + 0x38))) + (((f32) (*((s16 *) stickYPtr))) / (*((const f32 *) (&D_801E6734))));
    *((f32 *) (rotation + 0x38)) = ((newPitch < D_80100C60) || (newPitch < D_80100C68)) ? ((newPitch < D_80100C60) ? (*((const f32 *) (&D_80100C70))) : (newPitch)) : (*((const f32 *) (&D_80100C74)));
  }

  /* Drive turret-turning positional sound and vertical rumble from angular speed. */
  rotation = *((u8 **) (cannon + 0x2C));
  yawDelta = func_8014944C(*((f32 *) (rotation + 0x48)), *((f32 *) (rotation + 0x3C)));
  rotation = *((u8 **) (cannon + 0x2C));
  pitchDelta = func_8014944C(*((f32 *) (rotation + 0x44)), *((f32 *) (rotation + 0x38)));
  if (pitchDelta < yawDelta)
  {
    maxTurnDelta = yawDelta;
  }
  else
  {
    maxTurnDelta = func_8014944C(*((f32 *) ((*((u8 **) (cannon + 0x2C))) + 0x44)), *((f32 *) ((*((u8 **) (cannon + 0x2C))) + 0x38)));
  }
  yawDelta = maxTurnDelta;
  if (yawDelta != 0.0f)
  {
    if (!(*((s32 *) D_8029014C)))
    {
      func_801785E0(D_8029014C, D_801E6752, 0, D_8029030C, 128);
    }
    *((s32 *) (D_8029014C + 4)) = ((yawDelta * (*((const f32 *) (&D_801E674C)))) < (*((const f32 *) (&D_80100C78)))) ? ((s32) (yawDelta * (*((const f32 *) (&D_801E674C))))) : (100);
    *((s16 *) (D_8029014C + 0x10)) = (s32) ((yawDelta * (*((const f32 *) (&D_80100C7C)))) + D_80100C80);
  }
  else
    if (*((s32 *) D_8029014C))
  {
    D_80290150 -= 5;
    if (D_80290150 <= 0)
    {
      func_80178704(D_8029014C);
    }
  }
  rotation = *((u8 **) (cannon + 0x2C));
  if (((*((f32 *) (rotation + 0x38))) != (*((f32 *) (rotation + 0x44)))) || ((*((f32 *) (rotation + 0x3C))) != (*((f32 *) (rotation + 0x48)))))
  {
    D_801F7D78 = (((f32) func_80147000((D_801E6748 << 1) | 1)) - ((f32) D_801E6748)) / (*((f64 *) (((u8 *) (&D_80100C80)) + 4)));
    scratchVec = scratchVecAddr;
  }
  else
  {
    D_801F7D78 /= *((const f32 *) (&D_80100C8C));
  }
  scratchVec = scratchVecAddr;

  /* Position the left and right cannon wheels to match the turret yaw. */
  {
    u8 *wheel;
    wheel = func_8017DBA0(SHOOTING_GALLERY_LEFT_WHEEL_ID);
    *((f32 *) ((*((u8 **) (wheel + 0x2C))) + 0x3C)) = *((f32 *) ((*((u8 **) (cannon + 0x2C))) + 0x3C));
    scratchVec[0] = *((const f32 *) (&D_80100C90));
    initWheelOffsetY = (wheelOffsetY = *((const f32 *) (&D_80100C94)));
    wheelOffsetZ = *((const f32 *) (&D_80100C98));
    scratchVec[1] = initWheelOffsetY;
    scratchVec[2] = (savedWheelOffsetZ = wheelOffsetZ);
    func_801490AC(wheel + 0xB4, scratchVec, *((f32 *) ((*((u8 **) (wheel + 0x2C))) + 0x3C)));
    wheel = func_8017DBA0(SHOOTING_GALLERY_RIGHT_WHEEL_ID);
    *((f32 *) ((*((u8 **) (wheel + 0x2C))) + 0x3C)) = *((f32 *) ((*((u8 **) (cannon + 0x2C))) + 0x3C));
    scratchVec[0] = *((const f32 *) (&D_80100C9C));
    scratchVec[1] = wheelOffsetY;
    scratchVec[2] = savedWheelOffsetZ;
    func_801490AC(wheel + 0xB4, scratchVec, *((f32 *) ((*((u8 **) (wheel + 0x2C))) + 0x3C)));
  }

  /* Sync player orientation and position to the cannon turret. */
  func_8015C350(cannon + 0x11C, (*((u8 **) (cannon + 0x2C))) + 0x38);
  playerQuat = D_80290374;
  {
    typedef struct
    {
      u32 w[4];
    } QuatWords;
    *((QuatWords *) playerQuat) = *((QuatWords *) (cannon + 0x11C));
  }
  scratchVec[0] = 0;
  scratchVec[2] = 0;
  scratchVec[1] = *((const f32 *) (&D_80100CA0));
  func_801499A0(scratchVec, scratchVec, playerQuat);
  (&D_80290310)[-1] = scratchVec[0] + (*((f32 *) (cannon + 0xB4)));
  D_80290310 = scratchVec[1] + (*((f32 *) (cannon + 0xB8)));
  D_80290314 = scratchVec[2] + (*((f32 *) (cannon + 0xBC)));
  if (*((s32 *) (D_801F9628 + 8)))
  {
    return;
  }

  /* Blend camera eye behind the cannon and aim forward along the turret quaternion. */
  {
    f32 *lookTarget = &D_801F7D40;
    f32 *eyeTarget = &D_801F7D58;
    *lookTarget = (D_801F7D44 = 0.0f);
    D_801F7D48 = *((const f32 *) (&D_80100CA4));
    func_801499A0(lookTarget, lookTarget, playerQuat);
    func_801499A0(eyeTarget, &D_801F7D4C, playerQuat);
    *lookTarget += *((f32 *) D_8029030C);
    D_801F7D44 += D_80290310;
    D_801F7D48 += D_80290314;
    *eyeTarget += *((f32 *) D_8029030C);
    D_801F7D5C += D_80290310;
    D_801F7D60 += D_80290314;
    func_80149398(D_8028F914, D_8028F914, *((const f32 *) (&D_801E6740)), eyeTarget, (*((const f32 *) (&D_80100CA8))) - (*((const f32 *) (&D_801E6740))));
    func_80162EAC(*((f32 *) D_8028F914), D_8028F918, D_8028F91C, (s32) lookTarget, (s32) (&D_801ED3C4), 10, 0);
  }
  if (D_801EC7D2 || (D_801F9628 && (*((s32 *) (D_801F9628 + 8)))))
  {
    return;
  }

  /* Tick fire cooldown, damp recoil offset, and fire when the trigger is pressed. */
  if (D_801F7D70)
  {
    D_801F7D70--;
  }
  *((f32 *) (cannon + 0xB4)) *= *((const f32 *) (&D_801E673C));
  *((f32 *) (cannon + 0xB8)) *= *((const f32 *) (&D_801E673C));
  *((f32 *) (cannon + 0xBC)) *= *((const f32 *) (&D_801E673C));
  if (((D_8029F394 < SHOOTING_GALLERY_MAX_PROJECTILES) && (!D_801F7D70)) && (*((&D_801FAAC6) + (D_80202218 * PHYSICS_CONTROLLER_RECORD_STRIDE))))
  {
    u8 *player;
    scratchVec[0] = (scratchVec[1] = 0.0f);
    recoilPtr = (const f32 *) (&D_801E6738);
    scratchVec[2] = *recoilPtr;
    func_801499A0(scratchVec, scratchVec, playerQuat);
    player = (u8 *) playerQuat - 0x9C;
    *((f32 *) (cannon + 0xB4)) += scratchVec[0];
    *((f32 *) (cannon + 0xB8)) += D_801F7D68;
    ((Vec3F *)(cannon + 0xB4))->z += D_801F7D6C;
    D_801F7D84++;
    D_801F7D70 = D_801E6744;
    projectile = func_801A9054(player, SHOOTING_GALLERY_PROJECTILE_TYPE, 0);
    if (projectile)
    {
      /* Occasionally swap the cannonball for one of three novelty projectile models. */
      switch (func_80147000(15))
      {
        case 0:
        {
          u8 **modelNamePtr = &D_801F0118;
          func_80151FD0(projectile + 0xD0, func_80139CA0(*modelNamePtr), *modelNamePtr, 1);
        }
          *((f32 *) ((*((u8 **) (projectile + 0xE0))) + 0x70)) = (*((f32 *) (projectile + 0x38)) = D_801EE1F8);
          *((f32 *) (projectile + 0xC0)) = *((const f32 *) (&D_80100CAC));
          func_80178134(25, projectile + 0x3C, 80, (s16) (func_80147000(24) + 116));
          break;

        case 1:
        {
          u8 **modelNamePtr = &D_801F011C;
          func_80151FD0(projectile + 0xD0, func_80139CA0(*modelNamePtr), *modelNamePtr, 1);
        }
          *((f32 *) ((*((u8 **) (projectile + 0xE0))) + 0x70)) = (*((f32 *) (projectile + 0x38)) = D_801EE248);
          func_80178134(19, projectile + 0x3C, 80, (s16) (func_80147000(24) + 116));
          break;

        case 2:
        {
          u8 **modelNamePtr = &D_801F0120;
          func_80151FD0(projectile + 0xD0, func_80139CA0(*modelNamePtr), *modelNamePtr, 1);
        }
          shotMeshScale = (f32 *) ((*((u8 **) (projectile + 0xE0))) + 0x70);
          *((f32 *) (projectile + 0x38)) = D_801EE298;
          *shotMeshScale = D_801EE298;
          func_80178134(21, projectile + 0x3C, 80, (s16) (func_80147000(24) + 116));
          break;

      }

      /* Play cannon fire sound and spawn muzzle flash, smoke ring, and directional blast. */
      func_80178134(27, projectile + 0x3C, 80, (s16) (func_80147000(24) + 116));
      func_801B66D4(SHOOTING_GALLERY_MUZZLE_PARTICLE, projectile - (-0x3C), &D_801ED3C4, 0, 0);
      i = 0;
      {
        f32 *velVec = &D_801F7D64;
        f32 *posVec;
        f32 zero;
        yawDelta = (f32) (func_80147000(62) / 10);
        ;
        ;
        posVec = &D_801F7D58;
        zero = 0.0f;
        for (i = 0; i < 5; i++)
        {
          do
          {
            { f64 d = zero; zero = d; }
            ((Vec3F *) velVec)->x = (((Vec3F *) velVec)->z = zero);
            ((Vec3F *) velVec)->y = *((const f32 *) (&D_80100CB0));
            func_8014915C(velVec, velVec, (f32) (yawDelta + (((i * 2) * D_80100CB8) / D_80100CC0)), 2);
            func_801499A0(velVec, velVec, D_80290374);
            posVec[0] = velVec[0] + (*((f32 *) (projectile + 0x3C)));
            posVec[1] = D_801F7D68 + (*((f32 *) (projectile + 0x40)));
            posVec[2] = D_801F7D6C + (*((f32 *) (projectile + 0x44)));
            object = func_801B66D4(SHOOTING_GALLERY_SMOKE_PARTICLE, posVec, velVec, 0, 0);
          }
          while (0);
          if (object)
          {
            *((s16 *) (object + 0x24)) = 5;
            *((f32 *) ((*((u8 **) (object + 0xD0))) + 0x18)) = *((const f32 *) (&D_80100CB4));
            *((f32 *) (object + 0x70)) = *((const f32 *) (&D_80100CB4));
          }
        }

        for (i = 0; i < 10; i++)
        {
          if (1)
          {
            *((Vec3F *) velVec) = *((Vec3F *) (projectile + 0x60));
            velVec[0] += (f32) (func_80147000(15) - 7);
            velVec[1] += (f32) (func_80147000(15) - 7);
            velVec[2] += (f32) (func_80147000(15) - 7);
            if (i < 5)
            {
              object = func_801B66D4(SHOOTING_GALLERY_SMOKE_PARTICLE, projectile + 0x3C, velVec, 0, 0);
              if (object)
              {
                *((s16 *) (object + 0x24)) = 8;
                *((f32 *) ((*((u8 **) (object + 0xD0))) + 0x18)) = *((const f32 *) (&D_80100CC8));
                *((f32 *) (object + 0x70)) = *((const f32 *) (&D_80100CC8));
              }
            }
            else
            {
              object = func_801B66D4(SHOOTING_GALLERY_SPARK_PARTICLE, projectile + 0x3C, velVec, 0, 0);
              if (object)
              {
                *((u32 *) (object + 0x28)) &= 0xFF7FFFFF;
                *((f32 *) ((*((u8 **) (object + 0xD0))) + 0x18)) = *((const f32 *) (&D_80100CC8));
                *((f32 *) (object + 0x70)) = *((const f32 *) (&D_80100CC8));
              }
            }
          }
        }

      }
    }
  }

  /* Ramp angular speeds of the three target-row tracks over elapsed time. */
  {
    f32 elapsed;
    object = func_8017DBA0(SHOOTING_GALLERY_ROW1_TRACK_ID);
    elapsed = ((f32) D_802004E0) / (*((const f32 *) (&D_80100CCC)));
    *((f32 *) (*((u8 **) (object + 0x2C)))) = (((f64) elapsed) < D_80100CD0) ? ((f32) ((elapsed * D_80100CD8) + D_80100CE0)) : (*((const f32 *) (&D_80100CE8)));
  }
  {
    f32 elapsed;
    object = func_8017DBA0(SHOOTING_GALLERY_ROW2_TRACK_ID);
    elapsed = ((f32) D_802004E0) / (*((const f32 *) (&D_80100CEC)));
    *((f32 *) (*((u8 **) (object + 0x2C)))) = (((f64) elapsed) < D_80100CF0) ? ((f32) ((-(elapsed + D_80100CF8)) * D_80100D00)) : (*((const f32 *) (&D_80100D08)));
  }
  {
    f32 elapsed;
    object = func_8017DBA0(SHOOTING_GALLERY_ROW3_TRACK_ID);
    elapsed = ((f32) D_802004E0) / (*((const f32 *) (&D_80100D0C)));
    *((f32 *) (*((u8 **) (object + 0x2C)))) = (((f64) elapsed) < D_80100D10) ? ((f32) ((elapsed + D_80100D18) * D_80100D20)) : (*((const f32 *) (&D_80100D28)));
  }

  /* Apply vertical turret rumble and update final player seat position. */
  *((f32 *) (cannon + 0xB8)) += D_801F7D78;
  {
    f32 *seatOffset = &D_801F7D64;
    seatOffset[0] = 0;
    seatOffset[1] = *((const f32 *) (&D_80100D2C));
    seatOffset[2] = 0;
    func_801499A0(seatOffset, seatOffset, D_80290374);
    (&D_80290310)[-1] = seatOffset[0] + (*((f32 *) (cannon + 0xB4)));
    D_80290310 = seatOffset[1] + (*((f32 *) (cannon + 0xB8)));
    D_80290314 = seatOffset[2] + (*((f32 *) (cannon + 0xBC)));
  }
}

/* Clear the cutscene event flag D_8028FB7C and reset the player/ball state
 * (func_8011BCB8). While the ball recovery timer D_8029F468 runs and no
 * camera handoff or transition is active, keep the camera at its current
 * eye D_8028F914 and point it at the focus D_8028FA00, still, over 60 frames. */
void func_8011BB3C(void) {
    s32 *cutsceneFlag = &D_8028FB7C;

    *cutsceneFlag = 0;
    func_8011BCB8();
    if (D_8029F468 != 0 && D_8028FAF8 == 0 && D_8028FAF4 == 0) {
        f32 eyeX = *(f32 *)D_8028F914;
        f32 eyeY = D_8028F918;

        func_80162EAC(eyeX, eyeY, D_8028F91C, (s32)((u8 *)cutsceneFlag - 0x17C) /* D_8028FA00 */, (s32)&D_801ED3C4, 60, 0);
    }
}

/* Per-frame camera update for a scripted rise: if no camera target is set and
 * no transition runs, re-aim the camera (func_80162EAC) at its current eye
 * point over 60 frames, then move the eye's Z by D_80100D30 each frame.
 * Once D_8029F9B4 passes D_80100D38, func_80128DF8(5, 1, 1) is triggered. */
void func_8011BBD0(void) {
    s32 *cameraTarget;

    if (D_8029F468 != 0) {
        cameraTarget = &D_8028FAF8;
        if (*cameraTarget == 0 && D_8028FAF4 == 0) {
            f32 eyeX = *(f32 *)D_8028F914;
            f32 eyeY = D_8028F918;

            /* cameraTarget - 0xF8 is D_8028FA00, the camera's target position */
            func_80162EAC(eyeX, eyeY, D_8028F91C, (s32)((u8 *)cameraTarget - 0xF8), (s32)&D_801ED3C4, 60, 0);
        }
    }
    if (D_8029F468 != 0) {
        *(f32 *)&D_8028F91C = *(f32 *)&D_8028F91C + D_80100D30;
    }
    func_8011BCB8();
    if (D_8029F9B4 > D_80100D38) {
        func_80128DF8(5, 1, 1);
    }
}

/*
 * Hide the player: clear D_802902FE and shrink the player model's XYZ scale (D_80290394..39C) to zero.
 * If the camera (mode D_801EC740) was in mode 1 with the gameplay timer D_8028FBF4 expired, it switches
 * to mode 2 and follows the ball's position (D_8029F9AC) and velocity (D_8029F9D0). If the ball is not
 * held by the player (D_802902D8), the player enters state 3 (func_80167604, player_set_state).
 */
void func_8011BCB8(void) {
    f32 zero = 0.0f;
    u8 *ballPosition;

    D_802902FE = 0;
    D_8029039C = zero;
    D_80290398 = zero;
    D_80290394 = zero;
    if (D_801EC740 == 1 && D_8028FBF4 == 0) {
        ballPosition = (u8 *)&D_8029F9AC;
        D_8028FAC8 = ballPosition;
        D_8028FAD0 = ballPosition + 0x24;
        D_801EC740 = 2;
    }
    if (D_8029F9A4 != (s32)&D_802902D8) {
        func_80167604(3);
    }
}

/* Restore the player for play: D_802902FE = 0xFF, point the camera target back at the
 * player's position (D_8029030C) and velocity (D_80290330), reset the three floats at
 * D_80290394 to D_80100D3C, and resume camera following (func_801364D0) if it was
 * off (D_801EC740). */
void func_8011BD60(void) {
    f32 value = D_80100D3C;
    s32 wasFollowing = D_801EC740;
    f32 *scale = &D_80290394;

    D_802902FE = 0xFF;
    D_8028FAC8 = (u8 *)scale - 0x88; /* player position */
    D_8028FAD0 = (u8 *)scale - 0x64; /* player velocity */
    D_8029039C = value;
    D_80290398 = value;
    *scale = value;
    if (wasFollowing == 0) {
        func_801364D0();
    }
    D_801EC740 = 1;
}

extern u8 D_801E7584;
extern s32 D_801F7D7C;
extern s32 D_801E6764;
extern s32 D_801E6770;
extern s32 D_801E676C;
extern s32 D_801E6778;
extern s32 D_801E6768;
extern s32 D_801E6774;
extern s16 D_8029011E;
extern u16 D_8029011C;
extern u8 *D_802903B0;
extern f64 D_80100D58;
extern s32 D_80100D40;
extern u8 D_802904D4;
extern const f32 D_80100D64;
extern s32 func_8013FCDC(s32, s32, s32);
extern void func_80179ECC(void *);
extern s32 D_80100D48;
extern s32 D_80100D54;
extern const f32 D_80100D68;
extern const f32 D_80100D6C;
extern const f32 D_80100D70;
extern const f32 D_80100D74;
extern const f32 D_801E6754;
extern const f32 D_80100D78;
extern const f32 D_80100D7C;
extern const f32 D_80100D80;
extern const f32 D_801E675C;
extern const f32 D_801E6758;
extern const f32 D_80100D84;
void func_8018315C(void *, Vec3F *, f32);
void func_80182F64(void *platform, f32 x, f32 y, f32 z, s32 waitFrames);

/* Update Atlantis bonus bounds and initialize, trigger and wrap its moving platforms. */
void func_8011BDE0(void)
{
  u8 *supportPlatform;
  u8 *platform;
  u8 *shuttleParent;
  u8 *pushState;
  u8 *parentOrPath;
  Vec3F initialPosition;
  f32 *firstClampZ;
  f32 *secondClampZ;
  f32 zBound;
  f32 pushDamping;
  if ((D_802903AC[9] == 3) && ((D_801E7584 & 1) == 0))
  {
    D_801F7D7C = D_801F7D7C + 1;
    if (D_801F7D7C >= BONUS_FAILURE_DELAY)
    {
      func_80128DF8(5, 0, 0);
    }
  }
  firstClampZ = (f32 *) (&D_8028F91C);
  zBound = (f32) D_801E6764;
  if (zBound <= (*firstClampZ))
  {
    *firstClampZ = zBound;
  }
  else
  {
    zBound = (f32) D_801E6770;
    if ((*firstClampZ) <= zBound)
    {
      *firstClampZ = zBound;
    }
  }
  secondClampZ = &D_8028FA08;
  if (((f32) D_801E676C) <= (*secondClampZ))
  {
    *secondClampZ = (f32) D_801E676C;
    D_8028FB3C = 0.0f;
    D_8028FB40 = 2;
  }
  if ((*secondClampZ) <= ((f32) D_801E6778))
  {
    *secondClampZ = (f32) D_801E6778;
    D_8028FB3C = 0.0f;
    D_8028FB40 = 2;
  }
  if ((((f32) D_801E6768) < D_80290314) || (D_80290314 < ((f32) D_801E6774)))
  {
    func_80128DF8(5, 0, 0);
  }
  if (D_8029011E != 0)
  {
    D_8029011C = D_8029011C + 1;
  }
  D_8028FB7C = 0;
  if (((*((s32 *) D_802903B0)) != 0) && (D_80290334 < 0.0f))
  {
    D_80290330 = D_80290330 * (*((f64 *) (((u8 *) (&D_80100D58)) + 4)));
    D_80290338 = D_80290338 * (*((f64 *) (((u8 *) (&D_80100D58)) + 4)));
  }
  if (D_802004E0 == 0)
  {
    D_801F7D7C = 0;
    func_80155A44(&D_80100D40);
    for (platform = *((u8 **) (&D_802904D4)); platform != (&D_802904D4); platform = *((u8 **) platform))
    {
      if (((u16) ((*((s16 *) (platform + BONUS_PLATFORM_ROLE))) - 1)) < 2)
      {
        *((s32 *) (platform + PLATFORM_FLAGS)) &= ~0x20000;
        initialPosition = *((Vec3F *) (platform + PLATFORM_POSITION));
        if ((*((s16 *) (platform + BONUS_PLATFORM_ROLE))) == BONUS_PLATFORM_PUSH)
        {
          pushState = (u8 *) func_8013FCDC(BONUS_PUSH_STATE_BYTES, 1, (s32) (&D_80100D48));
          *((u8 **) (platform + BONUS_PLATFORM_PUSH_STATE)) = pushState;
          pushState[BONUS_PUSH_ENABLED] = 1;
          func_8018315C(platform, &initialPosition, 0.0f);
          *((f32 *) (platform + PLATFORM_MAX_SPEED)) = D_80100D64;
        }
        else
          if ((*((s16 *) (platform + BONUS_PLATFORM_ROLE))) == BONUS_PLATFORM_SHUTTLE_CHILD)
        {
          shuttleParent = (u8 *) func_8013FCDC(BONUS_PLATFORM_BYTES, 1, (s32) (&D_80100D54));
          *((s16 *) (shuttleParent + BONUS_PLATFORM_RENDER_TYPE)) = BONUS_SHUTTLE_RENDER_TYPE;
          *((s32 *) (shuttleParent + PLATFORM_FLAGS)) |= 0x80;
          func_80142700(shuttleParent + BONUS_PLATFORM_RENDER_OBJECT, 0);
          *((f32 *) (shuttleParent + PLATFORM_DAMPING)) = D_80100D68;
          func_80179ECC(shuttleParent);
          *((s16 *) (shuttleParent + BONUS_PLATFORM_ROLE)) = BONUS_PLATFORM_SHUTTLE_PARENT;
          *((f32 *) (shuttleParent + PLATFORM_MAX_SPEED)) = D_80100D64;
          func_80182F64(shuttleParent, initialPosition.x, initialPosition.y, 600.0f, 0);
          func_80182F64(shuttleParent, initialPosition.x, initialPosition.y, -4900.0f, 0);
          *((f32 *) ((*((u8 **) (shuttleParent + PLATFORM_PATH))) + PLATFORM_PATH_ACCELERATION)) = D_80100D6C;
          *((u8 **) (platform + PLATFORM_PARENT)) = shuttleParent;
          func_80182F64(platform, 0.0f, 0.0f, 0.0f, BONUS_SHUTTLE_WAIT);
          func_80182F64(platform, 0.0f, -30.0f, 0.0f, BONUS_SHUTTLE_RETURN_WAIT);
          func_8018315C(shuttleParent, &initialPosition, 0.0f);
          func_8018315C(platform, (Vec3F *) (&D_801ED3C4), 0.0f);
          *((s16 *) (platform + BONUS_PLATFORM_ROLE)) = BONUS_PLATFORM_ORDINARY;
          *((f32 *) ((*((u8 **) (platform + PLATFORM_PATH))) + PLATFORM_PATH_ACCELERATION)) = D_80100D70;
          *((f32 *) (platform + PLATFORM_MAX_SPEED)) = D_80100D74;
        }
      }
    }

    func_80155AE4(&D_80100D40);
  }
  supportPlatform = *((u8 **) (D_802903B0 + BONUS_PLAYER_SUPPORT_PLATFORM));
  if ((supportPlatform != 0) && ((*((u8 **) (supportPlatform + PLATFORM_PARENT))) != 0))
  {
    parentOrPath = *((u8 **) (supportPlatform + PLATFORM_PARENT));
    if ((*((s16 *) (parentOrPath + BONUS_PLATFORM_ROLE))) == BONUS_PLATFORM_SHUTTLE_PARENT)
    {
      parentOrPath = *((u8 **) (supportPlatform + PLATFORM_PATH));
      if ((*((s16 *) (parentOrPath + PLATFORM_PATH_WAIT))) < BONUS_SHUTTLE_TRIGGER_THRESHOLD)
      {
        *((s16 *) (parentOrPath + PLATFORM_PATH_WAIT)) = BONUS_SHUTTLE_TRIGGER_WAIT;
      }
    }
  }
  for (platform = *((u8 **) (&D_802904D4)); platform != (&D_802904D4); platform = *((u8 **) platform))
  {
    pushDamping = D_801E6754;
    if ((*((s16 *) (platform + BONUS_PLATFORM_ROLE))) == BONUS_PLATFORM_PUSH)
    {
      *((f32 *) (platform + BONUS_PLATFORM_VELOCITY_Z)) = D_80100D78 / pushDamping;
      if ((*((f32 *) (platform + PLATFORM_POSITION_Z))) > D_80100D7C)
      {
        *((f32 *) (platform + PLATFORM_POSITION_Z)) = D_80100D80;
      }
      do
      {
        *((f32 *) ((*((u8 **) (platform + BONUS_PLATFORM_PUSH_STATE))) + BONUS_PUSH_STRENGTH)) = D_801E675C;
        *((f32 *) (platform + PLATFORM_DAMPING)) = pushDamping;
      }
      while (0);
    }
    if ((*((s16 *) (platform + BONUS_PLATFORM_ROLE))) == BONUS_PLATFORM_SHUTTLE_PARENT)
    {
      *((f32 *) ((*((u8 **) ((*((u8 **) (platform + PLATFORM_PATH))) + 0))) + 4)) = *((f32 *) (platform + PLATFORM_POSITION_Y));
      *((f32 *) ((*((u8 **) ((*((u8 **) (platform + PLATFORM_PATH))) + 4))) + 4)) = *((f32 *) (platform + PLATFORM_POSITION_Y));
      *((f32 *) (platform + BONUS_PLATFORM_VELOCITY_Z)) = D_801E6758;
      *((f32 *) (platform + BONUS_PLATFORM_VELOCITY_Z)) = D_80100D84 / (*((f32 *) (platform + BONUS_PLATFORM_VELOCITY_Z)));
      if ((*((f32 *) (platform + PLATFORM_POSITION_Z))) < D_80100D80)
      {
        *((f32 *) (platform + PLATFORM_POSITION_Z)) = D_80100D7C;
      }
      *((f32 *) (platform + PLATFORM_DAMPING)) = D_801E6758;
    }
  }

}

/* Update level 39's platform interaction, timed effects, player alignment and camera handoff. */
void func_8011C36C(void) {
    u8 *primaryPlatform = func_8017DBA0(LEVEL39_PLATFORM_PRIMARY);
    u8 *companionPlatform = func_8017DBA0(LEVEL39_PLATFORM_COMPANION);
    s32 *cameraFlags;

    if (D_802004E0 < LEVEL39_FIXED_CAMERA_FRAMES) {
        D_8028FA00 = D_80100D88;
        D_8028FA04 = D_80100D8C;
        D_8028FA08 = D_80100D90;
        if (D_802004E0 == 1) {
            *(Vec3F *)D_8028F914 = D_8028FAFC;
        }
    }
    cameraFlags = &D_8028F908;
    *cameraFlags &= ~LEVEL39_CAMERA_CLEARED_FLAG;
    if (*(s16 *)(D_802903AC + PLAYER_STATE_CURRENT_OFFSET) == LEVEL39_PLAYER_INTERACTION_STATE) {
        f32 platformZ = *(f32 *)(primaryPlatform + PLATFORM_POSITION_Z);
        void *effect;

        D_801F7D80++; if (D_80100D94 < platformZ) {
            *(f32 *)(primaryPlatform + PLATFORM_POSITION_Z) = platformZ - (platformZ + D_80100D98) / D_80100D9C;
        }
        if (D_801F7D80 == LEVEL39_FIRST_EFFECT_FRAME || D_801F7D80 == LEVEL39_SECOND_EFFECT_FRAME) {
            f32 recoiledZ;
            s32 interactionFrame;

            effect = func_801A9054(&D_802902D8, LEVEL39_INTERACTION_EFFECT, 0);
            recoiledZ = *(f32 *)(primaryPlatform + PLATFORM_POSITION_Z) + D_801E677C;
            interactionFrame = D_801F7D80;
            *(f32 *)(primaryPlatform + PLATFORM_POSITION_Z) = recoiledZ;
            if (interactionFrame == LEVEL39_FIRST_EFFECT_FRAME) {
                f32 *followActorVelocityX = &D_80299A40;

                *followActorVelocityX = *followActorVelocityX + D_80100DA0;
            } else {
                f32 *followActorVelocityX = &D_80299A40;

                *followActorVelocityX = *followActorVelocityX - D_80100DA4;
            }
            if (effect != 0) {
                f32 effectZ = *(f32 *)((u8 *)effect + LEVEL39_EFFECT_POSITION_Z);
                f32 effectVelocityY = *(f32 *)((u8 *)effect + EFFECT_VELOCITY_Y_OFFSET);

                effectZ -= D_80100DA8;
                effectVelocityY += D_80100DAC;
                *(f32 *)((u8 *)effect + LEVEL39_EFFECT_POSITION_Z) = effectZ;
                *(f32 *)((u8 *)effect + EFFECT_VELOCITY_Y_OFFSET) = effectVelocityY;
            }
        }
        if (D_801F7D80 >= LEVEL39_CAMERA_HANDOFF_FRAME) {
            if (D_801F7D80 == LEVEL39_CAMERA_HANDOFF_FRAME) {
                u8 *followActor = D_802999E8;
                u8 *cameraPosition = (u8 *)D_8028F914;

                func_80197794(followActor, LEVEL39_FOLLOW_ACTOR_ACTION, 1);
                D_8028FAC8 = followActor + ACTOR_POSITION;
                *(u8 **)((u8 *)&D_8028FAC8 + LEVEL39_FOLLOW_VELOCITY_FROM_POSITION) = followActor + ACTOR_VELOCITY;
                *(Vec3F *)((u8 *)&D_8028FAC8 + LEVEL39_SAVED_CAMERA_FROM_FOLLOW_POSITION) = *(Vec3F *)cameraPosition;
            }
            D_8028FAF8 = 1;
        }
        {
            f32 *playerTargetYaw = &D_80290360;
            Vec3F playerTarget;

            *playerTargetYaw = D_80100DB0;
            playerTarget = *(Vec3F *)(primaryPlatform + PLATFORM_POSITION);
            playerTarget.y += D_80100DB4;
            playerTarget.z += D_80100DB8;
            if (D_801F7D80 >= LEVEL39_FIRST_EFFECT_FRAME) {
                D_80290314 = *(f32 *)(primaryPlatform + PLATFORM_POSITION_Z) + D_80100DB8;
            } else {
                func_80149398((u8 *)playerTargetYaw - LEVEL39_PLAYER_POSITION_FROM_TARGET_YAW, (u8 *)playerTargetYaw - LEVEL39_PLAYER_POSITION_FROM_TARGET_YAW, 0.7f, &playerTarget, D_80100DBC);
            }
        }
    } else {
        u8 *playerPosition = D_8029030C;

        if (func_80148EBC(playerPosition, (s32)(primaryPlatform + PLATFORM_POSITION)) < D_801E6780) {
            f32 zero = 0.0f;

            D_801F7D80 = 0;
            D_80290338 = zero;
            D_80290334 = zero;
            D_80290330 = zero;
            *(s16 *)(D_802903AC + PLAYER_STATE_CURRENT_OFFSET) = LEVEL39_PLAYER_INTERACTION_STATE;
            func_80133998(playerPosition - ACTOR_POSITION, LEVEL39_PLAYER_INTERACTION_ANIMATION, 0, 0, zero);
            D_80290300 &= ~LEVEL39_PLAYER_CLEARED_FLAGS;
        }
    }
    *(f32 *)(companionPlatform + PLATFORM_POSITION_Z) = *(f32 *)(primaryPlatform + PLATFORM_POSITION_Z);
}
