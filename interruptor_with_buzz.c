void play_buzz(){
     PORTC.RC1 = 0;
     PORTD = 0b00000100;
     Delay_ms(50);
     PORTC.RC1 = 1;
     PORTD = 0b00000000;
}

void main() {

     // Configurações Interruptor
     TRISB.RB2 = 1; // Entrada
     PORTB.RB2 = 0;
     
     // Configurações Led
     TRISD = 0b00000000;
     PORTD = 0b00000000;
     
     // Configurações Buzz
     TRISC.RC1 = 0; // Saída
     PORTC.RC1 = 1; //Deslgado

     while (1) {
           if (PORTB.RB2) {
              play_buzz();
           }
     }
}
