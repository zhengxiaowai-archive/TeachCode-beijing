#define	GPC1CON *((volatile unsigned long *) 0xE0200060)
#define GPC1DAT *((volatile unsigned long *) 0xE0200064)
#define GPH0CON *((volatile unsigned long *) 0xE0200C00)
#define GPH0DAT *((volatile unsigned long *) 0xE0200C04)

void delay_key(volatile unsigned int t)  
{  
    volatile unsigned int t2 = 0xFFFF;  
    while (t--)  
        for (; t2; t2--);  
} 

void delay_s(int time)
{
	int i, j;
	for(i = 0; i < time; i++)
	{
		for(j = 0; j <0xfffff; j++);
	}
	return;
}

void circle_on(unsigned int on)
{
	if(on == 1)
	{
		while(1)
		{
			GPC1DAT |= (1 << 3);
			delay_s(1);
			GPC1DAT &= ~(1 << 3);
			delay_s(1);
			GPC1DAT |= (1 << 4);
			delay_s(1);
			GPC1DAT &= ~(1 << 4);
			delay_s(1);
			
		}
	}
	else if( on == 0)
	{
		GPC1DAT &= ~(1 << 3 | 1  << 4);
	}
	else
		return;
}
int main(int argc, char *argv[])
{
	volatile int key_val = 0;
	/*ÅäÖÃµÆºÍ°´¼ü*/
	GPC1CON &= ~(0xFF << 12); 
	GPC1CON |=( (0x01<<12) | (0x01<<16) );
	
	GPH0CON &= ~(0xF << 0);

	/*¹Ø±ÕµÆ*/
	circle_on(0);
	
	GPC1DAT |= (1 << 3);
	delay_s(3);
	GPC1DAT &= ~(1 << 3);
	delay_s(3);
	GPC1DAT |= (1 << 4);
	delay_s(3);
	GPC1DAT &= ~(1 << 4);
	while(1)
	{
		key_val = GPH0DAT & 0x01;
		if(!key_val)
		{
			key_val = GPH0DAT & 0x01;
			delay_key(500000);
			if(!key_val)
			{
				circle_on(1);
			}
		}
	}
	return 0;
}