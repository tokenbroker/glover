#ifndef MUS_SONG_H
#define MUS_SONG_H

/* func_801C0694: MusStartSong.
 * D_802AB040: channel array; D_802AB058: next playback handle.
 * func_801C2A84: relocate nonzero offsets relative to a base.
 * func_801C28A0: select a song channel.
 * func_801C2768: reset a channel, preserving its allocated-voice flag.
 * func_801C1054: queue a resume command for the handle's channels.
 * Song header words 1..5 are relocatable pointers; words 1..3 point to
 * per-track note, volume and pitch stream tables. Accessed as s32 words.
 */
enum MusSongLayout {
    MUS_SONG_TRACK_COUNT_WORD = 0,
    MUS_SONG_VOLUME_STREAMS_WORD = 2,
    MUS_SONG_PITCH_STREAMS_WORD = 3,
    MUS_SONG_HEADER_POINTER_COUNT = 5,
    MUS_SONG_UNRELOCATED_LIMIT = 0x400,
    MUS_CH_PLAYBACK_HANDLE = 0x44,
    MUS_CH_PITCH_STREAM_START = 0x84,
    MUS_CH_VOLUME_STREAM_START = 0x88
};

/* func_801C08E4: mus_start_effect_ex; returns a playback handle or zero.
 * Restart requests reuse the first channel with the same effect ID.
 * Otherwise an idle channel wins; stealing requires strictly lower priority,
 * and equal-priority candidates retain the first channel encountered.
 * func_801C2B24: mus_start_effect_on_channel; resets channel state and assigns
 * effect ID, volume/pan scales, priority, sequence and a fresh handle.
 * D_802AB038: channel count; D_802AB040: 0x134-byte channel array;
 * D_802AB048: per-effect default-priority table. All are runtime BSS globals.
 * MusChannelOffsets describes the channel fields; volume/pan scales use
 * 128 for unity. Preserve their raw access widths and shared declarations.
 * N64 symbol renaming is unsupported; descriptive names are recorded here.
 */
enum MusEffectStartConstants {
    MUS_EFFECT_DEFAULT_PRIORITY = -1,
    MUS_EFFECT_INVALID_HANDLE = 0,
    MUS_EFFECT_SONG_ID = 0
};

/* func_801C2768 (mus_reset_channel) preserves MUS_CH_VOICE_ACTIVE.
 * D_802AB04C is the video refresh rate in Hz; D_802AB060 is the current
 * sample-bank address. The initial time step is 96 ticks/second with
 * eight fractional bits. Raw accesses retain the shared field types.
 * D_8010C1E8: initial cached pitch, 99.9f (forces the first pitch update).
 * D_8010C1EC: default decay slope, 1/255; D_8010C1F0: release slope, 1/15.
 */
enum MusChannelResetOffsets {
    MUS_CH_CACHED_PITCH = 0x28,          /* f32 */
    MUS_CH_ATTACK_SLOPE = 0x58,          /* f32 */
    MUS_CH_DECAY_SLOPE = 0x5C,           /* f32 */
    MUS_CH_RELEASE_SLOPE = 0x60,         /* f32 */
    MUS_CH_PITCH_STREAM_SCALE = 0x6C,    /* f32: semitones per stream unit */
    MUS_CH_HANDLE_TEMPO = 0x94,          /* u16: 128 is unity */
    MUS_CH_VOLUME_STREAM_COUNTDOWN = 0x9E, /* u16 */
    MUS_CH_PITCH_STREAM_COUNTDOWN = 0xA0, /* u16 */
    MUS_CH_BASE_TIME_STEP = 0xA4,        /* u16: before handle tempo scaling */
    MUS_CH_ENVELOPE_UPDATE_PERIOD = 0xBB, /* u8 */
    MUS_CH_ATTACK_VOLUME = 0xBD,         /* u8 */
    MUS_CH_SUSTAIN_VOLUME = 0xBE,        /* u8 */
    MUS_CH_ATTACK_DURATION = 0xC2,       /* u8 */
    MUS_CH_DECAY_DURATION = 0xC3,        /* u8 */
    MUS_CH_RELEASE_DURATION = 0xC4       /* u8 */
};

enum MusChannelResetConstants {
    MUS_DEFAULT_FIXED_TICKS_PER_SECOND = 0x6000,
    MUS_VOLUME_CACHE_INVALID = 0xFFFF,
    MUS_BYTE_CACHE_INVALID = 0xFF,
    MUS_CHANNEL_VOLUME_MAX = 0x7F,
    MUS_CHANNEL_PAN_CENTER = 0x40,
    MUS_HANDLE_SCALE_UNITY = 0x80,
    MUS_HANDLE_SCALE_SHIFT = 7,
    MUS_HANDLE_TEMPO_MAX = 256,
    MUS_DEFAULT_DECAY_DURATION = 0xFF,
    MUS_DEFAULT_RELEASE_DURATION = 0xF
};

/* func_801C1C1C: mus_apply_pitch, sends changed channel pitch to the voice.
 * D_8010C180 is the f64 semitone-to-octave factor, 1/12.
 * func_801C2314: mus_pitch_ratio_from_octaves; func_801CBD00: alSynSetPitch.
 * D_802AB03C: voice array; D_802AB2C8: synthesizer state.
 * Pitch ratios above 2.0 are clamped and silence the channel's note volume.
 * Symbol renaming is unavailable for N64; retain the address names.
 */
enum MusPitchOffsets {
    MUS_CH_STREAM_PITCH = 0x24, /* f32: scaled pitch-stream offset in semitones */
    MUS_CH_SLIDE_DURATION = 0xB4    /* u8: ticks; zero disables portamento */
};

/* func_801C0A2C: MusStop(flags, speed). Fades out every playing channel of
 * the selected kinds over `speed` updates; a paused channel stops at once.
 * func_801C0B00 counts playing channels with the same flags.
 */
enum MusStopFlags {
    MUS_FLAG_EFFECTS = 1, /* channels playing a sound effect (effect ID != 0) */
    MUS_FLAG_SONGS = 2    /* channels playing a song (effect ID == 0) */
};

/* 8-byte command in the player's FIFO (D_802AB080), queued by func_801C12A0
 * and run on the audio thread by func_801C1228 (__MusIntFifoProcessCommand).
 * func_801C102C / func_801C1054 queue pause / unpause of a playback handle;
 * func_801C1080 (MusSetFxType) records the effect preset in D_802AB06C and
 * queues the change.
 * func_801C10B4 (MusSetSongFxChange): D_802AB068 is the song-fx-change flag;
 * while it is 1, a song's set-effect command (func_801C02BC) applies its preset.
 * func_801C2BB0: __MusIntHandleSetFlag(handle, clearMask, setMask) on every
 * channel playing that handle. func_801C3FC0: apply effect preset `index`. */
typedef struct MusFifoCommand {
    /* 0x0 */ u8 type; /* MusFifoCommandType */
    /* 0x4 */ s32 data; /* playback handle or effect preset index */
} MusFifoCommand; /* size = 0x8 */

enum MusFifoCommandType {
    MUS_FIFO_PAUSE = 0,
    MUS_FIFO_UNPAUSE = 1,
    MUS_FIFO_SET_FX_PRESET = 2
};

#endif
