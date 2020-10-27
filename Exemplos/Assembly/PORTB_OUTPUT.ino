/*Sistemas microcontrolados
   MCU: ATmega 328p F: 12 MHz
   Autor: Alysson Lima
   Pisca led
*/

//incluindo bibliotecas
#include <avr/io.h>  //biblioteca para acesso aos registradores do ATmega
#include "util/delay.h" //biblioteca delay da ling C


//funcao principal do codigo
int main (void) {
//regiao do void setup 
// PORTB - P7 até PB0
//DDRB - controla entradas e saidas
  //configura o pino 15 do microcontolador( pin 9 do arduino) como saida 
  DDRB = 0x22; // PB1 e PB5  sao saidas digital 0b00100010 = 0x22

  //criacao do void loop
  while (1) {
    PORTB = 0x22; //PB1 vai para nivel logico alto
    _delay_ms(1000); //espara 1s
    PORTB = 0x00; //PB1 vai para nivel logico LOW
    _delay_ms(1000); //espara 1s
  }// --- fim loop ---


}// ----fim main ----
