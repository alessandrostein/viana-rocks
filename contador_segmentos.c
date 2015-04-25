int count;

unsigned short mask(unsigned short num) {
   switch (num) {
          case 0: return 0x3F; break;
          case 1: return 0x06; break;
          case 2: return 0x5B; break;
          case 3: return 0x4F; break;
          case 4: return 0x66; break;
          case 5: return 0x6D; break;
          case 6: return 0x7D; break;
          case 7: return 0x07; break;
          case 8: return 0x7F; break;
          case 9: return 0x6F; break;
          default: return 0x00; break;
   }
}

void main() {
  ADCON1 = 0x07;
  count = 0;
  
  TRISA.RA2 = 0; // Saída
  TRISA.RA3 = 0; // Saída
  TRISA.RA4 = 0; // Saída
  TRISA.RA5 = 0; // Saída
  
  TRISD = 0X00; // Saída

  PORTA.RA2 = 1; // Módulo Display Ligado
  PORTA.RA3 = 1; // Módulo Display Ligado
  PORTA.RA4 = 0; // Módulo Display Desligado
  PORTA.RA5 = 1; // Módulo Display Ligado

  PORTD = 0b00000000;
  //        hgfedcba
  // Pode-se configurar também em Hexadecimal, por exemplo
  // PORTD = 0x07
  
  while (count < 10) {
        count = count + 1;
        PORTD = mask(count);
        Delay_ms(500);
        if (count == 9) count = -1;
  }
  
}
