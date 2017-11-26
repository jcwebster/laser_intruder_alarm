/*
 * Laser-Cat Removal
 * John Webster
 * 11-20-17
 */
 /*
  * Button cnxns:
  * S  -----> -
  * DIO, GND, VCC
  */

  unsigned char i,j;// Define the variable
int button = 3;
int laser = 13;
int buzzer = 8;
//IR trip = "A6";

bool alarmState = 0;
bool state = 0;
int noObjectState = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(button, INPUT);
  pinMode(A6, INPUT); //IR sensor
  pinMode(laser, OUTPUT);
  pinMode(buzzer, OUTPUT);
  
  while (digitalRead(button)==LOW);
  noObjectState = analogRead(A6); //calibrate

  Serial.println("READY!");
  Serial.println(noObjectState);
  
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.print(analogRead(A6));
  Serial.print(",");
  Serial.println(noObjectState);
  
  //replace next if with
   while (analogRead(A6) < noObjectState*0.9){
     digitalWrite(laser, HIGH);
     alarm(2);
   }
   digitalWrite(laser, LOW);
  /*
  state = analogRead(A6);
 
  if (state < (noObjectState*0.9)){
    while (analogRead(A6) < noObjectState*0.9){
      digitalWrite(laser, HIGH);
      alarm(2);
    }
  }else {
    digitalWrite(laser, LOW);
  }
*/
  //delay(20);
}

void alarm(int length){
   for (int k=0; k< length; k++){
      for(i=0;i<80;i++)// Wen a frequency sound
      {
        digitalWrite(buzzer,HIGH);// Sound
        delay(1);//delay 1ms
        digitalWrite(buzzer,LOW);//Not sound
        delay(1);// delay 1ms
      }
      for(i=0;i<50;i++)// Wen out another frequency sound
      {
        digitalWrite(buzzer,HIGH);// Sound
        delay(2);//delay 2ms
        digitalWrite(buzzer,LOW);// Not sound
        delay(2);//delay 2ms
      }
   }  
}

