#define	GPC1CON *((volatile unsigned long *)0xE0200060)
#define GPC1DAT *((volatile unsigned long *)0xE0200064)

int main(int argc, char *argv[])
{
	GPC1CON &= ~(0x0F << 12);
	GPC1CON |= (0x01 << 12);

	GPC1DAT ^= 1 << 3;
	while(1);
	return 0;
}
