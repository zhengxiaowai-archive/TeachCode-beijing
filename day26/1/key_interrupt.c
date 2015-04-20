#define GPJ2CON				*((volatile unsigned long *)0xE0200280)
#define GPJ2DAT				*((volatile unsigned long *)0xE0200284)

#define GPH3CON				*( (volatile unsigned long*)0xE0200C60)
#define GPH3DAT				*( (volatile unsigned long*)0xE0200C64)

#define EXT_INT_3_CON		*( (volatile unsigned long *)0xE0200E0C )
#define EXT_INT_3_MASK		*( (volatile unsigned long *)0xE0200F0C )
//EXT_INT[24]  gph3_0
#define VIC0INTSELECT 		*( (volatile unsigned long *)0xF200000C)
#define VIC0INTENABLE 		*( (volatile unsigned long *)0xF2000010)
#define VIC0ADDRESS         *( (volatile unsigned long *)0xF2000F00)
#define VIC0VECTADDR24		*( (volatile unsigned long *)0xF2000160)

#define EXT_INT_3_PEND      *( (volatile unsigned long *)0xE0200F4C )
extern void key_isr(void); 

void led(unsigned int count,unsigned int flag);
void key_handle()
{
	led(1,0);
	//VIC0ADDRESS = 0;
	led(0,0);
}




int main(int argc, char *argv[])
{
	GPJ2CON |= (0x1 << 0 | 0x1 << 4 | 0x1 << 8 | 0x1 << 12);//config led:
	GPJ2DAT |= 0xF;//close all leds
	GPH3CON |= (0xF);//config key_interrupt 
	
	EXT_INT_3_CON &= ~(0x7 << 0);//clear EXT_INT_3_CON[3]
	EXT_INT_3_CON |=(0x2 << 0);//set EXT_INT_3_CON[3] for faling 
	EXT_INT_3_MASK &= ~(1 << 0);//open EXT_INT[24]

	VIC0INTSELECT &= ~(0x1 << 24);//open IRQ for EXT_INT[16]
	VIC0INTENABLE |= (1 << 24);//open interrupt
	VIC0VECTADDR24 = (int)key_isr;
	led(3,0);
	while(1);




	return 0;
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
