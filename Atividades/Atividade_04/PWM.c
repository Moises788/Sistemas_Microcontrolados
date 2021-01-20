#include<avr/io.h>
#include<util/delay.h>

//invejosos dirão ser uma cópia do digitalWrite
void escreve_o_analogico(int pino, int PWM) {
  //condição para configurar o pino desejado
  switch (pino) {
    case 3:
      TCCR2A |= (1 << WGM21) | (1 << WGM00);  // modo rapido
      TCCR2B |= (1 << CS21); // F/8
      TCCR2A |= (1 << COM2B1); // canal B modo clear
      OCR2B = PWM;

      break;
    case 11:
      TCCR2A |= (1 << WGM21) | (1 << WGM00);  // modo rapido
      TCCR2B |= (1 << CS21); // F/8
      TCCR2A |= (1 << COM2A1); // canal B modo clear
      OCR2A = PWM;
    
      break;
    case 10:
      ICR1 = 0xFFFF;
      TCCR1B |= (1 << WGM13) | (1 << WGM12);
      TCCR1A |= (1 << WGM11);
      TCCR1B |= (1 << CS10); // F/64
      TCCR1A |= (1 << COM1B1); // canal a pino 9 modo clear
	    OCR1B = PWM;
      break;
  }
}

int main(void) {
  //definindo saídas PWM
  DDRB = (1 << PB3) | (1 << PB2);
  DDRD = (1 << PD3);

  while (1) {
    
    escreve_o_analogico (3, 255);
    escreve_o_analogico (11, 255);
    escreve_o_analogico (10, 500);
  }
}