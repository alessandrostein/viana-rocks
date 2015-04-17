int i = 0;
TimeStruct ts1, ts2 ;

void main() {
     TRISB = 0b00000000;
     PORTB = 0b00000000;
     TRISD = 0b00000000;
     PORTD = 0b11111111;
     
     // ts1 =
     // diff = Time_dateDiff(&ts1, &ts2) ;    //  86163870
     // Pegar data atual e comparar até a diferença for 30 segundos

    // PORTB = 0b01010101
    while (i < 255) {
          PORTD = PORTD - 1;
          PORTB = PORTB + 1;
          Delay_ms(250);

          i++;
    }
}
