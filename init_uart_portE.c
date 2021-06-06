		void uart_init(void) 			// initializing UART portE (rx)
		{
		SYSCTL_RCGCUART_R |= 0x0010;
		SYSCTL_RCGCGPIO_R |= 0x10;
		UART7_CTL_R &= ~0x0001; //disable uart_ctl_r
		UART7_IBRD_R = 104; 
		UART7_FBRD_R = 11;
		UART7_LCRH_R = 0x0070;
		UART7_CTL_R = 0x0201;
		GPIO_PORTE_AFSEL_R |= 0x01;
		GPIO_PORTE_PCTL_R  = (GPIO_PORTE_PCTL_R&0xFFFFFFF0)|0x00000001;
		GPIO_PORTE_DEN_R |= 0x01;
		GPIO_PORTE_AMSEL_R &= ~0x01;
		}
		
		
		void uart_init(void) 			// initializing UART portE e0,e1 (rx,tx)
	  {
		SYSCTL_RCGCUART_R |= 0x0010;
		SYSCTL_RCGCGPIO_R |= 0x10;
		UART7_CTL_R &= ~0x0001; //disable uart_ctl_r
		UART7_IBRD_R = 104; 
		UART7_FBRD_R = 11;
		UART7_LCRH_R = 0x0070; // 8-bit word length, enable FIFO
		UART7_CTL_R = 0x0301; // enable RXE, TXE and UART
		GPIO_PORTE_AFSEL_R |= 0x03; // enable alt funct on PE1-0
		GPIO_PORTE_PCTL_R  = (GPIO_PORTE_PCTL_R&0xFFFFFF00)|0x00000011;
		GPIO_PORTE_DEN_R |= 0x03; // enable digital I/O on PE1-0
		GPIO_PORTE_AMSEL_R &= ~0x03; // disable analog function on PE1-0
		}
		
		
		char* init_Rx()
        {
        int i;
        while(1){
        while ((UART7_FR_R & 0x0010) != 0 ){};
        static char x[100];
        for( i=0; i<100; i++)
        {
            x[i] = UART7_DR_R;
            return x;}
        }}
		
		
		
		// Wait for new input, then return ASCII code	
		char UART_InChar(void){
		while((UART7_FR_R&0x0010) != 0); // wait until RXFE is 0
		return((char)(UART7_DR_R&0xFF));
		}
		// Wait for buffer to be not full, then output
		void UART_OutChar(char data){
		while((UART7_FR_R&0x0020) != 0); // wait until TXFF is 0
		UART7_DR_R = data;
		}