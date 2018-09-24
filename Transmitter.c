unsigned char _data = 0x55;

void main() {
     TRISC = 0x00;
     PORTC = 0x00;
     UART1_Init(9600);
     Delay_ms(100);
     while(1) {
              if (UART1_Tx_Idle() == 1) {
                 UART1_Write(_data);
              }
     }
}