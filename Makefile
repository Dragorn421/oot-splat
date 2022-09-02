MAKEFLAGS += --no-builtin-rules

BINUTILS_PREFIX := mips-linux-gnu-

DECOMP := ../oot

CC     := $(DECOMP)/tools/ido_recomp/linux/7.1/cc
CC_OLD := $(DECOMP)/tools/ido_recomp/linux/5.3/cc

AS      := $(BINUTILS_PREFIX)as
LD      := $(BINUTILS_PREFIX)ld
OBJCOPY := $(BINUTILS_PREFIX)objcopy
OBJDUMP := $(BINUTILS_PREFIX)objdump

INC :=

OPTFLAGS := -O2
ASFLAGS := -march=vr4300 -32 -no-pad-sections -Iinclude
CFLAGS += -G 0 -non_shared -fullwarn -verbose -Xcpluscomm $(INC) -Wab,-r4300_mul -woff 516,649,838,712
MIPS_VERSION := -mips2

ROM := zelda_ocarina_mq_dbg.z64
ELF := $(ROM:.z64=.elf)

S_FILES   := $(wildcard asm/*.s)
BIN_FILES := $(wildcard assets/*.bin)
O_FILES   := $(foreach f,$(S_FILES:.s=.s.o),build/$f) $(foreach f,$(BIN_FILES:.bin=.bin.o),build/$f)

LINKER_SCRIPTS := thelegendofzelda.ld undefined_funcs_auto.txt undefined_syms_auto.txt

$(shell mkdir -p build/asm build/assets)

default: $(ROM)
	echo 'f0b7f35375f9cc8ca1b2d59d78e35405  $<' | md5sum -c -

.PHONY: default

$(ROM): $(ELF)
	$(OBJCOPY) -O binary $< $@

$(ELF): $(O_FILES)
	$(LD) $(foreach f,$(LINKER_SCRIPTS),-T $f) -Map linker_map.txt -o $@

build/asm/%.s.o: asm/%.s
	$(AS) $(ASFLAGS) $< -o $@

build/assets/%.bin.o: assets/%.bin
	echo '.section .data\n.incbin "$<"' > $(@:.o=.o.s)
	$(AS) $(ASFLAGS) $(@:.o=.o.s) -o $@

clean:
	rm -rf build
