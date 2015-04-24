void main() {

 ADCON1 = 0x07;
 TRISD = 1;

 TRISD = 1; // Saída

 PORTD.RD2 = 1; // Display Ligado
 PORTD.RD3 = 0; // Display Desligado
 PORTD.RD4 = 0; // Display Desligado
 PORTD.RD5 = 0; // Display Desligado

 PORTD = 0b01100110;
 //        hgfedcba
}
