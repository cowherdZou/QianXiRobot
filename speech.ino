#include <Arduino.h>
#include <SoftwareSerial.h>

SoftwareSerial BT(A1, A2);
char speechval[12]={0};
int wi=0;
int speech = 0;

void setup(){
  Serial.begin(9600);
  BT.begin(115200);
  wi=0;
}

void loop(){

  if (BT.available()) 
  {
     speechval[wi] = BT.read();
     //Serial.println(speechval[wi]);
     //Serial.println(wi);
     if(speechval[wi] == '#' || wi >= 5){
       wi = 0;
     }
     else{
       wi++;
     }
  }
  if(speechval[2] == '0'){
    if(speechval[3] == '9'){
      if(speechval[4] == '5'){
        speech = 95;
        //Serial.println("$A095#");
      }
    }
  }
  if(speech == 95){
      delay(100);
      BT.print("$A045#");
      Serial.println("OK");
      speech = 0;
      for(int i;i<10;i++){
        speechval[i] = 0;
      }
  }  
}
