/*Sistemas Microcontrolados
*Prática 2 - Atividade 1
*Alunos: Daniel Santos - Moisés de Medeiros
*Professor: Alysson Lima
*/


// Definição das variaveis 
int EstadoMaquina, Controle = 0;
bool EstadoBotao = 0;


void setup() {
 pinMode(7,INPUT);// Botão como entrada no pino (7)
 pinMode(8,OUTPUT); // Led vermelho como saida no pino (8) 
}

void loop() {
  
  //Algoritimo que transforma o botão em não retentivo  
  if((digitalRead(7)) && (!EstadoBotao))
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
  EstadoBotao = digitalRead(7);

  
  
 switch(Controle) // Controle dos estados do botão
  {
 // Situação 01: Led Vermelho apagado  
    case 0 : 
        digitalWrite(8,LOW);
    break; 
// Ao pressionar o botão inicia-se a situação 02    
// Situação 02: Led piscando    
    case 1 :
        digitalWrite(8,HIGH);
        delay(100);
        digitalWrite(8,LOW);
        delay(100);
      break; 
//Ao precionar novamente 
//Situação 03: Led aceso 
    case 2:
        digitalWrite(8,HIGH);
    break; 
    
  }
}