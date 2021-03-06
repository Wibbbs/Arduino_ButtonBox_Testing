//From bildr article: http://bildr.org/2012/08/rotary-encoder-arduino/
#include <Joystick.h>

Joystick_ Joystick;
//these pins can not be changed 2/3 are special pins
int encoderPin1 = 0;
int encoderPin2 = 1;
int encoderSwitchPin = 16; //push button switch

volatile int lastEncoded = 0;
volatile long encoderValue = 0;

long lastencoderValue = 0;

int lastMSB = 0;
int lastLSB = 0;

boolean buttonPushed = false;

void setup() {
  Serial.begin (9600);
  Joystick.begin();
  pinMode(encoderPin1, INPUT_PULLUP);
  pinMode(encoderPin2, INPUT_PULLUP);

  pinMode(encoderSwitchPin, INPUT_PULLUP);


//  digitalWrite(encoderPin1, HIGH); //turn pullup resistor on
//  digitalWrite(encoderPin2, HIGH); //turn pullup resistor on
//
//  digitalWrite(encoderSwitchPin, HIGH); //turn pullup resistor on


  //call updateEncoder() when any high/low changed seen
  //on interrupt 0 (pin 2), or interrupt 1 (pin 3)
  attachInterrupt(0, updateEncoder, CHANGE);
  attachInterrupt(1, updateEncoder, CHANGE);

}

void loop(){
  //Do stuff here
  if(digitalRead(encoderSwitchPin)){
    //button is not being pushed
  }else{
    //button is being pushed
    Serial.println("button pushed");
    buttonPushed = true;
  }
 
  Serial.println(encoderValue);
  delay(1000); //just here to slow down the output, and show it will work  even during a delay
}


void updateEncoder(){
  int MSB = digitalRead(encoderPin1); //MSB = most significant bit
  int LSB = digitalRead(encoderPin2); //LSB = least significant bit

  int encoded = (MSB << 1) |LSB; //converting the 2 pin value to single number
  int sum  = (lastEncoded << 2) | encoded; //adding it to the previous encoded value

  if(sum == 0b1101 || sum == 0b0100 || sum == 0b0010 || sum == 0b1011)
  {
    encoderValue ++;
    Joystick.pressButton(2);
    delay(50);
    Joystick.releaseButton(2);
  }
  if(sum == 0b1110 || sum == 0b0111 || sum == 0b0001 || sum == 0b1000) 
  {
    encoderValue --;
    Joystick.pressButton(3);
    delay(50);
    Joystick.releaseButton(3);
  }

  lastEncoded = encoded; //store this value for next time
}
