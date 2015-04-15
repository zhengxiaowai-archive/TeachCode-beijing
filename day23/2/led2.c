#define GPJ2CON *((volatile unsigned long *)0xE0200280)
#define GPJ2DAT *((volatile unsigned long *)0xE0200284)

int main(int argc, char *argv[])
{
		GPJ2CON &= ~(0x0F << 12);
		GPJ2CON |= (0x1 << 4 );
 
		GPJ2DAT |= (1 << 0);

		while(1);
		return 0;
}
