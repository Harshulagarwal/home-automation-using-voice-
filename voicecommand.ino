#include <SoftwareSerial.h>

SoftwareSerial BTserial(11, 10); // RX | TX

String voice="";

int
led1 = 2, //Connect LED 1 To Pin #2
led2 = 3, //Connect LED 2 To Pin #3
led3 = 4, //Connect LED 3 To Pin #4
led4 = 5, //Connect LED 4 To Pin #5
led5 = 6, //Connect LED 5 To Pin #6
led10=10,
led11=11,
fan8=8,fan9=9;
//--------------------------Call A Function-------------------------------//
void allon(){
     digitalWrite(led1, HIGH);
     digitalWrite(led2, HIGH);
     digitalWrite(led3, HIGH);
     digitalWrite(led4, HIGH);
     digitalWrite(led5, HIGH);
digitalWrite(fan8, HIGH);
digitalWrite(fan9,LOW);
  }
void alloff(){
     digitalWrite(led1, LOW);
     digitalWrite(led2, LOW);
     digitalWrite(led3, LOW);
     digitalWrite(led4, LOW);
     digitalWrite(led5, LOW);
digitalWrite(fan8, LOW);
digitalWrite(fan9,LOW);
}
//-----------------------------------------------------------------------// 
void setup() {
  Serial.begin(9600);
BTserial.begin(9600); 

  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);
  pinMode(led5, OUTPUT);
  pinMode(fan8, OUTPUT);
  pinMode(fan9, OUTPUT);
}
//-----------------------------------------------------------------------// 
void loop() {
  //Serial.println(BTserial.read());
  while (BTserial.available()){  //Check if there is an available byte to read
  
  delay(10); //Delay added to make thing stable
  char c = (char)BTserial.read(); //Conduct a serial read
  if (c == '#') {break;} //Exit the loop when the # is detected after the word
  voice += c; //Shorthand for voice = voice + c
//  Serial.println((char)BTserial.read());
} 
  //BTserial.println(voice);
  if (voice.length() > 0) {
    
    Serial.println(voice);
//-----------------------------------------------------------------------//   
  //----------Control Multiple Pins/ LEDs----------// 
       if(voice == "*all on") {allon();}  //Turn Off All Pins (Call Function)
  else if(voice == "*all off"||voice == "*all of"){alloff();} //Turn On  All Pins (Call Function)
 
  //----------Turn On One-By-One----------//
  else if(voice == "*lights on"||voice == "*light on") {digitalWrite(led1, HIGH);}
  else if(voice == "*AC on") {digitalWrite(led2, HIGH);}
  else if(voice == "*computer on") {digitalWrite(led3, HIGH);}
  else if(voice == "*bedroom lights on") {digitalWrite(led4, HIGH);}
  else if(voice == "*bathroom lights on") {digitalWrite(led5, HIGH);}
  else if(voice == "*fan on") {digitalWrite(fan8, HIGH);
digitalWrite(fan9, LOW);  }
  //----------Turn Off One-By-One----------//
  else if(voice == "*lights off"|| voice == "*lights of"||  voice == "*light off"||   voice == "*light of") {digitalWrite(led1, LOW);}
  else if(voice == "*AC off"||voice == "*AC of") {digitalWrite(led2, LOW);}
  else if(voice == "*computer off") {digitalWrite(led3, LOW);}
  else if(voice == "*bedroom lights off") {digitalWrite(led4, LOW);}
  else if(voice == "*bathroom lights off") {digitalWrite(led5, LOW);}
   else if(voice == "*fan off") {digitalWrite(fan8, LOW);
digitalWrite(fan9, LOW);  }
//-----------------------------------------------------------------------// 
voice="";}} //Reset the variable after initiating


