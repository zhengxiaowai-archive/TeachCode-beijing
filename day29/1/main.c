void uart_init(void);

int main()
{
	char c;

	// ³õÊ¼»¯´®¿Ú 
	uart_init();	

	while (1)
	{

		c = uart_recv_byte();
		uart_send_string("!!!this is a uart test!\n");
		//uart_send_byte('c');

	}

	return 0;
}
