
#include <Encoder.h>
#include <Joystick.h>

Joystick_ Joystick;
// Change these pin numbers to the pins connected to your encoder.
//   Best Performance: both pins have interrupt capability
//   Good Performance: only the first pin has interrupt capability
//   Low Performance:  neither pin has interrupt capability
Encoder rotary1(0, 1);
Encoder rotary2(2, 3);
Encoder rotary3(4, 5);
Encoder rotary4(6, 7);
//   avoid using pins with LEDs attached

void setup() {
  Serial.begin(9600);
  Serial.println("Start Button Box");
  Joystick.begin();
}

long rotary1Position = -999;
long rotary2Position = -999;
long rotary3Position = -999;
long rotary4Position = -999;

void loop() {
    long newRotary1, newRotary2, newRotary3, newRotary4;
    newRotary1 = rotary1.read()/4;
    newRotary2 = rotary2.read()/4;
    newRotary3 = rotary3.read()/4;
    newRotary4 = rotary4.read()/4;

    if (newRotary1 != rotary1Position || newRotary2 != rotary2Position || newRotary3 != rotary3Position || newRotary4 != rotary4Position){
        
        if (newRotary1 > rotary1Position)
        {
            Joystick.pressButton(2);delay(50);Joystick.releaseButton(2);
        }
        else if (newRotary1 < rotary1Position)
        {
            Joystick.pressButton(3);delay(50);Joystick.releaseButton(3);
        };

        if (newRotary2 > rotary2Position)
        {
            Joystick.pressButton(4);delay(50);Joystick.releaseButton(4);
        }
        else if (newRotary2 < rotary2Position)
        {
            Joystick.pressButton(5);delay(50);Joystick.releaseButton(5);
        };

        if (newRotary3 > rotary3Position)
        {
            Joystick.pressButton(6);delay(50);Joystick.releaseButton(6);
        }
        else if (newRotary3 < rotary3Position)
        {
            Joystick.pressButton(7);delay(50);Joystick.releaseButton(7);
        };

        if (newRotary4 > rotary4Position)
        {
            Joystick.pressButton(8);
        }
        else if (newRotary4 < rotary4Position)
        {
            Joystick.pressButton(9);
        };

        rotary1Position = newRotary1;
        rotary2Position = newRotary2;
        rotary3Position = newRotary3;
        rotary4Position = newRotary4;

        Serial.print("Rotary 1 = ");
        Serial.print(newRotary1);
        Serial.print(", Rotary 2 = ");
        Serial.print(newRotary2);
        Serial.print("Rotary 3 = ");
        Serial.print(newRotary3);
        Serial.print(", Rotary 4 = ");
        Serial.print(newRotary4);
        Serial.println();

        delay(50);
        Joystick.releaseButton(9);
        Joystick.releaseButton(8);
    }
}

void press







//   if (newRotary1 != rotary1Position || newRotary2 != rotary2Position) {
//     Serial.print("Rotary 1 = ");
//     Serial.print(newRotary1);
//     Serial.print(", Rotary 2 = ");
//     Serial.print(newRotary2);
//     Serial.println();
//     rotary1Position = newRotary1;
//     rotary2Position = newRotary2;
//   }
  // if a character is sent from the serial monitor,
  // reset both back to zero.
//   if (Serial.available()) {
//     Serial.read();
//     Serial.println("Reset both knobs to zero");
//     knobLeft.write(0);
//     knobRight.write(0);
//   }
// }