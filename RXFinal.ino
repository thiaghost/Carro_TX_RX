#include <VirtualWire.h>

byte message[VW_MAX_MESSAGE_LEN];    // Armazena as mensagens recebidas
byte msgLength = VW_MAX_MESSAGE_LEN; // Armazena o tamanho das mensagens


//motor_A
int IN3 = 7 ;
int IN4 = 6 ;
int velocidadeB = 5;

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
}

void freio(){
  analogWrite(velocidadeB,0);
}

void setup()
{
  Serial.begin(9600);
  pinMode(IN3,OUTPUT);
  pinMode(IN4,OUTPUT);
  pinMode(velocidadeB,OUTPUT);
  Serial.begin(9600);  // Debugging only
  
  vw_setup(2000);  // Bits per sec
  vw_rx_start();
}

void loop()
{ 
  if (vw_get_message(message, &msgLength)) // Non-blocking
    {
        Serial.print("Recebido: ");
        Serial.write(message[0]);
        if(message[0] == '1'){
          digitalWrite(13, LOW);
          acelerar();
        }
        else if(message[0] == '2'){
          digitalWrite(13,HIGH);
          freio();
        }
    }
  }
