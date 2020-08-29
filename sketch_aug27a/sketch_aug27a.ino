#include <Encoder.h>
#include <Joystick.h>

Joystick_ Joystick;

int ledPin = 9;
int pushButtonPin = 10;
int encoderButtonPin = 16;
int pushButtonState = 0;
int encoderButtonState = 0;
int ledState = 0;
char buf [64];

Encoder enc1(0, 1);
Encoder enc2(2, 3);

void setup()
{
    Serial.begin(9600);
    pinMode(ledPin, OUTPUT); //pin 10 is set as output pin
    pinMode(pushButtonPin, INPUT_PULLUP);
    pinMode(encoderButtonPin, INPUT_PULLUP);
    Joystick.begin();
}

long oldPosition1 = -999;
long oldPosition2 = -999;
int lastButtonState10 = 0;
int lastButtonState16 = 16;

void loop() // The loop function runs again and again
{

    pushButtonState = digitalRead(pushButtonPin);
    encoderButtonState = digitalRead(encoderButtonPin);

    // if (pushButtonState == LOW || encoderButtonState == LOW)
    // {
    //     //digitalWrite(ledPin, HIGH);
    //     digitalWrite(ledPin, !digitalRead(ledPin));
    //     //ledState = 1;
    //     if (pushButtonState == LOW)
    //     {
    //         Serial.println("LED Toggled by push button");
    //     }
    //     else
    //     {
    //         Serial.println("LED Toggled by encoder button");
    //         myEnc.write(0);
    //     }

    //     delay(300);
    // }

    long newPosition1 = enc1.read() / 4;
    if (newPosition1 != oldPosition1)
    {
        if (newPosition1 > oldPosition1)
        {
            Joystick.pressButton(2);
            delay(50);
            Joystick.releaseButton(2);
        }
        else if (newPosition1 < oldPosition1)
        {
            Joystick.pressButton(3);
            delay(50);
            Joystick.releaseButton(3);
        }
        
        oldPosition1 = newPosition1;
        Serial.println("Encoder1: " + newPosition1);
    }

    long newPosition2 = enc2.read() / 4;
    if (newPosition2 != oldPosition2)
    {
        if (newPosition2 > oldPosition2)
        {
            Joystick.pressButton(4);
            delay(50);
            Joystick.releaseButton(4);
        }
        else if (newPosition2 < oldPosition2)
        {
            Joystick.pressButton(5);
            delay(50);
            Joystick.releaseButton(5);
        }
        
        oldPosition2 = newPosition2;
        sprintf (buf, "Encoder 2:", newPosition2);
        Serial.println(buf);
    }



   
    int currentButtonState10 = !digitalRead(pushButtonPin);
    if (currentButtonState10 != lastButtonState10)
    {
        Joystick.setButton(0, currentButtonState10);
        lastButtonState10 = currentButtonState10;
    }

    int currentButtonState16 = !digitalRead(encoderButtonPin);
    if (currentButtonState16 != lastButtonState16)
    {
        Joystick.setButton(1, currentButtonState16);
        lastButtonState16 = currentButtonState16;
    }
    
}
