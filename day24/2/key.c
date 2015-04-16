#define GPJ2CON		*((volatile unsigned long *)0xE0200280)
#define GPJ2DAT		*((volatile unsigned long *)0xE0200284)

#define GPH3CON		*( (volatile unsigned long*)0xE0200C60)
#define rGPH3DAT	*( (volatile unsigned long*)0xE0200C64)

void delay_key(volatile unsigned int t)  
{  
	volatile unsigned int t2 = 0xFFFF;  
	 while (t--)  
		 for (; t2; t2--);  
} 

void delay (int t)
{
	volatile int count = t;
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

void circle_on(unsigned int on)
{
	if(on == 1)
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

	return;
}
int main (int argc, char *argv[])
{
	volatile unsigned int key_val = 1;

	GPJ2CON |= (0x1 << 0 | 0x1 << 4 | 0x1 << 8 | 0x1 << 12);
	GPJ2DAT |= 0xF;
	
	GPH3CON &= ~(0xF << 12);
	
	while (1)
	{
		key_val = rGPH3DAT & 0x8;
		if(key_val == 0)
		{
			delay_key(50000);
			if(key_val == 0)
			{
				circle_on(1);
			}
		}
	}
	return 0;
}
