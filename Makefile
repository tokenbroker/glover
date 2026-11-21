MAKEFLAGS += --no-builtin-rules

SHELL = /bin/bash
.SHELLFLAGS = -o pipefail -c

#### Defaults ####
VERSION  ?= us
COMPARE  ?= 1
NON_MATCHING ?= 0
CROSS    ?= mips-linux-gnu-
PYTHON   ?= python3

TARGET   := glover

# OS detection
ifeq ($(OS),Windows_NT)
  DETECTED_OS := windows
else
  UNAME_S := $(shell uname -s)
  ifeq ($(UNAME_S),Linux)
    DETECTED_OS := linux
  endif
  ifeq ($(UNAME_S),Darwin)
    DETECTED_OS := macos
  endif
endif

#### Directories ####
BUILD_DIR := build
SRC_DIRS  := $(shell find src -type d 2>/dev/null)
ASM_DIRS  := $(shell find asm -type d -not -path "asm/nonmatchings/*" 2>/dev/null)
BIN_DIRS  := $(shell find assets -type d 2>/dev/null)

#### Tools ####
CC       := tools/gcc_2.7.2/$(DETECTED_OS)/gcc
STRIP    := $(CROSS)strip
AS       := $(CROSS)as
LD       := $(CROSS)ld
OBJCOPY  := $(CROSS)objcopy
OBJDUMP  := $(CROSS)objdump
CPP      := cpp
ASM_PROC := $(PYTHON) tools/asm-processor/build.py

SPLAT      ?= $(PYTHON) -m splat split
SPLAT_YAML ?= glover.yaml

#### Flags ####
CFLAGS    := -G0 -mips3 -mgp32 -mfp32 -Wa,--no-float-doubleword -Wa,-mabi=32 -Wa,-Iinclude -D_LANGUAGE_C
CPPFLAGS  := -Iinclude -I$(BUILD_DIR)/include -Isrc -DF3DEX_GBI_2 -D_LANGUAGE_C
ifeq ($(NON_MATCHING),1)
  CPPFLAGS += -DNON_MATCHING
endif
OPTFLAGS  := -O2 -g2
ASFLAGS   := -march=vr4300 -32 -G0
LDFLAGS   := --no-check-sections --accept-unknown-input-arch --emit-relocs
ENDIAN    := -EB

IINC := -Iinclude -I.

#### Host CC check ####
RUN_CC_CHECK ?= 1
ifdef PERMUTER
RUN_CC_CHECK := 0
endif
ifneq ($(RUN_CC_CHECK),0)
CC_CHECK       := gcc
CC_CHECK_FLAGS := -MMD -MP -fno-builtin -fsyntax-only -funsigned-char -std=gnu90 -m32 \
                  -DNON_MATCHING -DCC_CHECK=1 -D_LANGUAGE_C -DF3DEX_GBI_2 \
                  -Wall -Wextra -Wno-format-security -Wno-unused-parameter \
                  -Wno-sign-compare -Wno-unused-variable
else
CC_CHECK       := @:
CC_CHECK_FLAGS :=
endif

