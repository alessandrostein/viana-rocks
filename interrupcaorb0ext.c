// THE FOLLOWING SIMPLE PROGRAM CREATES A FUNCTION WITH A DELAY OF "t" sec
// USING TIMER0
// ==========================================================================
// BEFORE WE PROCEED TO SOME CALCULATIONS ON TIMER0:
/* Calculating Count, Fout, and TMR0 values
IF USING INTERNAL CLOCK, THE DIVISION IS PERFORMED AS FOLLOW:
PIC TIMER0 FORMULA FOR INTERNAL CLOCK:

fOUT = fCLK / (4 * PRESCALER *(256 - TMR0)* COUNT)

Fout             THE OUTPUT FREQUENCY AFTER THE DIVISION.
Tout             THE CYCLE TIME AFTER THE DIVISION.
4                THE DIVISION OF THE ORIGINAL CLOCK (4 MHz) BY 4, WHEN USING
                 INTERNAL CRYSTAL AS CLOCK (AND NOT EXTERNAL OSCILLATOR).
COUNT            A NUMERIC VALUE TO BE PLACED TO OBTAIN THE DESIRED OUTPUT 
                 FREQUENCY - FOUT.
(256 - TMR0)     THE NUMBER OF TIMES IN THE TIMER WILL COUNT BASED ON THE 
                 REGISTER TMR0.
// ==========================================================================
AN EXAMPLE OF INTERNAL CLOCK
SUPPOSE WE WANT TO CREATE A DELAY OF 0.5 SECOND IN THE OUR PROGRAM USING
TIMER0. WHAT IS THE VALUE OF COUNT?
CALCULATION:
FIRST, LET’S ASSUME THE FREQUENCY DIVISION BY THE PRESCALER WILL BE 1:256
SECOND, LET’S SET TMR0 = 0. THUS:

fOUT = fCLK / (4 * PRESCALER *(256 - TMR0)* COUNT) = 2 Hz (DESIRED)

COUNT = fCLK / (4 * PRESCALER *(256 - TMR0)* fOUT) = 
      = 4 MHz / (4 * 256 *(256 - 0)* 2 Hz) = 7.63 =~ 8 = COUNT
// ==========================================================================
NOW FOR MICROGENIOS PIC18F KIT AND FOR 0.5 SECONDS
COUNT = fCLK / (4 * PRESCALER *(256 - TMR0)* fOUT) =
      = 8 MHz / (4 * 256 *(256 - 0)* 2 Hz) =~ 15 = COUNT                   */
// ==========================================================================
// FUNCTION USING TIMER 1 TO WAIT t SECONDS ==> MICROGENIOS PIC18F KIT
void WaitForSec(unsigned int t){ 
int count = 0; 
TMR0 = 0; // Configura o Timer iniciar em 0
OPTION_REG.T0CS = 0; // Configura o Timer para usar o Oscilador interno
OPTION_REG.T0SE = 0; // Configura se a borda é de subida(0) ou descida(1).
OPTION_REG.PSA = 0; // Configura o Prescaler para usar o Time0 module -> Se for 0 -> Watch Dog Timer
OPTION_REG.PS0 = 1; // Configura a faixa (escala) de seleção
OPTION_REG.PS1 = 1; // Configura a faixa (escala) de seleção
OPTION_REG.PS2 = 1; // Configura a faixa (escala) de seleção

//PS0, PS1, PS2
//  1    1    1 = 1:256

  while (1){
     while (!INTCON.T0IF);  // Flag de Interrupção do Temporizador 0

    INTCON.T0IF = 0;            // Reset bit TMR1IF -> Limpa a Flag da Interrupção do Temporizador 0
    count ++;
    if (count == 30 * t){ 
    //5 segundos * 30 = 150 * 256 = 38400 ciclos de máquina
    // 5 - 38400
    // 1 - X
    // 5X = 38400
    // 7680 é equivalente a 1 segundo.
      count = 0; break;
    }
  }
}
// ==========================================================================
// MAIN FUNCTION TO TEST THE WaitForSec() FUNCTION
void main (){
ADCON1 = 0x06; // Configura tudo para digital

TRISB = 0x00; // Configura TRISB como saída
PORTB = 0xF0; // Configura PORTB (4 Leds ligados)

TRISD = 0x00; // Configura TRISB como saída
PORTD = 0x0F; // Configura PORTB (4 Leds ligados)

while (1){ WaitForSec(1); /*PORTB++*/ PORTB = ~PORTB; PORTD = ~PORTD;}}
// ==========================================================================
