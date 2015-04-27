#define GPA0CON 		( *((volatile unsigned long *)0xE0200000) )		
#define GPA1CON 		( *((volatile unsigned long *)0xE0200020) )

// UART��ؼĴ���
#define ULCON0 			( *((volatile unsigned long *)0xE2900000) )		
#define UCON0 			( *((volatile unsigned long *)0xE2900004) )
#define UFCON0 			( *((volatile unsigned long *)0xE2900008) )
#define UMCON0 			( *((volatile unsigned long *)0xE290000C) )
#define UTXH0 			( *((volatile unsigned long *)0xE2900020) )
#define URXH0 			( *((volatile unsigned long *)0xE2900024) )
#define UBRDIV0 		( *((volatile unsigned long *)0xE2900028) )
#define UDIVSLOT0 		( *((volatile unsigned long *)0xE290002C) )
#define UTRSTAT0 		( *((volatile unsigned long *)0xE2900010) )
#define UART_UBRDIV_VAL		34
#define UART_UDIVSLOT_VAL	0xDDDD

// ��ʼ������ 
void uart_init()
{
	//����GPIO�Ǵ���ģʽ
	GPA0CON |= (2 << 0 | 2 << 4);
	// ʹ��fifo
	UFCON0 = 0x1;
	// ������
	UMCON0 = 0x0;
	// ����λ:8, ��У��, ֹͣλ: 1
	ULCON0 = 0x3;
	// ʱ�ӣ�PCLK����ֹ�жϣ�ʹ��UART���͡�����
	UCON0  = 0x5;  				

	// 3 ���ò�����
	UBRDIV0 = UART_UBRDIV_VAL;
	UDIVSLOT0 = UART_UDIVSLOT_VAL;
}

// ����һ���ַ� 
char uart_recv_byte(void)
{
	while (!(UTRSTAT0 & (1<<0)));
	
	return URXH0;                   	
}

// ����һ���ַ�
void uart_send_byte(char c)
{
	while (!(UTRSTAT0 & (1<<2)));

	UTXH0 = c;
	//while(1);
}

//����string
void uart_send_string(const char const *str)
{
	const char *p = str;
	while(*p)
		uart_send_byte(*p++);
}

void uart_send_num(unsigned int num)		//��������
{
	char unit,tens,hunds,thund;
	
	unit = '0' + num%10;
	tens = '0' + num/10%10;
	hunds ='0' + num/100%10;
	thund ='0' + num/1000%10;
	
	uart_send_byte(thund);
	uart_send_byte(hunds);
	uart_send_byte(tens);
	uart_send_byte(unit);
	uart_send_byte('\r\n');
}
