#define	GPC1CON *((volatile unsigned long *) 0xE0200060)
#define GPC1DAT *((volatile unsigned long *) 0xE0200064)
#define GPH0CON *((volatile unsigned long *) 0xE0200C00)
#define GPH0DAT *((volatile unsigned long *) 0xE0200C04)

void delay(volatile unsigned int t)  
{  
    volatile unsigned int t2 = 0xFFFF;  
    while (t--)  
        for (; t2; t2--);  
}  

int main(int argc, char *argv[])
{
	volatile int key_val = 0;
	//配置LED
	GPC1CON &= ~(0xF << 12); 
	GPC1CON |= (0x01<<12);

	//配置按键
	GPH0CON &= ~(0xF << 0);
	
	//关闭灯
	GPC1DAT &= ~(1 << 3);

	while(1)
	{
		key_val = GPH0DAT/*1*/ & 0x01;
		if(!key_val)
		{
			
			delay(500000);
			key_val = GPH0DAT & 0x1;
			
			//GPC1DAT ^= (1 << 3);
			if(!key_val)
			{
				GPC1DAT ^= 1 << 3;
			}
		}
	}
	return 0;
}
