LDSCRIPT := thelegendofzelda.ld
BUILD_DIR := build

AS := mips-linux-gnu-as
ASFLAGS := -march=vr4300 -32 -no-pad-sections -Iinclude

OBJCOPY := mips-linux-gnu-objcopy

ifeq ($(IDO7RECOMP),)
  $(error No path to ido 7.1 recomp set. Export IDO7RECOMP as an environment variable or pass it to make.)
endif

IDO := $(IDO7RECOMP)

LD := mips-linux-gnu-ld
LDFLAGS := -T $(LDSCRIPT) -T undefined_funcs_auto.txt -T undefined_syms_auto.txt --no-check-sections --accept-unknown-input-arch --emit-relocs -Map $(BUILD_DIR)/rom.map

default: $(BUILD_DIR)/rom.z64
.PHONY: default

$(BUILD_DIR)/%.o: %.s
	@mkdir -p $(dir $@)
	iconv -f UTF-8 -t EUC-JP $< | $(AS) $(ASFLAGS) -o $@

$(BUILD_DIR)/%.o: %.bin
	@mkdir -p $(dir $@)
	$(OBJCOPY) -I binary -O elf32-tradbigmips $< $@

$(BUILD_DIR)/%.o: %.c
	@mkdir -p $(dir $@)
	python3 ./tools/asm-processor/build.py --input-enc UTF-8 --output-enc EUC-JP $(IDO) -- $(AS) $(ASFLAGS) -- -I include/include_oot_cc0redo -c -G 0 -non_shared -fullwarn -verbose -Xcpluscomm -Wab,-r4300_mul -mips2 -O2 -o $@ $<

include thelegendofzelda.d

$(BUILD_DIR)/rom.elf: $(LDSCRIPT) undefined_funcs_auto.txt undefined_syms_auto.txt
	@mkdir -p $(dir $@)
	$(LD) $(LDFLAGS) -o $@

$(BUILD_DIR)/rom.z64: $(BUILD_DIR)/rom.elf
	@mkdir -p $(dir $@)
	$(OBJCOPY) -O binary $< $@
ifneq ($(COMPARE),0)
	md5sum -c checksum.md5
endif
