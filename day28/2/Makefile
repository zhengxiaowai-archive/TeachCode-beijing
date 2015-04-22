 
pwm.bin: start.o clock.o main.o 
	arm-linux-ld -Ttext 0x0 -o pwm.elf $^
	arm-linux-objcopy -O binary pwm.elf $@
	arm-linux-objdump -D pwm.elf > pwm.dis
	gcc mkv210_image.c -o mkmini210
	./mkmini210 pwm.bin 210.bin
%.o : %.c
	arm-linux-gcc -c $< -o $@
%.o:%.S
	arm-linux-gcc -c $< -o $@

clean:
	rm *.o *.elf *.bin *.dis
