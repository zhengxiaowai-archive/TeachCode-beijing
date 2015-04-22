#define 	WTCON 			(*(volatile unsigned long *) 0xE2700000)
#define 	WTDAT			(*(volatile unsigned long *) 0xE2700004)
#define 	WTCNT			(*(volatile unsigned long *) 0xE2700008)

#define GPJ2CON				*((volatile unsigned long *) 0xE0200280)
#define GPJ2DAT				*((volatile unsigned long *) 0xE0200284)
void init_watchdog()
{
	//15625hz
	WTCON = ((1 << 0) | (1 << 3) | (1 << 5) | ( 131 << 8) );
	WTDAT  = 20625; //15625 + 5000
	WTCNT  = 20625; 
}

void feed_dog()
{
	WTCNT  = 20625;
}

void delay()
{
	while(1)
	{
		if(WTCNT < 5000)
			return;
	}
}
int main(int argc, char *argv[])
{
	GPJ2CON |= (0x1 << 0 | 0x1 << 4 | 0x1 << 8 | 0x1 << 12);//配置灯
	GPJ2DAT |= 0xF;
	init_watchdog();
	while(1)
	{
		GPJ2DAT ^= 1 ;
		delay();
		feed_dog();
	}
	return 0;
}
