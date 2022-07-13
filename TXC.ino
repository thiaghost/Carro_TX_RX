//Carrega a biblioteca do sensor ultrassonico
#include <Ultrasonic.h>
#include <VirtualWire.h>

//
byte message[VW_MAX_MESSAGE_LEN];    // Armazena as mensagens recebidas
byte msgLength = VW_MAX_MESSAGE_LEN; // Armazena o tamanho das mensagens
char data[2];

//Define os pinos para o trigger e echo
#define pino_trigger 10
#define pino_echo 9
#define led 13

//motor_A
int IN3 = 7 ;
int IN4 = 6 ;
int velocidadeB = 5;

//LED

//Variaveis
float cmMsec;

//Inicializa o sensor nos pinos definidos acima
Ultrasonic ultrasonic(pino_trigger, pino_echo);

void sentidoTras(){
  digitalWrite(IN3,LOW);
  digitalWrite(IN4,HIGH);
}

void sentidoFrente(){
  digitalWrite(IN3,HIGH);
  digitalWrite(IN4,LOW);
}

void acelerar(){
  digitalWrite(IN3,HIGH);
  digitalWrite(IN4,LOW);
  analogWrite(velocidadeB,135);
  byte TXacelerar = 1;
  vw_send((uint8_t *)&TXacelerar,1);
  Serial.print("acelerando");
  Serial.print('\n');
}

void freio(){
  analogWrite(velocidadeB,0);
  byte TXfreiar = 2;
  vw_send((uint8_t *)&TXfreiar,1);
  Serial.print("freiando");
  Serial.print('\n');
}

void setup()
{
  Serial.begin(9600);
  pinMode(IN3,OUTPUT);
  pinMode(IN4,OUTPUT);
  pinMode(velocidadeB,OUTPUT);
  vw_setup(2000);
}

void loop()
{
  cmMsec = ultrasonic.distanceRead(CM);  
  if (cmMsec > 30){
    digitalWrite(led,LOW);
    acelerar();
    Serial.print(cmMsec);
  }
  else{
    digitalWrite(led,HIGH);
    Serial.print(cmMsec);
    freio();
  }

}
