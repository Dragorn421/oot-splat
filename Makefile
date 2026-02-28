LDSCRIPT := thelegendofzelda.ld
BUILD_DIR := build

AS := mips-linux-gnu-as
ASFLAGS := -march=vr4300 -32 -no-pad-sections -Iinclude

OBJCOPY := mips-linux-gnu-objcopy

LD := mips-linux-gnu-ld
LDFLAGS := -T $(LDSCRIPT) -T undefined_funcs_auto.txt -T undefined_syms_auto.txt --no-check-sections --accept-unknown-input-arch --emit-relocs -Map $(BUILD_DIR)/rom.map

ASM_FILES := $(shell find asm -name '*.s')
ASSETS_FILES := $(shell find assets -name '*.bin')
O_FILES := \
  $(addprefix $(BUILD_DIR)/,$(ASM_FILES:.s=.o)) \
  $(addprefix $(BUILD_DIR)/,$(ASSETS_FILES:.bin=.o))

default: $(BUILD_DIR)/rom.z64
.PHONY: default

$(BUILD_DIR)/%.o: %.s
	@mkdir -p $(dir $@)
	iconv -f UTF-8 -t EUC-JP $< | $(AS) $(ASFLAGS) -o $@

$(BUILD_DIR)/%.o: %.bin
	@mkdir -p $(dir $@)
	$(OBJCOPY) -I binary -O elf32-tradbigmips $< $@

$(BUILD_DIR)/rom.elf: $(LDSCRIPT) $(O_FILES)
	$(LD) $(LDFLAGS) -o $@

$(BUILD_DIR)/rom.z64: $(BUILD_DIR)/rom.elf
	$(OBJCOPY) -O binary $< $@
	md5sum -c checksum.md5
