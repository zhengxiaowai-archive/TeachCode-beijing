void uart_init(void);
char uart_recv_byte(void);
void uart_send_byte(char c);
void uart_send_string(const char const *str);
void adc_test(void);
int main()
{
	char c;

	// ³õÊ¼»¯´®¿Ú 
	uart_init();	

	while (1)
	{
		adc_test();
		//c = uart_recv_byte();
		//uart_send_string("!!!this is a uart test!\n");
		//uart_send_byte('c');

	}

	return 0;
}
