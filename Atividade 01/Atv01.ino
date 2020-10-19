
/* Sistema Microcontrolados
*  Alunos: Daniel Santos e Moisés de Medeiros
*  Professor: Alysson Lima
*/

//Define os pinos que serão utilizados
void setup()
{
  pinMode(7, INPUT);//entrada Botão pull down
  pinMode(8, OUTPUT);//Saída LED verde
  pinMode(9, OUTPUT);//Saída LED vermelho
}

//Loop infinito
void loop()
{
  digitalWrite(8,HIGH);//Ligando LED Verde
  delay(500);// 0,5s aceso
  digitalWrite(8,LOW);//Desligando LED Verde
  delay(500);// 0,5s apagado

  //Loop que será acionado enquanto o botão for pressionado
  while(digitalRead(7) == 0){
  digitalWrite(9, HIGH);//Liga LED vermelho
  digitalWrite(8,HIGH);//Liga LED Verde
  delay(500);// 0,5s aceso
  digitalWrite(8,LOW);//Desliga LED Verde
  delay(500);// 0,5s apagado  
  }
  digitalWrite(9, LOW);//Desliga LED vermelho
}
