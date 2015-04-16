#define GPJ2CON *((volatile unsigned long *)0xE0200280)
#define GPJ2DAT *((volatile unsigned long *)0xE0200284)

void delay (int r0)
{
	volatile int count = r0;
	while (count--);
}

void led(unsigned int count,unsigned int flag)
{
	
	if(count > 3 || count < 0)
		return;
	if(flag != 0 && flag != 1)
		return;

	
	/*flag == 1 关闭，0打开*/
	if(flag == 1)
	{
		switch(count)
		{
			case 0:
				GPJ2DAT |= (1 << count);
				break;
			case 1:
				GPJ2DAT |= (1 << count);
				break;
			case 2:
				GPJ2DAT |= (1 << count);
				break;
			case 3:
				GPJ2DAT |= (1 << count);
				break;
		}
	}
	else
	{
		switch(count)
		{
			case 0:
				GPJ2DAT &= ~(1 << count);
				break;
			case 1:
				GPJ2DAT &= ~(1 << count);
				break;
			case 2:
				GPJ2DAT &= ~(1 << count);
				break;
			case 3:
				GPJ2DAT &= ~(1 << count);
				break;
		}
	}
	return;
}

int main (int argc, char *argv[])
{
	GPJ2CON |= (0x1 << 0 | 0x1 << 4 | 0x1 << 8 | 0x1 << 12);
	GPJ2DAT |= 0xF;
	delay (0x100000);
	//GPJ2DAT &= ~(1 << 0);
	//led(0,0);
	while (1)
	{
#if 1
		led(0,0);
		delay (0x100000);
		led(0,1);
		delay (0x100000);

		led(1,0);
		delay (0x100000);
		led(1,1);
		delay (0x100000);
		
		led(2,0);
		delay (0x100000);
		led(2,1);
		delay (0x100000);

		led(3,0);
		delay (0x100000);
		led(3,1);
		delay (0x100000);
#endif
	}
	return 0;
}
