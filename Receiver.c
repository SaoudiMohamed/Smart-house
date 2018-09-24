unsigned char receive = 0x00;
unsigned char key = 0x55;

void main() {
     TRISC = 0xFF;
     TRISE = 0x00;
     PORTE = 0x00;
     UART1_Init(9600);
     Delay_ms(100);
     while(1)
     {
              if(PORTC.RC0) {
                  if(UART1_Data_Ready() == 1) {
                                        receive = UART1_Read();
                  }
              }
              while(receive == key) {
                       if((PORTC.RC0) && (PORTC.RC3)) {
                             PORTE.RE0 = 1;
                         }
                       else if((PORTC.RC2) && (PORTC.RC0)) {
                             PORTE.RE0 = 0;
                         }
                       else if((PORTC.RC2) && !(PORTC.RC1) && !(PORTC.RC0)) {
                              PORTE.RE1 = 1;
                         }
                       else if((PORTC.RC3)) {
                              PORTE.RE1 = 0;
                         }
                  }
     }
}