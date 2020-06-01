#include "IRremote.h"

int receiver = 11; 
int redPin = 7;
int greenPin = 6;
int bluePin = 5;


IRrecv irrecv(receiver);     
decode_results results;      

void translateIR() {

  switch(results.value)

  {
  case 0xFF6897: analogWrite(redPin, 255);    break;
  case 0xFF30CF: analogWrite(bluePin, 255);    break;
  case 0xFF18E7: analogWrite(greenPin,255);   break;
  
  case 0xFF7A85: 
    analogWrite(redPin,150);
    analogWrite(greenPin,180);
    break;
    
  case 0xFF10EF:
    analogWrite(redPin,200);
    analogWrite(bluePin,190);
    break;
    
  case 0xFF38C7:
      analogWrite(greenPin,240);
      analogWrite(bluePin, 200);
      break;
      
  case 0xFF5AA5: 
    analogWrite(redPin,120);
    analogWrite(bluePin,240);   
    break;
    
  case 0xFF42BD: 
    analogWrite(redPin,255);
    analogWrite(greenPin,255);  
    analogWrite(bluePin,255);      
    break;
    
  case 0xFF4AB5: 
  analogWrite(redPin,230);
  analogWrite(greenPin,170);    
  break;
  
  case 0xFF52AD: 
  analogWrite(redPin,30); 
  analogWrite(greenPin,143);
  analogWrite(bluePin,82);   
  break;

  default: 
    analogWrite(redPin,0);
    analogWrite(greenPin,0);
    analogWrite(bluePin,0);

  }

  delay(500);


} 
void setup() 
{
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
 
}

void loop()   
{
  if (irrecv.decode(&results)) 

  {
    translateIR();
    irrecv.resume(); 
  }  
  
}
