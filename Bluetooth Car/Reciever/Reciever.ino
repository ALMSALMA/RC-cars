#include <SoftwareSerial.h>

int Angle = 0;
int Strength = 0;
int RightSideForward = 3;
int LeftSideForward = 5;
int RightSideBack = 6;
int LeftSideBack = 9;

String Sangle;
String Sstrength;

SoftwareSerial bluetooth(7,8); // RX,TX

void setup() {
  Serial.begin(9600);
  bluetooth.begin (9600);
  pinMode(RightSideForward,OUTPUT);
  pinMode(LeftSideForward,OUTPUT);
  pinMode(RightSideBack,OUTPUT);
  pinMode(LeftSideBack,OUTPUT);
}

void loop() {
  if (bluetooth.available() > 0 ){  
    String value = bluetooth.readStringUntil('#');

    if(value.length()==7){
      
      Sangle = value.substring(0, 3);
      Sstrength = value.substring(3, 6);
      
      Angle = Sangle.toInt();
      Strength = Sstrength.toInt();
      Strength = map(Strength,0,100,0,255);

      if(Strength == 0){                         // No move
        
          analogWrite(RightSideForward,0);
          analogWrite(LeftSideForward,0);
          analogWrite(RightSideBack,0);
          analogWrite(LeftSideBack,0);
          Serial.println("No");
          
       }else if(Angle > 30 && Angle < 60){       // Forward Right
        
          analogWrite(RightSideForward,Strength - Strength / 2);
          analogWrite(LeftSideForward,Strength);
          analogWrite(RightSideBack,0);
          analogWrite(LeftSideBack,0);
          Serial.println("Forward Right");
          
       }else if(Angle > 60 && Angle < 120) {     // Forward
          
          analogWrite(RightSideForward,Strength);
          analogWrite(LeftSideForward,Strength);
          analogWrite(RightSideBack,0);
          analogWrite(LeftSideBack,0);
          Serial.println("Forward");
          
       }else if(Angle > 120 && Angle < 150) {     // Forward Left
          
          analogWrite(RightSideForward,Strength);
          analogWrite(LeftSideForward,Strength - Strength / 2);
          analogWrite(RightSideBack,0);
          analogWrite(LeftSideBack,0);
          Serial.println("Forward Left");
          
       }else if(Angle > 150 && Angle < 210) {     // Left
          
          analogWrite(RightSideForward,Strength);
          analogWrite(LeftSideForward,0);
          analogWrite(RightSideBack,0);
          analogWrite(LeftSideBack,0);
          Serial.println("Left");
          
       }else if(Angle > 210 && Angle < 240){      // Back Left
          
          analogWrite(RightSideForward,0);
          analogWrite(LeftSideForward,0);
          analogWrite(RightSideBack,Strength);
          analogWrite(LeftSideBack,Strength - Strength / 2);
          Serial.println("Back Left");
          
       }else if(Angle > 240 && Angle < 300){      // Back
          
          analogWrite(RightSideForward,0);
          analogWrite(LeftSideForward,0);
          analogWrite(RightSideBack,Strength);
          analogWrite(LeftSideBack,Strength);
          Serial.println("Back");
          
       }else if(Angle > 300 && Angle < 330){      // Back right
          
          analogWrite(RightSideForward,0);
          analogWrite(LeftSideForward,0);
          analogWrite(RightSideBack,Strength - Strength / 2);
          analogWrite(LeftSideBack,Strength);
          Serial.println("Back right");
          
       }else if(Angle > 330 || Angle < 30){       // Right  
         
          analogWrite(RightSideForward,0);
          analogWrite(LeftSideForward,Strength);
          analogWrite(RightSideBack,0);
          analogWrite(LeftSideBack,0);
          Serial.println("Right");
          
      }
      
      value="";
    }
  }
}
