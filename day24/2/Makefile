CC=arm-linux-gcc
LD=arm-linux-ld
OBJCOPY=arm-linux-objcopy
OBJDUMP=arm-linux-objdump

TARGET=key.bin
ASM=start.S
CFILE=key.c
ELF=$(TARGET:.bin=.elf)
DIS=$(TARGET:%.bin=%.dis)
COBJS= $(CFILE:%.c=%.o)
SOBJS= $(ASM:%.S=%.o) 

$(TARGET):$(SOBJS) $(COBJS) 
	$(LD) -Ttext 0x20000000 -o $(ELF) $^
	$(OBJCOPY) $(ELF) -O binary $@
	$(OBJDUMP) -D $(ELF) > $(DIS)
	cp *.bin /mnt/hgfs/share/bin/

$(COBJS):%.o:%.c
	$(CC) -c $< -o $@ -Wall

$(SOBJS):%.o:%.S
	$(CC) -c $< -o $@ -Wall

clean:
	-$(RM) $(TARGET) $(ELF) $(DIS) $(COBJS) $(SOBJS)




