		// not final
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
