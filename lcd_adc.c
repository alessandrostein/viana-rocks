// LCD module connections
sbit LCD_RS at RE2_bit;
sbit LCD_EN at RE1_bit;
sbit LCD_D4 at RD4_bit;
sbit LCD_D5 at RD5_bit;
sbit LCD_D6 at RD6_bit;
sbit LCD_D7 at RD7_bit;

sbit LCD_RS_Direction at TRISE2_bit;
sbit LCD_EN_Direction at TRISE1_bit;
sbit LCD_D4_Direction at TRISD4_bit;
sbit LCD_D5_Direction at TRISD5_bit;
sbit LCD_D6_Direction at TRISD6_bit;
sbit LCD_D7_Direction at TRISD7_bit;
// End LCD module connections

char *text_a[7] = "";
char *text_b[7] = "";
long voltagem;
unsigned int count;
char ch;

void main(){
  ADCON1 = 0x8e;

  TRISA.RA0 = 1; // Entrada
  
  TRISB = 0b00000000; // Saída
  PORTB = 0b00000000;

  Lcd_Init();                        // Initialize LCD
  Lcd_Cmd(_LCD_CLEAR);               // Clear display
  Lcd_Cmd(_LCD_CURSOR_OFF);          // Cursor off
  Lcd_out(1,1,"CONTAGEM: ");
  Lcd_out(2,1,"TENSAO: ");
  while (1) {
    count = ADC_Read(0);
    voltagem = (long)count * 5000;
    voltagem = voltagem / 1023;
    
    ch = voltagem / 1000;
    
    IntToStr(count, text_a);
    Lcd_out(1,11, text_a);
    
    // IntToStr(ch, text_b);
    Lcd_Chr(2,9, 48 + ch);
    
    if (ch >= 3) {
     PORTB = 0b11111111;
    } else {
     PORTB = 0b00000000;
    }
    Lcd_out(2,10, ",");
    ch = voltagem / 100 % 10;
    Lcd_Chr(2,11, 48 + ch);
    ch = voltagem / 10 % 10;
    Lcd_Chr(2,12, 48 + ch);
    Lcd_out(2,13, "V");
    
    Delay_1ms();
    
  }
}
