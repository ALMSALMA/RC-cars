#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>


RF24 radio(7, 8); // CE, CSN
const byte address[6] = "00001";

void setup() {
  
  Serial.begin(9600);
  radio.begin();
  radio.openReadingPipe(0, address);
  radio.setPALevel(RF24_PA_MIN);
  radio.startListening();
  pinMode(5,OUTPUT);
  pinMode(6,OUTPUT);
  pinMode(3,OUTPUT);
  pinMode(9,OUTPUT);
  
}

void loop() {
  
  while (!radio.available());
  char text[3] = "";
  //String text = "";
  radio.read(&text, sizeof(text));
  Serial.println(text);
  
      if(strcmp(text, "S") == 0){
          analogWrite(3,0);
          analogWrite(5,0);
          analogWrite(6,0);
          analogWrite(9,0);
       }else if(strcmp(text, "F") == 0){
          analogWrite(3,0);
          analogWrite(5,255);
          analogWrite(6,0);
          analogWrite(9,255);
       }else if(strcmp(text, "B") == 0) {
          analogWrite(3,255);
          analogWrite(5,0);
          analogWrite(6,255);
          analogWrite(9,0);
       }else if(strcmp(text, "R") == 0) {
          analogWrite(3,255);
          analogWrite(5,0);
          analogWrite(6,0);
          analogWrite(9,0);
          
       }else if(strcmp(text, "L") == 0) {
          analogWrite(3,0);
          analogWrite(5,0);
          analogWrite(6,0);
          analogWrite(9,255);    
       }else if(strcmp(text, "FR") == 0){
          analogWrite(3,200);
          analogWrite(5,0);
          analogWrite(6,0);
          analogWrite(9,150);
       }else if(strcmp(text, "FL") == 0){
          analogWrite(3,150);
          analogWrite(5,0);
          analogWrite(6,0);
          analogWrite(9,200);
       }else if(strcmp(text, "BR") == 0){
          analogWrite(3,0);
          analogWrite(5,200);
          analogWrite(6,150);
          analogWrite(9,0);
       }else if(strcmp(text, "BL") == 0){
          analogWrite(3,0);
          analogWrite(5,150);
          analogWrite(6,200);
          analogWrite(9,0);
        }
  
}
