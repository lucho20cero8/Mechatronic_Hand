#include <Servo.h>
char bt ='a';
Servo myservo1;  // crea el objeto servo
Servo myservo2;
Servo myservo3;
int led1 = A0;
int led2 = A1;
int pos = 0;    // posicion del servo
 
void setup() {
  digitalWrite(led1,HIGH);
  Serial.begin(9600);
   myservo1.attach(10);  // vincula el servo al pin digital 9
   myservo2.attach(6);
   myservo3.attach(11);
   pinMode(led1,OUTPUT);
   pinMode(led2,OUTPUT);
   
   
}
 
void loop() {
  
  if (Serial.available() > 0) {
    bt = Serial.read();
      switch(bt)
    {
      case 'a':
        digitalWrite(led2,HIGH);
        digitalWrite(led1,LOW);
        for (pos = 180; pos >= 15; pos -= 1) 
           {
              myservo1.write(pos);
              myservo2.write(pos); 
              myservo3.write(pos);             
              delay(20);
                                  
           }
      
      break;
      case 'b':
        digitalWrite(led1,HIGH);
        digitalWrite(led2,LOW);
        for (pos = 15; pos <= 180; pos += 1) 
             {
                myservo1.write(pos);
                myservo2.write(pos); 
                myservo3.write(pos);               
                delay(20);
                                      
             }
       break;
      
    }
    Serial.println(bt);
  }
}