#### Files ####
C_FILES   := $(foreach dir,$(SRC_DIRS),$(wildcard $(dir)/*.c))
S_FILES   := $(foreach dir,$(ASM_DIRS) $(SRC_DIRS),$(wildcard $(dir)/*.s))
BIN_FILES := $(foreach dir,$(BIN_DIRS),$(wildcard $(dir)/*.bin))

O_FILES := $(foreach f,$(C_FILES:.c=.o),$(BUILD_DIR)/$f) \
           $(foreach f,$(S_FILES:.s=.o),$(BUILD_DIR)/$f) \
           $(foreach f,$(BIN_FILES:.bin=.o),$(BUILD_DIR)/$f)

DEP_FILES := $(O_FILES:.o=.d)

# Create build directories
$(shell mkdir -p $(foreach dir,$(SRC_DIRS) $(ASM_DIRS) $(BIN_DIRS),$(BUILD_DIR)/$(dir)))

#### Linker script ####
LDSCRIPT := $(BUILD_DIR)/$(TARGET).ld

#### Targets ####
all: rom

rom: $(BUILD_DIR)/$(TARGET).z64
ifneq ($(COMPARE),0)
	@md5sum $<
endif

clean:
	$(RM) -r $(BUILD_DIR)

distclean: clean
	$(RM) -r asm/ assets/

# splat regenerates asm/ and assets/ from baserom.z64. It also rewrites the linker script and the
# undefined-symbol lists, which are maintained by hand here, so those are restored afterwards.
EXTRACT_KEEP := glover.ld undefined_syms_auto.txt undefined_funcs_auto.txt
extract:
	$(RM) -r asm/ assets/ $(BUILD_DIR)/extract-keep
	mkdir -p $(BUILD_DIR)/extract-keep
	cp $(EXTRACT_KEEP) $(BUILD_DIR)/extract-keep/
	$(SPLAT) $(SPLAT_YAML); status=$$?; cp $(addprefix $(BUILD_DIR)/extract-keep/,$(EXTRACT_KEEP)) .; exit $$status

expected: rom
	$(RM) -r expected
	mkdir -p expected/src expected/asm
	cp $(BUILD_DIR)/src/*.o expected/src/
	cp $(BUILD_DIR)/asm/*.o expected/asm/

.PHONY: all rom clean distclean extract expected
.DEFAULT_GOAL := rom
.SECONDARY:

#### Recipes ####

$(BUILD_DIR)/$(TARGET).z64: $(BUILD_DIR)/$(TARGET).elf
	$(OBJCOPY) -O binary $< $@

# Interim: link copies of the C objects use the original read-only data block (tools/link_rodata.py).
C_O_FILES := $(filter $(BUILD_DIR)/src/%.o,$(O_FILES))
$(BUILD_DIR)/link/src/crodata.ld: $(C_O_FILES) tools/link_rodata.py $(SPLAT_YAML)
	$(PYTHON) tools/link_rodata.py $(SPLAT_YAML) baserom.z64 $(BUILD_DIR)/link/src $(C_O_FILES)

$(BUILD_DIR)/$(TARGET).elf: $(O_FILES) $(LDSCRIPT) $(BUILD_DIR)/link/src/crodata.ld
	$(LD) $(LDFLAGS) -T $(LDSCRIPT) \
		-T undefined_funcs_auto.txt -T undefined_syms_auto.txt -T undefined_syms.txt \
		-Map $(BUILD_DIR)/$(TARGET).map -o $@

$(LDSCRIPT): $(TARGET).ld
	$(CPP) -P $(IINC) -o $@ $<

#### Per-file optimization overrides ####
# PACK_TEXT := 1 on a piece that starts or ends inside a 16-byte line: the assembler gives .text 16-byte alignment
# and pads its size to 16, where the original single object had neither (tools/fable/pack_text.py).
comma := ,
$(BUILD_DIR)/src/18020_2D2B0.o: OPTFLAGS := -O0 -g2
$(BUILD_DIR)/src/18020_33940.o: OPTFLAGS := -O0 -g2
$(BUILD_DIR)/src/18020_34E60.o: OPTFLAGS := -O0 -g2
$(BUILD_DIR)/src/18020_3A90C.o: OPTFLAGS := -O0 -g2
$(BUILD_DIR)/src/18020_3AD70.o: OPTFLAGS := -O0 -g2
$(BUILD_DIR)/src/18020_46680.o: OPTFLAGS := -O0 -g2
$(BUILD_DIR)/src/18020_47B98.o: OPTFLAGS := -O0 -g2
$(BUILD_DIR)/src/18020_50400.o: OPTFLAGS := -O0 -g2
$(BUILD_DIR)/src/18020_80200.o: OPTFLAGS := -O0 -g2
# 18020_C5030: libultra objects, built without -g (GAS fills the delay slots), ldc1/sdc1 doubles, mtc1/mfc1 hazard nops
$(BUILD_DIR)/src/18020_C5030.o: OPTFLAGS := -O2 -Wa,--fp-move-nops -Wa,--lw-dest-temp
$(BUILD_DIR)/src/18020_C5030.o: CFLAGS := $(filter-out -Wa$(comma)--no-float-doubleword,$(CFLAGS))
# 18020_C7520: libultra objects, built without -g (GAS fills the delay slots), ldc1/sdc1 doubles, mtc1/mfc1 hazard nops
$(BUILD_DIR)/src/18020_C7520.o: OPTFLAGS := -O2 -Wa,--fp-move-nops -Wa,--lw-dest-temp
$(BUILD_DIR)/src/18020_C7520.o: CFLAGS := $(filter-out -Wa$(comma)--no-float-doubleword,$(CFLAGS))
$(BUILD_DIR)/asm/C7620.o: PACK_TEXT := 1
$(BUILD_DIR)/asm/C7D8C.o: PACK_TEXT := 1
$(BUILD_DIR)/asm/C7DE4.o: PACK_TEXT := 1
$(BUILD_DIR)/src/18020_34E60.o: PACK_TEXT := 1
$(BUILD_DIR)/src/18020_376E8.o: PACK_TEXT := 1
# func_801366E8, the piece's only function, is -O0 code (frame pointer, every local in its slot, no delay-slot filling,
# $f20-$f26 only for GCC's own temporaries): 100% at -O0 -g2 with sinf/cosf, 50% at -O2 (2026-10-31, Opus draft)
$(BUILD_DIR)/src/18020_376E8.o: OPTFLAGS := -O0 -g2
$(BUILD_DIR)/src/18020_3A90C.o: PACK_TEXT := 1
$(BUILD_DIR)/src/18020_46680.o: PACK_TEXT := 1
$(BUILD_DIR)/src/18020_479E4.o: PACK_TEXT := 1
# func_801469E4 is -O0 code in an -O2 unit (s8 frame pointer, args copied to s0-s7, a nop in every jal delay
# slot): the one-function piece builds at -O0 like the pieces above (suggestions #2 and #3, 2026-11-18)
$(BUILD_DIR)/src/18020_479E4.o: OPTFLAGS := -O0 -g2
$(BUILD_DIR)/src/18020_47B98.o: PACK_TEXT := 1
# 18020_C7FB0: libultra objects, built without -g (GAS fills the delay slots), ldc1/sdc1 doubles, mtc1/mfc1 hazard nops
$(BUILD_DIR)/src/18020_C7FB0.o: OPTFLAGS := -O2 -Wa,--fp-move-nops -Wa,--lw-dest-temp
$(BUILD_DIR)/src/18020_C7FB0.o: CFLAGS := $(filter-out -Wa$(comma)--no-float-doubleword,$(CFLAGS))
# 18020_C8430: libultra objects, built without -g (GAS fills the delay slots), ldc1/sdc1 doubles, mtc1/mfc1 hazard nops
$(BUILD_DIR)/src/18020_C8430.o: OPTFLAGS := -O2 -Wa,--fp-move-nops -Wa,--lw-dest-temp
$(BUILD_DIR)/src/18020_C8430.o: CFLAGS := $(filter-out -Wa$(comma)--no-float-doubleword,$(CFLAGS))
# 18020_C8D90: libultra objects, built without -g (GAS fills the delay slots), ldc1/sdc1 doubles, mtc1/mfc1 hazard nops
$(BUILD_DIR)/src/18020_C8D90.o: OPTFLAGS := -O2 -Wa,--fp-move-nops -Wa,--lw-dest-temp
$(BUILD_DIR)/src/18020_C8D90.o: CFLAGS := $(filter-out -Wa$(comma)--no-float-doubleword,$(CFLAGS))
# 18020_C8EB0: libultra objects, built without -g (GAS fills the delay slots), ldc1/sdc1 doubles, mtc1/mfc1 hazard nops;
# --lw-dest-temp on every libultra piece (2026-10-31): the ROM's library objects expand lw rd,sym(idx) through rd, as
# upstream gas does, where KMC's assembler (the game units) goes through $at: func_801D06E0, func_801D1880,
# func_801D1A10 matched from that alone (tools/kmc-as-lw-dest-temp.patch)
$(BUILD_DIR)/src/18020_C8EB0.o: OPTFLAGS := -O2 -Wa,--fp-move-nops -Wa,--lw-dest-temp
$(BUILD_DIR)/src/18020_C8EB0.o: CFLAGS := $(filter-out -Wa$(comma)--no-float-doubleword,$(CFLAGS))
# 18020_D30C0: libultra objects, built without -g (GAS fills the delay slots), ldc1/sdc1 doubles, mtc1/mfc1 hazard nops
$(BUILD_DIR)/src/18020_D30C0.o: OPTFLAGS := -O2 -Wa,--fp-move-nops -Wa,--lw-dest-temp
$(BUILD_DIR)/src/18020_D30C0.o: CFLAGS := $(filter-out -Wa$(comma)--no-float-doubleword,$(CFLAGS))
# 18020_D4AA0: libgcc helpers (__divdi3, __udivdi3, __udivmoddi4, __umoddi3), built with -g2: GAS leaves the jr slots unfilled
$(BUILD_DIR)/src/18020_D4AA0.o: OPTFLAGS := -O2 -g2

# src/18020_C0800.c (game_end head, 0x801BF800-0x801C4030) was built by SGI IDO at -O2 -mips2, not by KMC GCC:
# or-moves for register copies, ra saved at frame-4, $t6-$t9 temps (2026-10-28; IDO from tools/ido-static-recomp).
# IDO 7.1 since 2026-10-31: it matches every function 5.3 matched plus the ones whose prologue truncates a byte
# parameter in place (andi $a1,$a1,0xff); the loop unroller stays ON, the ROM's unrolled loops (func_801C2A84,
# func_801C2768) come from it and the loops it leaves alone test a global in their condition or are `while` loops.
IDO71     := tools/ido-static-recomp/build/7.1/out/cc
IDO_FLAGS := -G0 -non_shared -Xcpluscomm -Wab,-r4300_mul -woff 649,838,712 -mips2
$(BUILD_DIR)/src/18020_C0800.o: src/18020_C0800.c
	$(PYTHON) tools/fable/ido_build.py $(IDO71) -- $(AS) $(ASFLAGS) $(ENDIAN) $(IINC) -- -O2 $(IDO_FLAGS) $(CPPFLAGS) -c -o $@ $<

$(BUILD_DIR)/%.o: %.c
ifndef PERMUTER
	$(CC_CHECK) $(CC_CHECK_FLAGS) $(CPPFLAGS) -o $@ $<
endif
	export COMPILER_PATH=tools/gcc_2.7.2/$(DETECTED_OS) && $(CC) -Btools/build/ $(OPTFLAGS) $(CFLAGS) $(CPPFLAGS) -c -o $@ $<
ifndef PERMUTER
	@$(STRIP) $@ -N dummy-symbol-name
endif
	$(if $(PACK_TEXT),$(PYTHON) -I tools/fable/pack_text.py $@)

$(BUILD_DIR)/%.o: %.s
	$(AS) $(ASFLAGS) $(ENDIAN) $(IINC) -I $(dir $*) -o $@ $<
	$(if $(PACK_TEXT),$(PYTHON) -I tools/fable/pack_text.py $@)

$(BUILD_DIR)/%.o: %.bin
	$(OBJCOPY) -I binary -O elf32-big $< $@

-include $(DEP_FILES)

print-% : ; $(info $* is a $(flavor $*) variable set to [$($*)]) @true
