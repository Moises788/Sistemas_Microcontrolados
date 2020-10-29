/*
Autor: Moisés de Medeiros
ATmega328p
Pisca LED
*/


#include <avr/io.h>
#include <util/delay.h>

//Função principal
int main (void){
  DDRB = 0x07; //configura registrador como saídas digitais
while (1)
  { //Realiza deslocamento de bits
    for (int i = 0; i < 3; i++)
    {
      PORTB = 1 << i;
      _delay_ms(500);
    }
    //Liga os 3 LEDs ao mesmo tempo e desliga em seguida
    PORTB = 0X07;
    _delay_ms(500);
    PORTB = 0X00;
    _delay_ms(500);
  }
}



