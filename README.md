void main() {

     TRISC.RC1 = 0; //S
     TRISC.RC0 = 0; //S

     while (5) {
           PORTC.RC0 = 1;
           PORTC.RE0 = 0;
           Delay_ms(1000);
           PORTC.RC0 = 0;
           PORTC.RE0 = 1;
           Delay_ms(1000);
     }

}
