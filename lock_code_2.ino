#include <IRremote.h>
#define IR_RECEIVE_PIN 7
#define IR_BUTTON_1 12
#define IR_BUTTON_2 24
#define IR_BUTTON_3 94
#define IR_BUTTON_PLAY_PAUSE 64

#include <Servo.h>

Servo myservo;  // create servo object to control a servo
// twelve servo objects can be created on most boards

int pos = 0;    // variable to store the servo position



void setup() {
  Serial.begin(9600);
  IrReceiver.begin(IR_RECEIVE_PIN);
  //myservo.attach(9);
  
}
void loop() {
  if (IrReceiver.decode()) {
    IrReceiver.resume();
    int command = IrReceiver.decodedIRData.command;
    switch (command) {
      case IR_BUTTON_1: {
        Serial.println("Pressed on button 1");
        myservo.attach(9);
         pos = pos + 180;
         myservo.write(pos);              // tell servo to go to position in variable 'pos'
         delay(1000);
         myservo.detach();
        break;
      }
      case IR_BUTTON_2: {
        myservo.attach(9);
        pos = pos - 180;
        myservo.write(pos);              // tell servo to go to position in variable 'pos'
        delay(1000);
        myservo.detach(); 
         
        break;
      }
      
      case IR_BUTTON_3: {
        Serial.println("Pressed on button 3");
        break;
      }
      case IR_BUTTON_PLAY_PAUSE: {
        Serial.println("Pressed on button play/pause");
        break;
      }
      default: {
        Serial.println("Button not recognized");
      }
    }
  }
    } 
