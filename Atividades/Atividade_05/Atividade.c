#include <avr/io.h>
#include <util/delay.h>
#include <LiquidCrystal.h> 

// Definir variaveis 
int Sensor = A0;
int DigitalVRers = 0;
float realVRers = 0;
int Motor1 = 2 ;
int Motor2 = 3;
int i = 0;
bool controle = 0;

//                 RS, E, D4, D5 , D6, D7
LiquidCrystal lcd(8, 9, 10, 11, 12, 13);  

void escreve_tela(uint16_t valor)
{
     lcd.clear();
    //escolhe linha e coluna de escrita
    lcd.setCursor (2,0);
    lcd.print("Quantidade:");
    lcd.setCursor(8,1);
    lcd.print("L ");
    lcd.setCursor(4,1);
    lcd.print(valor);
    _delay_ms(100);
}

uint16_t ler_o_analogico(uint8_t channel)
{
  ADMUX &= ~0b11110000;         //Limpa os bits de canal
  ADMUX |= channel;   //Defines the new ADC channel to be read by setting bits MUX0-2
  ADCSRA |= (1<<ADSC);      //Inicia a nova conversÃ£o
  while(ADCSRA & (1<<ADSC));  //Espera atÃ© ela ser realizada
  return ADCW; //Retorna o valor convertido
}        

int main(){
  
  DDRD = 0x12;
  DDRB = 0xFF;
  ADCSRA |= ((1<<ADPS2)|(1<<ADPS1)|(1<<ADPS0)); //Divide o clock por 128
  ADMUX  |= (1<<REFS0);       //TensÃ£o de referÃªncia de 5V
  ADCSRA |= (1<<ADEN);       //Habilita o ADC
  ADCSRA |= (1<<ADSC);     //Inicia a conversÃ£o
  
  uint16_t valor;
  // inicia LCD
  lcd.begin(16,2); //inicia o monitor serial
  while(1)
  {
    //Medição do reservatório   
    DigitalVRers = ler_o_analogico(0); //invejosos dirão ser uma cópia da função digitalRead
    realVRers = DigitalVRers * 1.953125; //valor real
  
    //Printando valores no monitor serial
    escreve_tela(realVRers);
    
    /*Oseguínte algorítimo utiliza a variável "i" como
    refência para escolher qual motor irá ligar. A variável 
    "controle" para evitar bug na execução do software.
    */
    if((DigitalVRers <= 255)&&(i==0))
  	{
        PORTD = 0X08;  
        controle = true;  
  	}
    else if((DigitalVRers <= 255)&&(i==1))
  	{
        PORTD = 0X04;
        controle = true; 
  	}
    else if ((DigitalVRers == 1023)&&(controle))
  	{
        PORTD = 0X00;
        i++;
        controle = false;
        if (i>1)
  	    {
            i = 0;
  	    }	
  	}
  }
} 