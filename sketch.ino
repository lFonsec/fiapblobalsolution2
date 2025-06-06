#include "DHTesp.h"

DHTesp dhtSensor;

int DHT_PIN = 21;
int greenLED = 16;
int yellowLED = 17;
int orangeLED = 18;
int redLED = 19;
int potencPin = 26;
int buzzer = 25;

int pwm = 0;
int valorpot= 0;

void setup() {
  Serial.begin(115200);
  dhtSensor.setup(DHT_PIN, DHTesp::DHT22);
  pinMode(potencPin, INPUT);
  pinMode(greenLED, OUTPUT);
  pinMode(yellowLED, OUTPUT);
  pinMode(orangeLED, OUTPUT);  
  pinMode(redLED, OUTPUT );
  pinMode(buzzer, OUTPUT);    

}

void loop() {
  TempAndHumidity  data = dhtSensor.getTempAndHumidity();
  float temp = data.temperature;
  float humi = data.humidity;
  Serial.print("Temp: ");
  Serial.print(temp);
  Serial.println(" °C");
  Serial.print("Humidity: ");
  Serial.print(humi);
  Serial.println(" %");

  valorpot = analogRead(potencPin);//Efetua a leitura do pino analógico A5 
  pwm = map(valorpot, 0, 1023, 0, 255);//Função map() para converter a escala de 0 a 1023 para a escala de 0 a 255
  Serial.print(pwm/10);
  Serial.println(" km/h");
  Serial.println("---");
  if(temp > 40 && humi < 12 ){
    digitalWrite(redLED, HIGH);
    digitalWrite(orangeLED, LOW);
    digitalWrite(yellowLED, LOW);
    digitalWrite(greenLED, LOW);
    digitalWrite(buzzer, HIGH); 

  }else if(temp > 35 && humi <= 20){
    digitalWrite(redLED, LOW);
    digitalWrite(orangeLED, HIGH);
    digitalWrite(yellowLED, LOW);
    digitalWrite(greenLED, LOW);
    digitalWrite(buzzer, LOW);

  }else if (temp > 30 && humi <= 30 ){
    digitalWrite(redLED, LOW);
    digitalWrite(orangeLED, LOW);
    digitalWrite(yellowLED, HIGH);
    digitalWrite(greenLED, LOW);
    digitalWrite(buzzer, LOW); 

  }else{
    digitalWrite(redLED, LOW);
    digitalWrite(orangeLED, LOW);
    digitalWrite(yellowLED, LOW);
    digitalWrite(greenLED, HIGH);
    digitalWrite(buzzer, LOW); 
  }

  delay(1500);


}

//Acima de 30 °C: risco moderado a alto.
//Acima de 35 °C: risco alto a muito alto.
//Acima de 40 °C: risco extremo, especialmente se acompanhado de vento e baixa umidade.
//Humidade Relativa do Ar
//Entre 30% e 20%: risco moderado a alto.
//Entre 20% e 12%: risco muito alto.
//Abaixo de 12%: risco extremo — as condições favorecem ignição e propagação rápida do fogo.
