LDSCRIPT := thelegendofzelda.ld
BUILD_DIR := build

AS := mips-linux-gnu-as
ASFLAGS := -march=vr4300 -32 -no-pad-sections -Iinclude

OBJCOPY := mips-linux-gnu-objcopy

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

include thelegendofzelda.d

$(BUILD_DIR)/rom.elf: $(LDSCRIPT) undefined_funcs_auto.txt undefined_syms_auto.txt
	@mkdir -p $(dir $@)
	$(LD) $(LDFLAGS) -o $@

$(BUILD_DIR)/rom.z64: $(BUILD_DIR)/rom.elf
	@mkdir -p $(dir $@)
	$(OBJCOPY) -O binary $< $@
	md5sum -c checksum.md5
