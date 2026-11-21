# Unmatched library candidates

Survey only; no source or symbol renames. Every entry was absent from the saved 243-entry 100% baseline and still has an INCLUDE_ASM target after cleanup.

## References and method

- [decompals/ultralib](https://github.com/decompals/ultralib/tree/e24c836796df4bf520ff8b11a5c9d2cea3a66cbd), commit `e24c836796df4bf520ff8b11a5c9d2cea3a66cbd`.
- [cdlewis/snowboardkids2-decomp](https://github.com/cdlewis/snowboardkids2-decomp/tree/3b1bd5db108193528fd7dbe6facba02901218a13), commit `3b1bd5db108193528fd7dbe6facba02901218a13`; its actual ultralib submodule is [cdlewis/ultralib](https://github.com/cdlewis/ultralib/tree/c2badeea898d1de3b3722a2c038e5d9597a477b8). Snowboard's Makefile selects **2.0J libgultra_rom**, and its splat config and symbol list identify the corresponding library objects/functions. It uses patched library sources (for example explicit sirawwrite rodata and preserved assertion lines), so it is a source-shape reference, not proof that Glover uses 2.0J.

Compiled 203 upstream C reference files separately in /tmp, with KMC GCC 2.7.2 and the upstream 2.0I libgultra_rom profile: -O3, -mips3, -mgp32, -mfp32, -G0, -funsigned-char, assertions enabled, _FINALROM. Compared each unmatched target against reference function instruction words, masking relocation immediates and normalizing assembler daddiu address expansions to addiu. Trailing alignment nops were omitted. This found 96 strong candidates. Percentages below describe this limited instruction comparison, **not objdiff matches**; relocation destinations, data, literal addresses and full-ROM placement still need verification. Registers, non-relocated immediates and instruction order were retained.

**Likely version:** 2.0I libgultra_rom is the strongest working hypothesis. Enabled assertions combined with optimized code fit upstream's special I ROM configuration (later ROM versions define NDEBUG). The sirawwrite assertion line 52 agrees with the pre-J source adjustment, and C matrix routines also favor I/J over K/L's assembly implementations. Exact SDK revision remains unproven; do not assume all library objects share one revision or optimization profile. “I-ROM” in the table means this hypothesis, with confidence in identity higher than confidence in version. Many implementations are shared by I–L. Some targets contain sdc1/ldc1, so the game C build flags alone do not reproduce every prebuilt-library instruction.

Ambiguous normalized pairs were checked using their callers, hardware registers, assertion filename strings and globals. SI helpers connect to controller/EEPROM operations; PI helpers connect to PI DMA. D_801F4760 is the current VI context and D_801F4764 is next (the latter is updated by setters and swapped by the context routine).

## C reference candidates

| Glover function | Likely library function | Version | Confidence / evidence | Reference source |
| --- | --- | --- | --- | --- |
| `func_801C5224` | `guLookAtHilite` | I-ROM | High; 100.0% normalized words | [src/gu/lookathil.c](https://github.com/decompals/ultralib/blob/e24c836796df4bf520ff8b11a5c9d2cea3a66cbd/src/gu/lookathil.c) |
| `func_801C5300` | `guMtxF2L` | I-ROM | High; 100.0% normalized words | [src/gu/mtxutil.c](https://github.com/decompals/ultralib/blob/e24c836796df4bf520ff8b11a5c9d2cea3a66cbd/src/gu/mtxutil.c) |
| `func_801C5490` | `guMtxIdent` | I-ROM | High; 100.0% normalized words | [src/gu/mtxutil.c](https://github.com/decompals/ultralib/blob/e24c836796df4bf520ff8b11a5c9d2cea3a66cbd/src/gu/mtxutil.c) |
| `func_801C5580` | `guMtxCatF` | I-ROM | High; 100.0% normalized words | [src/gu/mtxcatf.c](https://github.com/decompals/ultralib/blob/e24c836796df4bf520ff8b11a5c9d2cea3a66cbd/src/gu/mtxcatf.c) |
| `func_801C5710` | `guMtxCatL` | I-ROM | High; 100.0% normalized words | [src/gu/mtxcatl.c](https://github.com/decompals/ultralib/blob/e24c836796df4bf520ff8b11a5c9d2cea3a66cbd/src/gu/mtxcatl.c) |
| `func_801C5784` | `guMtxXFML` | I-ROM | High; 100.0% normalized words | [src/gu/mtxcatl.c](https://github.com/decompals/ultralib/blob/e24c836796df4bf520ff8b11a5c9d2cea3a66cbd/src/gu/mtxcatl.c) |
| `func_801C5B90` | `guRotateF` | I-ROM | High; 100.0% normalized words | [src/gu/rotate.c](https://github.com/decompals/ultralib/blob/e24c836796df4bf520ff8b11a5c9d2cea3a66cbd/src/gu/rotate.c) |
| `func_801C5CEC` | `guRotate` | I-ROM | High; 100.0% normalized words | [src/gu/rotate.c](https://github.com/decompals/ultralib/blob/e24c836796df4bf520ff8b11a5c9d2cea3a66cbd/src/gu/rotate.c) |
| `func_801C5F20` | `guScaleF` | I-ROM | High; 100.0% normalized words | [src/gu/scale.c](https://github.com/decompals/ultralib/blob/e24c836796df4bf520ff8b11a5c9d2cea3a66cbd/src/gu/scale.c) |
| `func_801C5F80` | `guScale` | I-ROM | High; 100.0% normalized words | [src/gu/scale.c](https://github.com/decompals/ultralib/blob/e24c836796df4bf520ff8b11a5c9d2cea3a66cbd/src/gu/scale.c) |
| `func_801C61A0` | `guTranslateF` | I-ROM | High; 100.0% normalized words | [src/gu/translate.c](https://github.com/decompals/ultralib/blob/e24c836796df4bf520ff8b11a5c9d2cea3a66cbd/src/gu/translate.c) |
| `func_801C61F4` | `guTranslate` | I-ROM | High; 100.0% normalized words | [src/gu/translate.c](https://github.com/decompals/ultralib/blob/e24c836796df4bf520ff8b11a5c9d2cea3a66cbd/src/gu/translate.c) |
| `func_801C6550` | `osCreateThread` | I-ROM | High; 100.0% normalized words | [src/os/createthread.c](https://github.com/decompals/ultralib/blob/e24c836796df4bf520ff8b11a5c9d2cea3a66cbd/src/os/createthread.c) |
| `func_801C6FB0` | `osDestroyThread` | I-ROM | High; 100.0% normalized words | [src/os/destroythread.c](https://github.com/decompals/ultralib/blob/e24c836796df4bf520ff8b11a5c9d2cea3a66cbd/src/os/destroythread.c) |
| `func_801C7080` | `osGetTime` | I-ROM | High; 100.0% normalized words | [src/os/gettime.c](https://github.com/decompals/ultralib/blob/e24c836796df4bf520ff8b11a5c9d2cea3a66cbd/src/os/gettime.c) |
| `func_801C7110` | `osInitialize` | I-ROM | High; 100.0% normalized words | [src/os/initialize.c](https://github.com/decompals/ultralib/blob/e24c836796df4bf520ff8b11a5c9d2cea3a66cbd/src/os/initialize.c) |
| `func_801C7430` | `osRecvMesg` | I-ROM | High; 100.0% normalized words | [src/os/recvmesg.c](https://github.com/decompals/ultralib/blob/e24c836796df4bf520ff8b11a5c9d2cea3a66cbd/src/os/recvmesg.c) |
| `func_801C7560` | `osSendMesg` | I-ROM | High; 100.0% normalized words | [src/os/sendmesg.c](https://github.com/decompals/ultralib/blob/e24c836796df4bf520ff8b11a5c9d2cea3a66cbd/src/os/sendmesg.c) |
| `func_801C7690` | `osSetEventMesg` | I-ROM | High; 100.0% normalized words | [src/os/seteventmesg.c](https://github.com/decompals/ultralib/blob/e24c836796df4bf520ff8b11a5c9d2cea3a66cbd/src/os/seteventmesg.c) |
| `func_801C76F0` | `osSetThreadPri` | I-ROM | High; 100.0% normalized words | [src/os/setthreadpri.c](https://github.com/decompals/ultralib/blob/e24c836796df4bf520ff8b11a5c9d2cea3a66cbd/src/os/setthreadpri.c) |
| `func_801C77C0` | `osSetTimer` | I-ROM | High; 100.0% normalized words | [src/os/settimer.c](https://github.com/decompals/ultralib/blob/e24c836796df4bf520ff8b11a5c9d2cea3a66cbd/src/os/settimer.c) |
| `func_801C7860` | `osStartThread` | I-ROM | High; 100.0% normalized words | [src/os/startthread.c](https://github.com/decompals/ultralib/blob/e24c836796df4bf520ff8b11a5c9d2cea3a66cbd/src/os/startthread.c) |
| `func_801C7980` | `osStopThread` | I-ROM | High; 100.0% normalized words | [src/os/stopthread.c](https://github.com/decompals/ultralib/blob/e24c836796df4bf520ff8b11a5c9d2cea3a66cbd/src/os/stopthread.c) |
| `func_801C7AD4` | `__osTimerInterrupt` | I-ROM | High; 100.0% normalized words | [src/os/timerintr.c](https://github.com/decompals/ultralib/blob/e24c836796df4bf520ff8b11a5c9d2cea3a66cbd/src/os/timerintr.c) |
| `func_801C7C10` | `__osSetTimerIntr` | I-ROM | High; 100.0% normalized words | [src/os/timerintr.c](https://github.com/decompals/ultralib/blob/e24c836796df4bf520ff8b11a5c9d2cea3a66cbd/src/os/timerintr.c) |
| `func_801C7C70` | `__osInsertTimer` | I-ROM | High; 100.0% normalized words | [src/os/timerintr.c](https://github.com/decompals/ultralib/blob/e24c836796df4bf520ff8b11a5c9d2cea3a66cbd/src/os/timerintr.c) |
| `func_801C7D90` | `osVirtualToPhysical` | I-ROM | High; 100.0% normalized words | [src/os/virtualtophysical.c](https://github.com/decompals/ultralib/blob/e24c836796df4bf520ff8b11a5c9d2cea3a66cbd/src/os/virtualtophysical.c) |
| `func_801CE430` | `osAiSetNextBuffer` | I-ROM | High; 100.0% normalized words | [src/io/aisetnextbuf.c](https://github.com/decompals/ultralib/blob/e24c836796df4bf520ff8b11a5c9d2cea3a66cbd/src/io/aisetnextbuf.c) |
| `func_801CE4F0` | `osSpTaskLoad` | I-ROM | High; 99.2% normalized words | [src/io/sptask.c](https://github.com/decompals/ultralib/blob/e24c836796df4bf520ff8b11a5c9d2cea3a66cbd/src/io/sptask.c) |
| `func_801CE6FC` | `osSpTaskStartGo` | I-ROM | High; 100.0% normalized words | [src/io/sptask.c](https://github.com/decompals/ultralib/blob/e24c836796df4bf520ff8b11a5c9d2cea3a66cbd/src/io/sptask.c) |
| `func_801CE760` | `__osSpSetPc` | I-ROM | High; 100.0% normalized words | [src/io/spsetpc.c](https://github.com/decompals/ultralib/blob/e24c836796df4bf520ff8b11a5c9d2cea3a66cbd/src/io/spsetpc.c) |
| `func_801CE790` | `__osSpRawStartDma` | I-ROM | High; 100.0% normalized words | [src/io/sprawdma.c](https://github.com/decompals/ultralib/blob/e24c836796df4bf520ff8b11a5c9d2cea3a66cbd/src/io/sprawdma.c) |
| `func_801CE890` | `osSpTaskYield` | I-ROM | High; 100.0% normalized words | [src/io/sptaskyield.c](https://github.com/decompals/ultralib/blob/e24c836796df4bf520ff8b11a5c9d2cea3a66cbd/src/io/sptaskyield.c) |
| `func_801CE8B0` | `osSpTaskYielded` | I-ROM | High; 100.0% normalized words | [src/io/sptaskyielded.c](https://github.com/decompals/ultralib/blob/e24c836796df4bf520ff8b11a5c9d2cea3a66cbd/src/io/sptaskyielded.c) |
| `func_801CE910` | `osViGetCurrentFramebuffer` | I-ROM | High; 100.0% normalized words; call/global context disambiguates | [src/io/vigetcurrframebuf.c](https://github.com/decompals/ultralib/blob/e24c836796df4bf520ff8b11a5c9d2cea3a66cbd/src/io/vigetcurrframebuf.c) |
| `func_801CE950` | `__osViInit` | I-ROM | High; 100.0% normalized words | [src/io/vi.c](https://github.com/decompals/ultralib/blob/e24c836796df4bf520ff8b11a5c9d2cea3a66cbd/src/io/vi.c) |
| `func_801CEA60` | `osViGetNextFramebuffer` | I-ROM | High; 100.0% normalized words; call/global context disambiguates | [src/io/vigetnextframebuf.c](https://github.com/decompals/ultralib/blob/e24c836796df4bf520ff8b11a5c9d2cea3a66cbd/src/io/vigetnextframebuf.c) |
| `func_801CEAA0` | `osCreateViManager` | I-ROM | High; 100.0% normalized words | [src/io/vimgr.c](https://github.com/decompals/ultralib/blob/e24c836796df4bf520ff8b11a5c9d2cea3a66cbd/src/io/vimgr.c) |
| `func_801CEC38` | `viMgrMain` | I-ROM | High; 100.0% normalized words | [src/io/vimgr.c](https://github.com/decompals/ultralib/blob/e24c836796df4bf520ff8b11a5c9d2cea3a66cbd/src/io/vimgr.c) |
| `func_801CEDD0` | `osGetThreadPri` | I-ROM | High; 100.0% normalized words | [src/os/getthreadpri.c](https://github.com/decompals/ultralib/blob/e24c836796df4bf520ff8b11a5c9d2cea3a66cbd/src/os/getthreadpri.c) |
| `func_801CEE00` | `osViSetEvent` | I-ROM | High; 100.0% normalized words | [src/io/visetevent.c](https://github.com/decompals/ultralib/blob/e24c836796df4bf520ff8b11a5c9d2cea3a66cbd/src/io/visetevent.c) |
| `func_801CEE60` | `osViSetMode` | I-ROM | High; 100.0% normalized words | [src/io/visetmode.c](https://github.com/decompals/ultralib/blob/e24c836796df4bf520ff8b11a5c9d2cea3a66cbd/src/io/visetmode.c) |
| `func_801CEEB0` | `osViSetSpecialFeatures` | I-ROM | High; 100.0% normalized words | [src/io/visetspecial.c](https://github.com/decompals/ultralib/blob/e24c836796df4bf520ff8b11a5c9d2cea3a66cbd/src/io/visetspecial.c) |
| `func_801CF020` | `osViSetYScale` | I-ROM | High; 100.0% normalized words | [src/io/visetyscale.c](https://github.com/decompals/ultralib/blob/e24c836796df4bf520ff8b11a5c9d2cea3a66cbd/src/io/visetyscale.c) |
| `func_801CF070` | `osViSwapBuffer` | I-ROM | High; 100.0% normalized words | [src/io/viswapbuf.c](https://github.com/decompals/ultralib/blob/e24c836796df4bf520ff8b11a5c9d2cea3a66cbd/src/io/viswapbuf.c) |
| `func_801CF3B0` | `osViBlack` | I-ROM | High; 100.0% normalized words | [src/io/viblack.c](https://github.com/decompals/ultralib/blob/e24c836796df4bf520ff8b11a5c9d2cea3a66cbd/src/io/viblack.c) |
| `func_801CF410` | `__osSiRawReadIo` | I-ROM | High; 100.0% normalized words; call/global context disambiguates | [src/io/sirawread.c](https://github.com/decompals/ultralib/blob/e24c836796df4bf520ff8b11a5c9d2cea3a66cbd/src/io/sirawread.c) |
| `func_801CF4C0` | `__osSiRawWriteIo` | I-ROM | High; 100.0% normalized words | [src/io/sirawwrite.c](https://github.com/decompals/ultralib/blob/e24c836796df4bf520ff8b11a5c9d2cea3a66cbd/src/io/sirawwrite.c) |
| `func_801CF530` | `osContStartReadData` | I-ROM | High; 100.0% normalized words | [src/io/contreaddata.c](https://github.com/decompals/ultralib/blob/e24c836796df4bf520ff8b11a5c9d2cea3a66cbd/src/io/contreaddata.c) |
| `func_801CF5B8` | `osContGetReadData` | I-ROM | High; 100.0% normalized words | [src/io/contreaddata.c](https://github.com/decompals/ultralib/blob/e24c836796df4bf520ff8b11a5c9d2cea3a66cbd/src/io/contreaddata.c) |
| `func_801CF654` | `__osPackReadData` | I-ROM | High; 100.0% normalized words | [src/io/contreaddata.c](https://github.com/decompals/ultralib/blob/e24c836796df4bf520ff8b11a5c9d2cea3a66cbd/src/io/contreaddata.c) |
| `func_801CF710` | `__osSiRawStartDma` | I-ROM | High; 100.0% normalized words | [src/io/sirawdma.c](https://github.com/decompals/ultralib/blob/e24c836796df4bf520ff8b11a5c9d2cea3a66cbd/src/io/sirawdma.c) |
| `func_801CF7D0` | `__osSiCreateAccessQueue` | I-ROM | High; 100.0% normalized words; call/global context disambiguates | [src/io/siacs.c](https://github.com/decompals/ultralib/blob/e24c836796df4bf520ff8b11a5c9d2cea3a66cbd/src/io/siacs.c) |
| `func_801CF824` | `__osSiGetAccess` | I-ROM | High; 100.0% normalized words; call/global context disambiguates | [src/io/siacs.c](https://github.com/decompals/ultralib/blob/e24c836796df4bf520ff8b11a5c9d2cea3a66cbd/src/io/siacs.c) |
| `func_801CF890` | `__osSiRelAccess` | I-ROM | High; 100.0% normalized words; call/global context disambiguates | [src/io/siacs.c](https://github.com/decompals/ultralib/blob/e24c836796df4bf520ff8b11a5c9d2cea3a66cbd/src/io/siacs.c) |
| `func_801CF8C0` | `osContInit` | I-ROM | High; 100.0% normalized words | [src/io/controller.c](https://github.com/decompals/ultralib/blob/e24c836796df4bf520ff8b11a5c9d2cea3a66cbd/src/io/controller.c) |
| `func_801CFA5C` | `__osContGetInitData` | I-ROM | High; 100.0% normalized words; call/global context disambiguates | [src/io/controller.c](https://github.com/decompals/ultralib/blob/e24c836796df4bf520ff8b11a5c9d2cea3a66cbd/src/io/controller.c) |
| `func_801CFB10` | `__osPackRequestData` | I-ROM | High; 100.0% normalized words | [src/io/controller.c](https://github.com/decompals/ultralib/blob/e24c836796df4bf520ff8b11a5c9d2cea3a66cbd/src/io/controller.c) |
| `func_801CFBD0` | `osEepromProbe` | I-ROM | High; 100.0% normalized words | [src/io/conteepprobe.c](https://github.com/decompals/ultralib/blob/e24c836796df4bf520ff8b11a5c9d2cea3a66cbd/src/io/conteepprobe.c) |
| `func_801CFC50` | `osEepromWrite` | I-ROM | High; 100.0% normalized words | [src/io/conteepwrite.c](https://github.com/decompals/ultralib/blob/e24c836796df4bf520ff8b11a5c9d2cea3a66cbd/src/io/conteepwrite.c) |
| `func_801CFDD8` | `__osPackEepWriteData` | I-ROM | High; 100.0% normalized words | [src/io/conteepwrite.c](https://github.com/decompals/ultralib/blob/e24c836796df4bf520ff8b11a5c9d2cea3a66cbd/src/io/conteepwrite.c) |
| `func_801CFE9C` | `__osEepStatus` | I-ROM | High; 100.0% normalized words | [src/io/conteepwrite.c](https://github.com/decompals/ultralib/blob/e24c836796df4bf520ff8b11a5c9d2cea3a66cbd/src/io/conteepwrite.c) |
| `func_801D0030` | `osEepromRead` | I-ROM | High; 100.0% normalized words | [src/io/conteepread.c](https://github.com/decompals/ultralib/blob/e24c836796df4bf520ff8b11a5c9d2cea3a66cbd/src/io/conteepread.c) |
| `func_801D01C4` | `__osPackEepReadData` | I-ROM | High; 100.0% normalized words | [src/io/conteepread.c](https://github.com/decompals/ultralib/blob/e24c836796df4bf520ff8b11a5c9d2cea3a66cbd/src/io/conteepread.c) |
| `func_801D0280` | `osEepromLongWrite` | I-ROM | High; 100.0% normalized words | [src/io/conteeplongwrite.c](https://github.com/decompals/ultralib/blob/e24c836796df4bf520ff8b11a5c9d2cea3a66cbd/src/io/conteeplongwrite.c) |
| `func_801D0370` | `osEepromLongRead` | I-ROM | High; 100.0% normalized words | [src/io/conteeplongread.c](https://github.com/decompals/ultralib/blob/e24c836796df4bf520ff8b11a5c9d2cea3a66cbd/src/io/conteeplongread.c) |
| `func_801D03E0` | `osPiRawReadIo` | I-ROM | High; 100.0% normalized words | [src/io/pirawread.c](https://github.com/decompals/ultralib/blob/e24c836796df4bf520ff8b11a5c9d2cea3a66cbd/src/io/pirawread.c) |
| `func_801D0480` | `osCreatePiManager` | I-ROM | High; 100.0% normalized words | [src/io/pimgr.c](https://github.com/decompals/ultralib/blob/e24c836796df4bf520ff8b11a5c9d2cea3a66cbd/src/io/pimgr.c) |
| `func_801D0610` | `osPiRawStartDma` | I-ROM | High; 100.0% normalized words | [src/io/pirawdma.c](https://github.com/decompals/ultralib/blob/e24c836796df4bf520ff8b11a5c9d2cea3a66cbd/src/io/pirawdma.c) |
| `func_801D06E0` | `osEPiRawStartDma` | I-ROM | High; 98.3% normalized words | [src/io/epirawdma.c](https://github.com/decompals/ultralib/blob/e24c836796df4bf520ff8b11a5c9d2cea3a66cbd/src/io/epirawdma.c) |
| `func_801D08B0` | `osEPiStartDma` | I-ROM | High; 100.0% normalized words | [src/io/epidma.c](https://github.com/decompals/ultralib/blob/e24c836796df4bf520ff8b11a5c9d2cea3a66cbd/src/io/epidma.c) |
| `func_801D0950` | `osJamMesg` | I-ROM | High; 100.0% normalized words | [src/os/jammesg.c](https://github.com/decompals/ultralib/blob/e24c836796df4bf520ff8b11a5c9d2cea3a66cbd/src/os/jammesg.c) |
| `func_801D0A90` | `osPiGetCmdQueue` | I-ROM | High; 100.0% normalized words | [src/io/pigetcmdq.c](https://github.com/decompals/ultralib/blob/e24c836796df4bf520ff8b11a5c9d2cea3a66cbd/src/io/pigetcmdq.c) |
| `func_801D0AB0` | `osCartRomInit` | I-ROM | High; 100.0% normalized words | [src/io/cartrominit.c](https://github.com/decompals/ultralib/blob/e24c836796df4bf520ff8b11a5c9d2cea3a66cbd/src/io/cartrominit.c) |
| `func_801D0B90` | `osLeoDiskInit` | I-ROM | High; 100.0% normalized words | [src/io/leodiskinit.c](https://github.com/decompals/ultralib/blob/e24c836796df4bf520ff8b11a5c9d2cea3a66cbd/src/io/leodiskinit.c) |
| `func_801D0C90` | `__osLeoInterrupt` | I-ROM | High; 100.0% normalized words | [src/io/leointerrupt.c](https://github.com/decompals/ultralib/blob/e24c836796df4bf520ff8b11a5c9d2cea3a66cbd/src/io/leointerrupt.c) |
| `func_801D119C` | `__osLeoAbnormalResume` | I-ROM | High; 100.0% normalized words | [src/io/leointerrupt.c](https://github.com/decompals/ultralib/blob/e24c836796df4bf520ff8b11a5c9d2cea3a66cbd/src/io/leointerrupt.c) |
| `func_801D126C` | `__osLeoResume` | I-ROM | High; 100.0% normalized words | [src/io/leointerrupt.c](https://github.com/decompals/ultralib/blob/e24c836796df4bf520ff8b11a5c9d2cea3a66cbd/src/io/leointerrupt.c) |
| `func_801D1320` | `osDriveRomInit` | I-ROM | High; 100.0% normalized words | [src/io/driverominit.c](https://github.com/decompals/ultralib/blob/e24c836796df4bf520ff8b11a5c9d2cea3a66cbd/src/io/driverominit.c) |
| `func_801D13E0` | `__osDevMgrMain` | I-ROM | High; 99.6% normalized words | [src/io/devmgr.c](https://github.com/decompals/ultralib/blob/e24c836796df4bf520ff8b11a5c9d2cea3a66cbd/src/io/devmgr.c) |
| `func_801D17A0` | `__osResetGlobalIntMask` | I-ROM | High; 100.0% normalized words | [src/os/resetglobalintmask.c](https://github.com/decompals/ultralib/blob/e24c836796df4bf520ff8b11a5c9d2cea3a66cbd/src/os/resetglobalintmask.c) |
| `func_801D17F0` | `__osSetGlobalIntMask` | I-ROM | High; 100.0% normalized words | [src/os/setglobalintmask.c](https://github.com/decompals/ultralib/blob/e24c836796df4bf520ff8b11a5c9d2cea3a66cbd/src/os/setglobalintmask.c) |
| `func_801D1830` | `osYieldThread` | I-ROM | High; 100.0% normalized words | [src/os/yieldthread.c](https://github.com/decompals/ultralib/blob/e24c836796df4bf520ff8b11a5c9d2cea3a66cbd/src/os/yieldthread.c) |
| `func_801D1880` | `osEPiRawReadIo` | I-ROM | High; 98.0% normalized words | [src/io/epirawread.c](https://github.com/decompals/ultralib/blob/e24c836796df4bf520ff8b11a5c9d2cea3a66cbd/src/io/epirawread.c) |
| `func_801D1A10` | `osEPiRawWriteIo` | I-ROM | Medium-high; 97.5% normalized words | [src/io/epirawwrite.c](https://github.com/decompals/ultralib/blob/e24c836796df4bf520ff8b11a5c9d2cea3a66cbd/src/io/epirawwrite.c) |
| `func_801D1B60` | `__osPiCreateAccessQueue` | I-ROM | High; 100.0% normalized words; call/global context disambiguates | [src/io/piacs.c](https://github.com/decompals/ultralib/blob/e24c836796df4bf520ff8b11a5c9d2cea3a66cbd/src/io/piacs.c) |
| `func_801D1BB4` | `__osPiGetAccess` | I-ROM | High; 100.0% normalized words; call/global context disambiguates | [src/io/piacs.c](https://github.com/decompals/ultralib/blob/e24c836796df4bf520ff8b11a5c9d2cea3a66cbd/src/io/piacs.c) |
| `func_801D1C20` | `__osPiRelAccess` | I-ROM | High; 100.0% normalized words; call/global context disambiguates | [src/io/piacs.c](https://github.com/decompals/ultralib/blob/e24c836796df4bf520ff8b11a5c9d2cea3a66cbd/src/io/piacs.c) |
| `func_801D1C50` | `osPiStartDma` | I-ROM | High; 100.0% normalized words | [src/io/pidma.c](https://github.com/decompals/ultralib/blob/e24c836796df4bf520ff8b11a5c9d2cea3a66cbd/src/io/pidma.c) |
| `func_801D2150` | `sprintf` | I-ROM | High; 100.0% normalized words | [src/libc/sprintf.c](https://github.com/decompals/ultralib/blob/e24c836796df4bf520ff8b11a5c9d2cea3a66cbd/src/libc/sprintf.c) |
| `func_801D21A8` | `proutSprintf` | I-ROM | High; 100.0% normalized words | [src/libc/sprintf.c](https://github.com/decompals/ultralib/blob/e24c836796df4bf520ff8b11a5c9d2cea3a66cbd/src/libc/sprintf.c) |
| `func_801D21E0` | `_Printf` | I-ROM | High; 100.0% normalized words | [src/libc/xprintf.c](https://github.com/decompals/ultralib/blob/e24c836796df4bf520ff8b11a5c9d2cea3a66cbd/src/libc/xprintf.c) |
| `func_801D2750` | `_Putfld` | I-ROM | High; 99.7% normalized words | [src/libc/xprintf.c](https://github.com/decompals/ultralib/blob/e24c836796df4bf520ff8b11a5c9d2cea3a66cbd/src/libc/xprintf.c) |
| `func_801D2C10` | `_Litob` | I-ROM | High; 100.0% normalized words | [src/libc/xlitob.c](https://github.com/decompals/ultralib/blob/e24c836796df4bf520ff8b11a5c9d2cea3a66cbd/src/libc/xlitob.c) |
| `func_801D3460` | `_Ldunscale` | I-ROM | High; 100.0% normalized words | [src/libc/xldtob.c](https://github.com/decompals/ultralib/blob/e24c836796df4bf520ff8b11a5c9d2cea3a66cbd/src/libc/xldtob.c) |
| `func_801D34F8` | `_Genld` | I-ROM | High; 100.0% normalized words | [src/libc/xldtob.c](https://github.com/decompals/ultralib/blob/e24c836796df4bf520ff8b11a5c9d2cea3a66cbd/src/libc/xldtob.c) |

## Additional assembly and behavioral candidates

| Glover function | Likely function | Version | Confidence / evidence | Source family |
| --- | --- | --- | --- | --- |
| `func_8010D9B4` | `__osGetSR` | I/J-era; exact revision unverified | High; mfc0 v0,SR; jr ra; nop; handwritten | [src/os/getsr.s](https://github.com/decompals/ultralib/blob/e24c836796df4bf520ff8b11a5c9d2cea3a66cbd/src/os/getsr.s) |
| `func_8010D9C0` | `__osSetSR` | I/J-era; exact revision unverified | High; CP0 SR write leaf; handwritten | [src/os/setsr.s](https://github.com/decompals/ultralib/blob/e24c836796df4bf520ff8b11a5c9d2cea3a66cbd/src/os/setsr.s) |
| `func_801C4030` | `sqrtf` | I/J-era; exact revision unverified | High; jr ra with sqrt.s in delay slot; upstream documents compiler builtin bug | [src/gu/sqrtf.s](https://github.com/decompals/ultralib/blob/e24c836796df4bf520ff8b11a5c9d2cea3a66cbd/src/gu/sqrtf.s) |
| `func_801C4040` | `cosf` | I/J-era; exact revision unverified | High; float exponent extraction, absolute value, range reduction and polynomial; same 0x150 size as Snowboard cosf object | [src/gu/cosf.c](https://github.com/decompals/ultralib/blob/e24c836796df4bf520ff8b11a5c9d2cea3a66cbd/src/gu/cosf.c) |
| `func_801C4190` | `guLookAtF` | I/J-era; exact revision unverified | High; identity setup, three vector normalizations via sqrtf, view matrix stores | [src/gu/lookat.c](https://github.com/decompals/ultralib/blob/e24c836796df4bf520ff8b11a5c9d2cea3a66cbd/src/gu/lookat.c) |
| `func_801C4510` | `guLookAt` | I/J-era; exact revision unverified | High; same view construction followed by guMtxF2L | [src/gu/lookat.c](https://github.com/decompals/ultralib/blob/e24c836796df4bf520ff8b11a5c9d2cea3a66cbd/src/gu/lookat.c) |
| `func_801C48A0` | `guLookAtHiliteF` | I/J-era; exact revision unverified | High; extended look-at construction and hilite vectors; called by guLookAtHilite | [src/gu/lookathil.c](https://github.com/decompals/ultralib/blob/e24c836796df4bf520ff8b11a5c9d2cea3a66cbd/src/gu/lookathil.c) |
| `func_801C565C` | `guMtxXFMF` | I/J-era; exact revision unverified | High; matrix-vector multiply, float output pointers; wrapped by guMtxXFML | [src/gu/mtxcatf.c](https://github.com/decompals/ultralib/blob/e24c836796df4bf520ff8b11a5c9d2cea3a66cbd/src/gu/mtxcatf.c) |
| `func_801C5810` | `guPerspectiveF` | I/J-era; exact revision unverified | High; identity, cosf/sinf ratio, perspective matrix and normalization factor | [src/gu/perspective.c](https://github.com/decompals/ultralib/blob/e24c836796df4bf520ff8b11a5c9d2cea3a66cbd/src/gu/perspective.c) |
| `func_801C59C0` | `guPerspective` | I/J-era; exact revision unverified | High; same perspective construction then guMtxF2L | [src/gu/perspective.c](https://github.com/decompals/ultralib/blob/e24c836796df4bf520ff8b11a5c9d2cea3a66cbd/src/gu/perspective.c) |
| `func_801C5E70` | `guNormalize` | I/J-era; exact revision unverified | High; sum of three squares, sqrtf, component divisions | [src/gu/normalize.c](https://github.com/decompals/ultralib/blob/e24c836796df4bf520ff8b11a5c9d2cea3a66cbd/src/gu/normalize.c) |
| `func_801C6000` | `sinf` | I/J-era; exact revision unverified | High; float exponent tests 0xFF/0xE6, polynomial and range reduction; 0x1A0 Snowboard sinf object | [src/gu/sinf.c](https://github.com/decompals/ultralib/blob/e24c836796df4bf520ff8b11a5c9d2cea3a66cbd/src/gu/sinf.c) |
| `func_801C62C0` | `osSetIntMask` | I/J-era; exact revision unverified | High; CP0 SR and RCP mask handling; handwritten | [src/os/setintmask.s](https://github.com/decompals/ultralib/blob/e24c836796df4bf520ff8b11a5c9d2cea3a66cbd/src/os/setintmask.s) |
| `func_801C63D0` | `osInvalDCache` | I/J-era; exact revision unverified | High; cache line iteration and cache invalidate/writeback operations | [src/os/invaldcache.s](https://github.com/decompals/ultralib/blob/e24c836796df4bf520ff8b11a5c9d2cea3a66cbd/src/os/invaldcache.s) |
| `func_801C6470` | `osWritebackDCache` | I/J-era; exact revision unverified | High; cache line iteration and writeback operations | [src/os/writebackdcache.s](https://github.com/decompals/ultralib/blob/e24c836796df4bf520ff8b11a5c9d2cea3a66cbd/src/os/writebackdcache.s) |
| `func_801C64F0` | `osWritebackDCacheAll` | I/J-era; exact revision unverified | High; whole D-cache writeback loop | [src/os/writebackdcacheall.s](https://github.com/decompals/ultralib/blob/e24c836796df4bf520ff8b11a5c9d2cea3a66cbd/src/os/writebackdcacheall.s) |
| `func_801C7320` | `__osGetSR` | I/J-era; exact revision unverified | High; same mfc0 SR leaf as boot copy | [src/os/getsr.s](https://github.com/decompals/ultralib/blob/e24c836796df4bf520ff8b11a5c9d2cea3a66cbd/src/os/getsr.s) |
| `func_801C7330` | `osInvalICache` | I/J-era; exact revision unverified | High; I-cache line iteration | [src/os/invalicache.s](https://github.com/decompals/ultralib/blob/e24c836796df4bf520ff8b11a5c9d2cea3a66cbd/src/os/invalicache.s) |
| `func_801C73B0` | `__osSetFpcCsr` | I/J-era; exact revision unverified | High; cfc1 old FCSR, ctc1 argument into FCSR | [src/os/setfpccsr.s](https://github.com/decompals/ultralib/blob/e24c836796df4bf520ff8b11a5c9d2cea3a66cbd/src/os/setfpccsr.s) |
| `func_801C73C0` | `__osSetSR` | I/J-era; exact revision unverified | High; CP0 SR setter leaf | [src/os/setsr.s](https://github.com/decompals/ultralib/blob/e24c836796df4bf520ff8b11a5c9d2cea3a66cbd/src/os/setsr.s) |
| `func_801C73D0` | `__osMapTLBRdb` | I/J-era; exact revision unverified | High; writes RDB mapping with tlbwi at index 31 | [src/os/maptlbrdb.s](https://github.com/decompals/ultralib/blob/e24c836796df4bf520ff8b11a5c9d2cea3a66cbd/src/os/maptlbrdb.s) |
| `func_801C7DF0` | `__osProbeTLB` | I/J-era; exact revision unverified | High; tlbp/tlbr and page translation; called by osVirtualToPhysical | [src/os/probetlb.s](https://github.com/decompals/ultralib/blob/e24c836796df4bf520ff8b11a5c9d2cea3a66cbd/src/os/probetlb.s) |
| `func_801CE2F0` | `osAiGetLength` | I/J-era; exact revision unverified | High; read AI_LEN_REG at 0xA4500004 | [src/io/aigetlen.c](https://github.com/decompals/ultralib/blob/e24c836796df4bf520ff8b11a5c9d2cea3a66cbd/src/io/aigetlen.c) |
| `func_801CE300` | `osAiSetFrequency` | I/J-era; exact revision unverified | High; VI clock / frequency, DAC period, divide by 66 and AI register writes | [src/io/aisetfreq.c](https://github.com/decompals/ultralib/blob/e24c836796df4bf520ff8b11a5c9d2cea3a66cbd/src/io/aisetfreq.c) |
| `func_801CE4D0` | `__osAiDeviceBusy` | I/J-era; exact revision unverified | High; AI_STATUS sign bit / FIFO-full test | [src/io/ai.c](https://github.com/decompals/ultralib/blob/e24c836796df4bf520ff8b11a5c9d2cea3a66cbd/src/io/ai.c) |
| `func_801CE750` | `__osSpSetStatus` | I/J-era; exact revision unverified | High; store SP_STATUS_REG at 0xA4040010 | [src/io/spsetstat.c](https://github.com/decompals/ultralib/blob/e24c836796df4bf520ff8b11a5c9d2cea3a66cbd/src/io/spsetstat.c) |
| `func_801CE900` | `__osSpGetStatus` | I/J-era; exact revision unverified | High; load SP_STATUS_REG at 0xA4040010 | [src/io/spgetstat.c](https://github.com/decompals/ultralib/blob/e24c836796df4bf520ff8b11a5c9d2cea3a66cbd/src/io/spgetstat.c) |
| `func_801CEDF0` | `__osViGetCurrentContext` | I/J-era; exact revision unverified | High; return D_801F4760 | [src/io/vigetcurrcontext.c](https://github.com/decompals/ultralib/blob/e24c836796df4bf520ff8b11a5c9d2cea3a66cbd/src/io/vigetcurrcontext.c) |
| `func_801CF0C0` | `__osViSwapContext` | I/J-era; exact revision unverified | High; next context fields, VI MMIO updates, context exchange | [src/io/viswapcontext.c](https://github.com/decompals/ultralib/blob/e24c836796df4bf520ff8b11a5c9d2cea3a66cbd/src/io/viswapcontext.c) |
| `func_801D1D00` | `bcopy` | I/J-era; exact revision unverified | High; overlap-aware forward/backward aligned word and byte copy | [src/libc/bcopy.s](https://github.com/decompals/ultralib/blob/e24c836796df4bf520ff8b11a5c9d2cea3a66cbd/src/libc/bcopy.s) |
| `func_801D2020` | `bzero` | I/J-era; exact revision unverified | High; alignment prefix, zero-store word loop and byte tail | [src/libc/bzero.s](https://github.com/decompals/ultralib/blob/e24c836796df4bf520ff8b11a5c9d2cea3a66cbd/src/libc/bzero.s) |
| `func_801D2E60` | `ldiv` | I/J-era; exact revision unverified | High; quotient/remainder correction; hidden structure-return pointer | [src/libc/ldiv.c](https://github.com/decompals/ultralib/blob/e24c836796df4bf520ff8b11a5c9d2cea3a66cbd/src/libc/ldiv.c) |
| `func_801D2EE4` | `lldiv` | I/J-era; exact revision unverified | High; 64-bit analogue, calls signed division helper and returns two 64-bit members | [src/libc/ldiv.c](https://github.com/decompals/ultralib/blob/e24c836796df4bf520ff8b11a5c9d2cea3a66cbd/src/libc/ldiv.c) |
| `func_801D3020` | `_Ldtob` | I/J-era; exact revision unverified | High; floating print conversion; calls _Ldunscale, ldiv and _Genld | [src/libc/xldtob.c](https://github.com/decompals/ultralib/blob/e24c836796df4bf520ff8b11a5c9d2cea3a66cbd/src/libc/xldtob.c) |
| `func_801D3AA0` | `__divdi3 (KMC/libgcc signed 64-bit divide)` | KMC GCC 2.7.2 runtime candidate | Medium; sign normalization around unsigned divide helper; library source invokes compiler helper | [src/libc/ldiv.c](https://github.com/decompals/ultralib/blob/e24c836796df4bf520ff8b11a5c9d2cea3a66cbd/src/libc/ldiv.c) |
| `func_801D3B60` | `__udivdi3 / __udivmoddi4 family (KMC/libgcc)` | KMC GCC 2.7.2 runtime candidate | Medium; multiword unsigned division used by signed helper; exact ABI/name needs runtime archive comparison | [src/libc/ldiv.c](https://github.com/decompals/ultralib/blob/e24c836796df4bf520ff8b11a5c9d2cea3a66cbd/src/libc/ldiv.c) |

Total: **132 unmatched candidates** (96 compiled-reference comparisons, 36 additional behavioral/assembly candidates). No candidates were implemented or marked matched.

Handwritten CP0/cache/TLB routines and the sqrt leaf require particular care under the pure-C rule: do not invent unsupported builtins or inline assembly. Do not treat every boot exception trampoline or game vector routine as libultra merely because it resembles one. Boundary audit and linker placement remain authoritative.


## libultra 2.0I names for the 0x801C–0x801D band (2026-10-18)

From [djsaunde/glover-decomp-1 issue 1](https://github.com/djsaunde/glover-decomp-1/issues/1) (madbot-001, 2026-08-27):
57 names verified present in decompals/ultralib at version I, with 14 functions byte-identical to the
`make TARGET=libgultra_rom VERSION=I` build (the GCC-built libultra). That fork still uses the old ROM mapping, so its
addresses are 0x1000 above ours; the table is already shifted. Three names are decided only by link order and were not
applied; two are hand-written assembly upstream and belong on the do-not-claim list. Names are recorded as function
notes in the app (the fork has no rename tool); the symbol file still says `func_`. Files are decompals/ultralib paths
at commit e24c836.

| Ours | libultra | ultralib file | insns | now | note |
|---|---|---|---:|---:|---|
| `func_801C48A0` | `guLookAtHiliteF` | `src/gu/lookathil.c` | 609 | 64.4% |  |
| `func_801C5398` | `guMtxL2F` | `src/gu/mtxutil.c` | 42 | 95.2% |  |
| `func_801C5580` | `guMtxCatF` | `src/gu/mtxcatf.c` | 55 | matched |  |
| `func_801C5710` | `guMtxCatL` | `src/gu/mtxcatl.c` | 29 | 94.5% |  |
| `func_801C5B90` | `guRotateF` | `src/gu/rotate.c` | 87 | 62.4% |  |
| `func_801C5F20` | `guScaleF` | `src/gu/scale.c` | 24 | 53.3% |  |
| `func_801C61A0` | `guTranslateF` | `src/gu/translate.c` | 21 | 46.7% |  |
| `func_801C63D0` | `osSetIntMask` | `src/os/setintmask.s` | 40 | undrafted | assembly upstream: do not claim |
| `func_801C6550` | `osCreateThread` | `src/os/createthread.c` | 52 | 93.8% |  |
| `func_801C7560` | `osSendMesg` | `src/os/sendmesg.c` | 76 | 97.9% |  |
| `func_801C7C10` | `__osSetTimerIntr` | `src/os/timerintr.c` | 24 | 93.3% |  |
| `func_801C7F54` | `alFxNew` | `src/audio/drvrnew.c` | 294 | 85.0% |  |
| `func_801C83EC` | `alEnvmixerNew` | `src/audio/drvrnew.c` | 46 | 96.5% |  |
| `func_801C84A4` | `alLoadNew` | `src/audio/drvrnew.c` | 44 | 96.4% |  |
| `func_801C8554` | `alResampleNew` | `src/audio/drvrnew.c` | 35 | 95.4% |  |
| `func_801C85E0` | `alAuxBusNew` | `src/audio/drvrnew.c` | 23 | 93.0% |  |
| `func_801C863C` | `alMainBusNew` | `src/audio/drvrnew.c` | 23 | 93.0% |  |
| `func_801C8EC0` | `alLoadParam` | `src/audio/load.c` | 107 | 95.1% |  |
| `func_801C984C` | `alEnvmixerParam` | `src/audio/env.c` | 53 | 94.8% |  |
| `func_801C9920` | `_pullSubFrame` | `src/audio/env.c` | 192 | 84.7% |  |
| `func_801C9D24` | `_getRate` | `src/audio/env.c` | 160 | 84.4% |  |
| `func_801CAA34` | `_loadOutputBuffer` | `src/audio/reverb.c` | 134 | 82.9% |  |
| `func_801CAC4C` | `_loadBuffer` | `src/audio/reverb.c` | 92 | 98.3% |  |
| `func_801CADBC` | `_saveBuffer` | `src/audio/reverb.c` | 92 | 98.3% |  |
| `func_801CAF2C` | `_filterBuffer` | `src/audio/reverb.c` | 39 | 88.3% |  |
| `func_801CB060` | `alSavePull` | `src/audio/save.c` | 64 | 86.1% |  |
| `func_801CB310` | `alSynNew` | `src/audio/synthesizer.c` | 179 | 89.8% |  |
| `func_801CB5DC` | `alAudioFrame` | `src/audio/synthesizer.c` | 108 | 98.5% |  |
| `func_801CB7D0` | `_collectPVoices` | `src/audio/synthesizer.c` | 21 | 92.4% |  |
| `func_801CB824` | `_freePVoice` | `src/audio/synthesizer.c` | 16 | 90.0% |  |
| `func_801CB8F8` | `__nextSampleTime` | `src/audio/synthesizer.c` | 42 | 96.2% |  |
| `func_801CB9B0` | `alSynAddPlayer` | `src/audio/synaddplayer.c` | 20 | 92.0% |  |
| `func_801CBA00` | `alSynAllocVoice` | `src/audio/synallocvoice.c` | 74 | 77.4% |  |
| `func_801CBB28` | `_allocatePVoice` | `src/audio/synallocvoice.c` | 46 | 96.5% |  |
| `func_801CBD00` | `alSynSetPitch` | `src/audio/synsetpitch.c` | 36 | 83.1% |  |
| `func_801CBE50` | `alSynSetFXMix` | `src/audio/synsetfxmix.c` | 36 | 95.6% |  |
| `func_801CBEE0` | `alSynSetPan` | `src/audio/synsetpan.c` | 36 | 94.7% |  |
| `func_801CC118` | `drawbitmap` | `src/sp/sprite.c` | 1194 | undrafted |  |
| `func_801CD3C0` | `spInit` | `src/sp/sprite.c` | 110 | 98.5% |  |
| `func_801CD578` | `spDraw` | `src/sp/sprite.c` | 813 | 80.7% |  |
| `func_801CE4F0` | `osSpTaskLoad` | `src/io/sptask.c` | 131 | 98.7% |  |
| `func_801CEAA0` | `osCreateViManager` | `src/io/vimgr.c` | 102 | 95.8% |  |
| `func_801CF410` | `__osSiRawReadIo` | `src/io/sirawread.c` | 36 | 95.3% | link-order ambiguous (byte-identical sibling) |
| `func_801CF530` | `osContStartReadData` | `src/io/contreaddata.c` | 34 | 62.9% |  |
| `func_801CF5B8` | `osContGetReadData` | `src/io/contreaddata.c` | 39 | matched |  |
| `func_801CFA5C` | `__osContGetInitData` | `src/io/controller.c` | 45 | 97.8% | link-order ambiguous (byte-identical sibling) |
| `func_801CFC50` | `osEepromWrite` | `src/io/conteepwrite.c` | 98 | undrafted |  |
| `func_801CFDD8` | `__osPackEepWriteData` | `src/io/conteepwrite.c` | 49 | 94.4% |  |
| `func_801CFE9C` | `__osEepStatus` | `src/io/conteepwrite.c` | 101 | 98.4% |  |
| `func_801D0030` | `osEepromRead` | `src/io/conteepread.c` | 101 | 98.4% |  |
| `func_801D01C4` | `__osPackEepReadData` | `src/io/conteepread.c` | 47 | 96.6% |  |
| `func_801D0480` | `osCreatePiManager` | `src/io/pimgr.c` | 100 | 98.4% |  |
| `func_801D119C` | `__osLeoAbnormalResume` | `src/io/leointerrupt.c` | 52 | 88.4% |  |
| `func_801D1B60` | `__osPiCreateAccessQueue` | `src/io/piacs.c` | 21 | 92.4% | link-order ambiguous (byte-identical sibling) |
| `func_801D2020` | `bzero` | `src/libc/bzero.s` | 40 | 54.4% | assembly upstream: do not claim |
| `func_801D21E0` | `_Printf` | `src/libc/xprintf.c` | 348 | 92.0% |  |
| `func_801D3020` | `_Ldtob` | `src/libc/xldtob.c` | 272 | 75.9% |  |
