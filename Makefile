COMPARE := 1

LDSCRIPT := thelegendofzelda.ld
BUILD_DIR := build

AS := mips-linux-gnu-as
ASFLAGS := -march=vr4300 -32 -no-pad-sections -Iinclude

OBJCOPY := mips-linux-gnu-objcopy

ifeq ($(IDO7RECOMP),)
  $(error No path to ido 7.1 recomp set. Export IDO7RECOMP as an environment variable or pass it to make.)
endif
ifeq ($(IDO5RECOMP),)
  $(error No path to ido 5.3 recomp set. Export IDO5RECOMP as an environment variable or pass it to make.)
endif

IDO7 := $(IDO7RECOMP)
IDO5 := $(IDO5RECOMP)

CC := $(IDO7)
OPTFLAGS := -O2 -g3

LD := mips-linux-gnu-ld
LDFLAGS := -T $(LDSCRIPT) -T undefined_funcs_auto.txt -T undefined_syms_auto.txt --no-check-sections --accept-unknown-input-arch --emit-relocs -Map $(BUILD_DIR)/thelegendofzelda.map

default: $(BUILD_DIR)/thelegendofzelda.z64
ifneq ($(COMPARE),0)
	md5sum -c checksum.md5
endif
.PHONY: default

$(BUILD_DIR)/%.o: %.s
	@mkdir -p $(dir $@)
	iconv -f UTF-8 -t EUC-JP $< | $(AS) $(ASFLAGS) -o $@

$(BUILD_DIR)/%.o: %.bin
	@mkdir -p $(dir $@)
	$(OBJCOPY) -I binary -O elf32-tradbigmips $< $@

$(BUILD_DIR)/%.o: %.c
	@mkdir -p $(dir $@)
	python3 asm-processor/build.py --input-enc UTF-8 --output-enc EUC-JP $(CC) -- $(AS) $(ASFLAGS) -- -DOOT_VERSION=NTSC_1_2 -I include -I include/include_cc0redo -I include/include_cc0redo/libc -c -G 0 -non_shared -fullwarn -verbose -Xcpluscomm -Wab,-r4300_mul -mips2 $(OPTFLAGS) -woff 649,838,807 -o $@ $<

include thelegendofzelda.d

$(BUILD_DIR)/thelegendofzelda.elf: $(LDSCRIPT) undefined_funcs_auto.txt undefined_syms_auto.txt
	@mkdir -p $(dir $@)
	$(LD) $(LDFLAGS) -o $@

$(BUILD_DIR)/thelegendofzelda.z64: $(BUILD_DIR)/thelegendofzelda.elf
	@mkdir -p $(dir $@)
	$(OBJCOPY) -O binary $< $@
