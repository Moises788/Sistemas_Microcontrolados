/*Sistemas Microcontrolados
*Prática 2 - Atividade 2
*Alunos: Daniel Santos - Moisés de Medeiros
*Professor: Alysson Lima
*/

// Definir variaveis 
int Sensor = A0;
int DigitalVRers = 0;
float realVRers = 0;
int Motor1 = 8 ;
int Motor2 = 7;
int i = 0;
bool controle = 0;

void setup()
{
  pinMode(Sensor, INPUT); //define o sensor como entrada
  pinMode(Motor1, OUTPUT); //define o LedVerde como saída
  pinMode(Motor2, OUTPUT);//define o LedVermelho como saída
  Serial.begin(9600); //inicia o monitor serial
 
}

void loop()
{
  //Medição do reservatório   
  DigitalVRers = analogRead(A0); //valor digital
  realVRers = DigitalVRers * 1.953125; //valor real
  
  //Printando valores no monitor serial
  Serial.print("Valor digital do reservatorio:");
  Serial.println(DigitalVRers); 
  Serial.print("Valor real do reservatorio:");
  Serial.println(realVRers);
  delay(1000);
    
    /*O seguínte algorítimo utiliza a variável "i" como
    refência para escolher qual motor irá ligar. A variável 
    "controle" para evitar bug na execução do software.
    */
    if((DigitalVRers <= 255)&&(i==0))
  	{
      digitalWrite(Motor1,HIGH);  
      controle = true;  
  	}

    else if((DigitalVRers <= 255)&&(i==1))
  	{
      digitalWrite(Motor2,HIGH);
      controle = true; 
  	}

    else if ((DigitalVRers == 1023)&&(controle))
  	{
      digitalWrite(Motor1,LOW);
      digitalWrite(Motor2,LOW);
      i++;
      controle = false;
      if (i>1)
  	  {
      	i = 0;
  	  }	
  	}
    
}  
