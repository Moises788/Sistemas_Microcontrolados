#include <avr/io.h>
#include <util/delay.h>

int EstadoMaquina, Controle = 0;
bool EstadoBotao = 0;

int main(void) 
{
   DDRB = 0x01;
   //PB1 = 9 definido como entrada
   //PB0 = 8 definido como saída
  while(1) 
  {
  //Algoritimo que transforma o botão em não retentivo  
    if( (PINB & 0x2) && (!EstadoBotao))
    {
    /*soma variável referente ao estado da máquina
   	  e atribui o seu valor para a variável controle
     */
    EstadoMaquina++;
    Controle = EstadoMaquina;
    
    /*Condições para voltar os estados e reiniciar
      o o valor da variável quando chegar no estado
      inicial
     */
    if(EstadoMaquina == 3){
      Controle = 1;
    }
    else if (EstadoMaquina == 4)
    {
      Controle = 0;
      EstadoMaquina = 0;
    }
    
  }
 
    EstadoBotao =  (PINB & 0x2);
    switch(Controle) // Controle dos estados do botão
    {
      // Situação 01: Led Vermelho apagado  
      case 0 : 
        PORTB = (0<<PB0);
      break; 
      // Ao pressionar o botão inicia-se a situação 02    
      // Situação 02: Led piscando    
      case 1 :
        PORTB ^= (1<<PB0);
        _delay_ms(100);
      break; 
      //Ao precionar novamente 
      //Situação 03: Led aceso 
      case 2:
        PORTB ^= (1<<PB0);
      break; 
    
    }
  }
}