//led
#define GPJ2CON				*((volatile unsigned long *)0xE0200280)
#define GPJ2DAT				*((volatile unsigned long *)0xE0200284)

//key K1 GPH2_0
#define GPH2CON     				*((volatile unsigned long *)0xE0200C40)  
#define GPH2DAT     				*((volatile unsigned long *)0xE0200C44)  

//外中断0-7的中断控制寄存器 
#define EXT_INT_2_CON       *((volatile unsigned int *)0xE0200E08)
//外中断0-7的中断屏蔽寄存器  
#define EXT_INT_2_MASK      *((volatile unsigned int *)0xE0200F08 )  
//第一组矢量中断选择寄存器  
#define VIC0INTSELECT       *((volatile unsigned int *)0xF200000C) 
//第一组矢量中断使能寄存器 
#define VIC0INTENABLE       *((volatile unsigned int *)0xF2000010)  
  
#define VIC0VECTADDR16       *((volatile unsigned int *)0xF2000140)  
  
#define VIC0ADDRESS         *((volatile unsigned int *)0xF2000F00)  
//外部中断0-7的中断挂起寄存器，记录是否有中断产生
#define EXT_INT_2_PEND       *((volatile unsigned int *)0xE0200F48 )  
  
void led(unsigned int count,unsigned int flag);
extern void key_isr(void); //抛出为外部可用标记，提供给.s文件使用
  
void key_handle()  
{     

    volatile unsigned char key_code = EXT_INT_2_PEND & 0x1;  
      
    VIC0ADDRESS = 0;        /* 清中断向量寄存器 */  
    EXT_INT_2_PEND |= 1;    /* 清中断挂起寄存器 */  
      
    if (key_code == 1)      /* key1 */  
        GPJ2DAT ^= 1 ;    /* toggle LED1 */  

}  
  
int main()  
{  
    GPJ2CON |= (0x1 << 0 | 0x1 << 4 | 0x1 << 8 | 0x1 << 12);//配置灯
	GPJ2DAT |= 0xF;
    GPH2CON |= 0xF << 0;                 /* 配置K1*/  
      
    EXT_INT_2_CON &= ~(0xF << 0);  			/* 清空低四位*/
    EXT_INT_2_CON |= (2 << 0);          /* 配置EXT_INT[16]为下降沿触发*/  
    EXT_INT_2_MASK &= ~(1 << 0);                   /* 取消屏蔽外部中断EXT_INT[0]和EXT_INT[1] */  
      
    VIC0INTSELECT &= ~(1 << 16);                    /* 选择外部中断EXT_INT[0]和外部中断EXT_INT[1]为IRQ类型的中断 */  
      
    VIC0INTENABLE |= (1 << 16);                     /* 使能外部中断EXT_INT[0]和EXT_INT[1] */  
      
    VIC0VECTADDR16 = (int)key_isr;            
     
	led(1,0);
    while (1);  
      
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
