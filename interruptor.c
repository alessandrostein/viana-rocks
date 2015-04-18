void main() {

     // Configurações
     TRISD = 0b00000000;
     TRISB.RB2 = 1; // Entrada
     PORTD = 0b00000000;

     while (1) {
           if (PORTB.RB2){
             PORTD = 0b11111111;
           } else {
             PORTD = 0b11111011;
           }

     }
}
