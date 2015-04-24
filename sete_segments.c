void main() {
  ADCON1 = 0x07;
  
  TRISA.RA2 = 0; // Saída
  TRISA.RA3 = 0; // Saída
  TRISA.RA4 = 0; // Saída
  TRISA.RA5 = 0; // Saída
  
  TRISD = 0X00; // Saída

  PORTA.RA2 = 1; // Módulo Display Ligado
  PORTA.RA3 = 1; // Módulo Display Ligado
  PORTA.RA4 = 0; // Módulo Display Desligado
  PORTA.RA5 = 1; // Módulo Display Ligado

  PORTD = 0b10000111;
  //        hgfedcba
  // Pode-se configurar também em Hexadecimal, por exemplo
  // PORTD = 0x07
}
