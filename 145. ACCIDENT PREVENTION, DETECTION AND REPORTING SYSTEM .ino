#include <SoftwareSerial.h>
 
//define for temperature sensor
int sensorInput;
int tempsensePin=A4;
int temp;
int ledPin_temp =3;
int threshold_temperature=15;
 
//define eye blink senaor
int IRSensor = 2;
int BUZZER = 13;
 
//define alcohol sensor
const int MQ3=0;
const int motor=9;
int value;
 
 
void setup() {
 Serial.begin(9600);
 
//setup for temperature
pinMode(tempsensePin, INPUT);
pinMode(sensorInput,INPUT);
pinMode(ledPin_temp, OUTPUT);
 
//setup for eye blink sensor
pinMode (IRSensor, INPUT); 
pinMode (BUZZER, OUTPUT);
 
//setup for alcohol sensor
pinMode(MQ3, INPUT);
pinMode(motor, OUTPUT);
 
digitalWrite(BUZZER,LOW);
digitalWrite(motor,LOW);
digitalWrite(ledPin_temp,LOW);
  
}
 
void loop() {
 
 //temperature sensor detection and prevention by  red light on
  sensorInput = analogRead(A4);
  temp = sensorInput*0.048828125;
 
 //eye blink sensor detection
  int statusSensor = digitalRead(IRSensor);
 
 //alcohol sensor detection
  value= analogRead(MQ3);
  Serial.print("alcohol concentration is: ");
  Serial.println(value);
   
if (temp>threshold_temperature)
  {
   digitalWrite(ledPin_temp,HIGH);
   Serial.print("Temperature: ");
   Serial.print(temp);
   Serial.println("C"); 
   Serial.print('\n');
   Serial.print("Warning!!!");
   Serial.print('\n');
   Serial.print("Temprature is High");
   Serial.print('\n');
   delay(2000);
  }
else
  {
  digitalWrite(ledPin_temp,LOW);
  Serial.print("Temp is fine");
  Serial.print('\n');
  delay(1000);
  }
if(statusSensor == 1)
  {
    digitalWrite(BUZZER, LOW);
  }
else
{
 digitalWrite(BUZZER, HIGH);
}
if(value>700)
  {
    digitalWrite(motor,LOW);
  }
else
  {
  digitalWrite(motor,HIGH);
  }
   
 delay(500);
 
}