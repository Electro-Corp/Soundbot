/*
SOUNDBOT V1.0
Chinmay Tiwari June 8 2020
GNU Public Lisense

*/

// named constants for the switch and motor pins
const int switchPin = 2; // the number of the switch pin
const int motorPin =  9; // the number of the motor pin

int switchState = 0;  // variable for reading the switch's status
const int ledPin = 13; //pin13 built-in led
const int soundPin = A0;  //sound sensor attach to A0
const int redPin = 11;  // R petal on RGB LED module connected to digital pin 11 
const int greenPin = 10;  // G petal on RGB LED module connected to digital pin 10 
const int bluePin = 8; 
#include <IRremote.h>
// named constants for the switch and motor pins
// the number of the switch pin
 // the number of the motor pin
const int yesno = 5;
const int irReceiverPin = 7;

int onoff = 0;
IRrecv irrecv(irReceiverPin);
decode_results results;


void setup() {
  // initialize the motor pin as an output 
  pinMode(motorPin, OUTPUT);
  // initialize the switch pin as an input:
  pinMode(switchPin, INPUT);
    pinMode(ledPin,OUTPUT);//set ledPin as OUTPUT
  Serial.begin(9600); //initialize the serial communication as 9600 bps
  pinMode(redPin, OUTPUT); // sets the redPin to be an output 
  pinMode(greenPin, OUTPUT); // sets the greenPin to be an output 
  pinMode(bluePin, OUTPUT); // sets the bluePin to be an output 
    // initialize the motor pin as an output:
 
  // initialize the switch pin as an input:
  
  pinMode(ledPin, OUTPUT);
  pinMode(yesno, OUTPUT);
  irrecv.enableIRIn();
}


void loop() {
  // read the state of the switch value:
  switchState = digitalRead(switchPin);
    int value = analogRead(soundPin); //read the value of sound sensor
  Serial.println(value);//print it
  if(value > 600)//if the vallue of sound sensor is greater than 600
  {
    digitalWrite(ledPin,HIGH); //turn on the led
    delay(200); //delay 200ms
    digitalWrite(motorPin, HIGH);
    color(255,0,255); // turn the RGB LED green  

  }
  else //elae 
  {
    
    digitalWrite(ledPin,LOW); //turn off the led
    digitalWrite(motorPin, LOW);
    color(0,255,255); // turn the RGB LED red 

  }
   switchState = digitalRead(switchPin);
  if (irrecv.decode(&results)) //if the ir receiver module receiver data
  {
    Serial.print("irCode: "); //print"irCode: "
    Serial.print(results.value, HEX); //print the value in hexdecimal
    Serial.print(", bits: "); //print" , bits: "
    Serial.println(results.bits); //print the bits
    irrecv.resume(); // Receive the next value
  }
  delay(600); //delay 600ms
  if (results.value == 0xFFA25D) //if receiver module receive OxFFA25D
  {
    digitalWrite(ledPin, HIGH); //turn on the led
    digitalWrite(yesno, HIGH);
    int yeet = 1;
    if (yeet == 1) {
      // turn motor on:
      digitalWrite(motorPin, HIGH);
    } else {
      // turn motor off:
      digitalWrite(motorPin, LOW);
    }
  }
  else
  {
    digitalWrite(ledPin, LOW); //turn off the led
    digitalWrite(yesno, LOW);
    int yeet = 0;
    if (yeet == 1) {
      // turn motor on:
      digitalWrite(motorPin, HIGH);
    } else {
      // turn motor off:
      digitalWrite(motorPin, LOW);
    }

void color (unsigned char red, unsigned char green, unsigned char blue)     // the color generating function  
{    
  analogWrite(redPin, red);   
  analogWrite(bluePin, blue); 
  analogWrite(greenPin, green); 
}
