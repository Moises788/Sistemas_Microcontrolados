/*Sistemas Microcontrolados
*Prática 4
*Alunos: Daniel Santos - Felipe Augusto - Moisés de Medeiros
*Professor: Alysson Lima
*/

#include <avr/io.h>
#include <avr/interrupt.h>

int Controle, overflow = 0;
bool EstadoBotao = 0;

void timer0_init()
{
TCCR0B = 0x05; 
TCNT0 = 0;
TIMSK0 = 0x01;
overflow = 0;
sei();
}

ISR(TIMER0_OVF_vect)
{
  if((PINB & 0x02) && (!EstadoBotao))
  {
    Controle++;
    if(Controle == 4)
    {
      Controle = 0;
    }
    overflow = 0;
  }
                 
  EstadoBotao = (PINB & 0x02);
  overflow++;
  
  if(Controle == 0)
  {
    PORTB = (0<<PB0);
    overflow = 0;
  }
  else if((overflow == 30) && ((Controle == 1)||(Controle == 3)))
  { 
    // 0.5 segundos
    PORTB ^= (1<<PB0);
    overflow = 0;
  }

  else if ((overflow == 120) && (Controle == 2))
  {
    // 2 segundos
    PORTB ^= (1<<PB0);
    overflow = 0;
  }
}

int main(void) 
{
  timer0_init();
  DDRB = 0x01;
  //PB1 = 9 definido como entrada
  //PB0 = 8 definido como saída
  while(1) 
  {  
  }
}