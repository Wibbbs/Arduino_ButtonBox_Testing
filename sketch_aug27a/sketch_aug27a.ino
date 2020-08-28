#include <Encoder.h>
#include <Joystick.h>

Joystick_ Joystick;

int ledPin = 9;
int pushButtonPin = 10;
int encoderButtonPin = 16;
int pushButtonState = 0;
int encoderButtonState = 0;
int ledState = 0;

Encoder myEnc(2, 3);

void setup()
{
    Serial.begin(9600);
    pinMode(ledPin, OUTPUT); //pin 10 is set as output pin
    pinMode(pushButtonPin, INPUT_PULLUP);
    pinMode(encoderButtonPin, INPUT_PULLUP);
    Joystick.begin();
}

long oldPosition = -999;
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

    long newPosition = myEnc.read() / 4;
    if (newPosition != oldPosition)
    {
        if (newPosition > oldPosition)
        {
            Joystick.pressButton(2);
            delay(25);
            Joystick.releaseButton(2);
        }
        else if (newPosition < oldPosition)
        {
            Joystick.pressButton(3);
            delay(25);
            Joystick.releaseButton(3);
        }
        
        oldPosition = newPosition;
        Serial.println(newPosition);
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
