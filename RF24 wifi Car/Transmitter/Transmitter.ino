#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

bool ok;
int16_t x_Axis;
int16_t y_Axis;
int16_t x_map;
int16_t y_map;


RF24 radio(7, 8); // CE, CSN
const byte address[6] = "00001";

void setup() {
  Serial.begin(9600);
  radio.begin();
  radio.openReadingPipe(0, address); // 00001
  radio.setPALevel(RF24_PA_MIN);
  radio.stopListening();
  x_Axis=analogRead(A0);
  y_Axis=analogRead(A1);

}
void loop() {
  x_map=analogRead(A0);
  y_map=analogRead(A1);
  
   if( y_Axis - 5 < y_map && y_map < y_Axis + 5 && x_Axis - 5 < x_map && x_map < x_Axis + 5 ){
         const char text[] = "S";
         ok = radio.write(&text, sizeof(text));
         Serial.println(text);
         
         
   }else if( x_Axis - 100 < x_map && x_map < x_Axis + 100 ){
      
      if( y_map > y_Axis ){
         
         const char text1[] = "F";
         ok = radio.write(&text1, sizeof(text1));
         Serial.println(text1);
         
      }else if( y_map < y_Axis ){
         
         const char text2[] = "B";
         ok = radio.write(&text2, sizeof(text2));
         Serial.println(text2);
         
      }
      
   }else if( y_Axis - 100 < y_map && y_map < y_Axis + 100 ){
      
      if( x_map > x_Axis ){
         
         const char text3[] = "R";
         ok = radio.write(&text3, sizeof(text3));
         Serial.println(text3);
         
      }else if( x_map < x_Axis ){
         
         const char text4[] = "L";
         ok = radio.write(&text4, sizeof(text4));
         Serial.println(text4);
         
      }
   }else if( y_map > y_Axis+100 && x_map > x_Axis+100 ){
      
         
         const char text5[] = "FR";
         ok = radio.write(&text5, sizeof(text5));
         Serial.println(text5);
         
     
   }else if( y_map < y_Axis-100 && x_map < x_Axis-100 ){
      
         const char text6[] = "FL";
         ok = radio.write(&text6, sizeof(text6));
         Serial.println(text6);
         
   }else if( y_map > y_Axis+100 && x_map < x_Axis-100 ){
      
         const char text7[] = "BR";
         ok = radio.write(&text7, sizeof(text7));
         Serial.println(text7);
         
   }else if( y_map < y_Axis-100 && x_map > x_Axis+100 ){
      
         const char text8[] = "BL";
         ok = radio.write(&text8, sizeof(text8));
         Serial.println(text8);
         
   }

  delay(250);

}
