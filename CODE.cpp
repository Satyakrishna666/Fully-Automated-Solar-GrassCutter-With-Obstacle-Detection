#include <NewPing.h>

#define IN_1  15      
#define IN_2  2       
#define IN_3  4        
#define IN_4  16      

#define TRIG_PIN 18
#define ECHO_PIN 19 

#define MAX_DISTANCE 200 

#define LDRsensor 23 

NewPing sonar(TRIG_PIN, ECHO_PIN, MAX_DISTANCE);
 
int distance = 0;
int readPing();
int prev=0;

int flag = 0;

void setup() {
      
      Serial.begin(115200);
      Serial.print("RESTART");
      
      pinMode(LDRsensor, INPUT);

      pinMode(IN_1, OUTPUT);
      pinMode(IN_2, OUTPUT);
      pinMode(IN_3, OUTPUT);
      pinMode(IN_4, OUTPUT);

      distance = readPing();
      delay(100);
      distance = readPing();
      delay(100);
      distance = readPing();
      delay(100);
      distance = readPing();
      delay(100);

      stopRobot();  
      bot.sendMessage(CHAT_ID, "Bot started up", "");
}
 
void loop() {

    distance = readPing();
    delay(100);
    
    Serial.print(distance);
    
    
    if(flag==0)
    {
      if(distance<=40)//distance
      {    
        stopRobot();
        Serial.println("STOP");
        delay(1000);    
        goBack();
        Serial.println("BACK");
        delay(2000);
        
        if(prev == 1)
        {
          goLeft();Serial.println("LEFT");
          delay(5000);
          prev=0;      
        }
        else
        { 
          goRight();Serial.println("RIGHT");
          delay(5000);
          prev=1;
        }     
      }
      else
      {
      goAhead(); Serial.println("Front");
      }
    }
    
 }
 

void goAhead(){ 

      digitalWrite(IN_1, LOW);
      digitalWrite(IN_2, HIGH);
      digitalWrite(IN_3, LOW);
      digitalWrite(IN_4, HIGH);
  }

void goBack(){ 

      digitalWrite(IN_1, HIGH);
      digitalWrite(IN_2, LOW);
      digitalWrite(IN_3, HIGH);
      digitalWrite(IN_4, LOW);
      
  }

void goRight(){ 

      digitalWrite(IN_1, HIGH);
      digitalWrite(IN_2, LOW);
      digitalWrite(IN_3, LOW);
      digitalWrite(IN_4, HIGH);
      
  }

void goLeft(){

      digitalWrite(IN_1, LOW);
      digitalWrite(IN_2, HIGH);
      digitalWrite(IN_3, HIGH);
      digitalWrite(IN_4, LOW);
      
  }

void stopRobot(){  

      digitalWrite(IN_1, LOW);
      digitalWrite(IN_2, LOW);
      
      digitalWrite(IN_3, LOW);
      digitalWrite(IN_4, LOW);
    
  }

int readPing() { 
  
  delay(70);
  int cm = sonar.ping_cm();
  if(cm==0)
  {
    cm = 250;
  }
  return cm;
}

 
