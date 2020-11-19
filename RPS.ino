#include <Servo.h>
#include <LiquidCrystal.h>

const int trigPin = 8;
const int echoPin = 7;

long duration; 
int distance; 

LiquidCrystal lcd(6, 5, 4, 3, 2, 9);

Servo myservo2;
Servo myservo3;
Servo myservo4;
Servo myservo5;  


int pos = 0;   
long randNumber; 


void setup() {
  lcd.begin(16, 2);
  lcd.print("Welcome");
  delay(1000);
  lcd.begin(1,0);
  lcd.print("hand to start");
  
  pinMode (trigPin,OUTPUT);
  pinMode (echoPin, INPUT);
  Serial.begin(9600);

 randomSeed(analogRead(0));

  myservo2.attach(10);
  myservo3.attach(11);
  myservo4.attach(12);
  myservo5.attach(13);

  pos = 90;

  myservo2.write(pos);
  myservo3.write(pos);
  myservo4.write(pos);
  myservo5.write(pos); 
}

void loop() {
  
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin,LOW);

  duration = pulseIn(echoPin, HIGH);
  distance =duration * 0.034/2;

  Serial.print("Distance: ");
  Serial.println(distance);

  lcd.clear();
  lcd.print("Go");

  if (distance < 10){
      randNumber = random(3);
     
      Serial.println(randNumber);
    
      delay (1000);
      lcd.clear();
      lcd.print("Rock");
      Serial.println("Rock");
    
      delay (1000);
       lcd.clear();
      lcd.print("paper");
      Serial.println("paper");
     
      delay (1000);
       lcd.clear();
      lcd.print("scissors");
      Serial.println("scissors");
      delay (1000);
          
      if(randNumber == 0){
        Serial.println("paper");
        lcd.clear();
        lcd.print("paper");
                         
            myservo2.write(0);
            myservo3.write(0);
            myservo4.write(0);
            myservo5.write(0);           
            delay(15);                                
    
          delay (4000);
               
            myservo2.write(90);
            myservo3.write(90);
            myservo4.write(90);
            myservo5.write(90);                                                 
        }
    
      else if(randNumber == 1){
          Serial.println("scissors");
          lcd.clear();
          lcd.print("scissors");
        
            myservo2.write(0);
            myservo3.write(0);   
            myservo5.write(180);
            myservo4.write(180);      
            delay(15);                       
        
          delay (4000);
      
            myservo4.write(90);
            myservo2.write(90);    
            myservo3.write(90);
            myservo5.write(90);       
            delay(15);                         
        }
    
        
      else {
        Serial.println("Rock");
        lcd.clear();
        lcd.print("Rock");
            
            myservo2.write(180);
            myservo3.write(180);
            myservo4.write(180);
            myservo5.write(180);           
            delay(15);                       
            
          delay (4000);
        
            myservo2.write(90);
            myservo3.write(90);
            myservo4.write(90);
            myservo5.write(90);               
            delay(15);                       
    }

    delay(1000);  
    } 
}
