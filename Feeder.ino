#include <Servo.h>

Servo myservo;
#define servoPin 3
#define pushButtonPin 2

int angle =90;
int angleStep =10;
const int minAngle = 0;
const int maxAngle = 140;

const int type =2;

int buttonPushed =0;

void setup() {

  Serial.begin(9600);
  myservo.attach(servoPin);
  pinMode(pushButtonPin,INPUT_PULLUP);
   Serial.println("Robojax Servo Button ");
   myservo.write(angle);
}

void loop() {
  if(digitalRead(pushButtonPin) == LOW){
    buttonPushed = 1;
  }
   if( buttonPushed ){

  angle = angle + angleStep;


    if (angle >= maxAngle) {
      angleStep = -angleStep;
        if(type ==1)
        {
            buttonPushed =0;
        }
    }

    if (angle <= minAngle) {
      angleStep = -angleStep;
       if(type ==2)
        {
            buttonPushed =0;
        }
    }

    myservo.write(angle);
      Serial.print("Moved to: ");
      Serial.print(angle);
      Serial.println(" degree");
  delay(100);
   }


}
