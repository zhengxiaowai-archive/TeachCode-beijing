#define GPD0CON			*((volatile unsigned int *)0xE02000A0)
#define GPD0DAT			*((volatile unsigned int *)0xE02000A4)

#define TCFG0			*((volatile unsigned int *)0xE2500000)
#define TCFG1			*((volatile unsigned int *)0xE2500004)
#define TCON			*((volatile unsigned int *)0xE2500008)
#define TCNTB1			*((volatile unsigned int *)0xE2500018)
#define TCMPB1			*((volatile unsigned int *)0xE250001C)
#define TCNTO1			*((volatile unsigned int *)0xE2500020)

int main()
{
#if 0
	/* 配置GPD0[1]为输出 */
	GPD0CON &= ~(0xF << 4);
	GPD0CON |= 1 << 4;
	/* GPD0[1]输出高电平即可使蜂鸣器发声 */
	GPD0DAT |= 1 << 1;
#endif
	/* 配置GPD0[1]为定时器1输出:TOUT1 */
	GPD0CON &= ~(0xF << 4);//清空
	GPD0CON |= 2 << 4;//7:4位为0b 0010表示TOUT1功能，

	/*
	** 配置定时器输入频率，使用timer1
	** Timer Input Clock Frequency = PCLK / ( {prescaler value + 1} ) / {divider value} 
	** = 66MHz / (65 + 1) / 8 = 125000
	** 假设输出频率为n，则
	** TCNTB1 = 1125000 / n
	*/
	TCFG0 = 65;
	TCFG1 = 3 << 4; //7:4位为0011，表示1/8分频

	/* 产生1Hz,占空比为50%的输出频率 */
	TCNTB1 = 125000 / 1; //递减缓冲寄存器值为定时器输出频率=125000
	TCMPB1 = TCNTB1 / 2; //比较缓冲寄存器值为125000/2,控制占空比为50%

	TCON = (1 << 9);	/* 手动更新on */
	TCON = (1 << 8) | (1 << 11);	/* 启动定时器/手动更新off/自动重载开启 */

	while (1);
	
	return 0;
}