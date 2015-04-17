const float PERCENTUAL_DESLIGADO = 0.9;
const float PERCENTUAL_LIGADO = 0.1;
const float TOTAL = 1000;
float play_ms;

void main() {
     TRISC.RC1 = 0; //S
     PORTC.RC1 = 1; //OFF

     while (5) {
       PORTC.RC1 = 0; //ON
       Delay_ms((int)(TOTAL * PERCENTUAL_LIGADO));
       PORTC.RC1 = 1; //OFF
       Delay_ms((int)(TOTAL * PERCENTUAL_DESLIGADO));
     }

}
