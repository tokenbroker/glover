# Cleanup audit

Step 1 restored 137 C bodies below 100%, including the two link-broken builtin drafts. Also removed 13 extra draft copies staged in src/18020_O0.c that were absent from the target objdiff unit (base-only/nosource); their original assembly stubs remain in the owning -O2 units. These copies were not linked into the ROM, and no functions were moved. The existing uncommitted function edits were all below 100% and were discarded; the staged AGENTS.md notes are deferred to step 3. Removed unused local types, unused/duplicate externs, probe comments and the fake commented INCLUDE_ASM attempt. Consolidated signed/unsigned declarations of D_801E7530 by retaining its signed declaration and casting the unsigned read.

Two missing zero words after D_80179808_padding and D_8019A988_padding were restored as separate C constants, preserving the existing padding symbols and their objdiff results. No protected files were changed. Clean build SHA-1: 270be17b3c8da9b88a7b99c2a545b0bce16837f4. All 243 baseline entries remain 100%. The report includes padding symbols; this is the requested baseline definition.

## Shared layouts

Consumer search covered all src/*.c and include/*.h before extraction. Removed draft-only Unk801F4764 / Unk802AD560 copies have no surviving C users and were deleted in step 1 rather than promoted.

| Canonical type | Consumers and evidence | Decision |
| --- | --- | --- |
| Gfx, 0x08 | func_8014B03C and func_8013DA1C; D_80202240 in both units, D_801ED4A8/D_801ED430 in game; two u32 stores at 0/4 and 8-byte increments | Merge Gfx8014C03C and Gfx into shared Gfx |
| Unk802904D4Node, 0x70 prefix | func_8017DBA0, func_8017DBD8, func_801305D8/func_80130620 declaration, D_802904D4; next at 0, signed halfword at 0x6C | Move unchanged to shared header |
| Unk802AA7A0Node, 0x2C prefix | func_801B985C and D_802AA7A0; next at 0, signed halfword at 0x2A | Move unchanged; distinct from 0x6C list |
| UnkList, 0x08 prefix | func_801779C0; links at 0/4, removes node and decrements D_8029040C | Move unchanged; distinct from ObjectNode (offset 4 is not a pointer there) |
| Unk80299210Node, 0x3C prefix | func_8018B2D4, D_80299210; key word at 0x30, links at 0x34/0x38; initializer func_8018A9D0 establishes sentinel via D_80299244/D_80299248 | Move unchanged; distinct link offsets |

These linked nodes are traversed through pointers, with no C array stride or allocation establishing a complete owning object size. Header size comments describe the accessed prefix only. ObjectNode's 0x110 layout and all existing consumers remain unchanged: its byte fields at 0x6C cannot be silently merged with the signed halfword key in the D_802904D4 family. No speculative field additions or allocation-size claims were made. Each family passed full-ROM SHA-1 and all 243 baseline entries after its change; no family required reverting.
