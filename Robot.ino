#include <NewPing.h>

#define TRIGGER_PIN  46  // Arduino pin tied to trigger pin on the ultrasonic sensor.
#define ECHO_PIN     48  // Arduino pin tied to echo pin on the ultrasonic sensor.
#define MAX_DISTANCE 200 // Maximum distance we want to ping for (in centimeters). Maximum sensor distance is rated at 400-500cm.
int red[] = {255, 0, 0};
int green[] = {0, 255, 0};
int blue[] = {0, 0, 255};

NewPing sonar_right(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE); // NewPing setup of pins and maximum distance.
//NewPing sonar_left(26, 28, MAX_DISTANCE);
void setup() {
  // put your setup code here, to run once:
  pinMode(13, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(A10, OUTPUT);

  pinMode(46, OUTPUT);
  pinMode(48, OUTPUT);


  Serial.begin(9600);
}

void loop() {
  //put your main code here, to run repeatedly:
  /*
  if(sonar_right.ping_cm() > 15  && sonar_left.ping_cm() > 15)
    moveForward(10, 255);
  else{
    moveBackward(300, 200);
    delay(300);
      if(sonar_right.ping_cm() > sonar_left.ping_cm() + 2)
        turnRight(300, 255);
       else
        turnLeft(300, 255);
    delay(300);
    
  }
  */
  moveForward(1000, 255);
  moveBackward(1000, 255);
  turnRight(1000, 255);
  turnLeft(1000, 255);
}
void turnOffLights(){
  analogWrite(10, 255);
  analogWrite(7, 255);
  analogWrite(6, 255);
  analogWrite(5, 255);
  analogWrite(4, 255);
  analogWrite(2, 255);
}
void lightRight(int color[]){
  analogWrite(10, 255 - color[0]);
  analogWrite(7, 255 - color[1]);
  analogWrite(6, 255 - color[2]);
}
void lightLeft(int color[]){
  analogWrite(5, 255 - color[0]);
  analogWrite(4, 255 - color[1]);
  analogWrite(2, 255 - color[2]);
}
void moveForward(int t, int s){
  lightRight(green);
  lightLeft(green);
  digitalWrite(13, HIGH);
  digitalWrite(12, HIGH);
  digitalWrite(9, LOW);
  digitalWrite(8, LOW);
  analogWrite(11, 255);
  analogWrite(3, 255);
  delay(100);
  analogWrite(11, s);
  analogWrite(3, s);
  delay(t);
  analogWrite(11, 0);
  analogWrite(3, 0);
  digitalWrite(9, HIGH);
  digitalWrite(8, HIGH);
  turnOffLights();
}
void moveBackward(int t, int s){
  lightRight(blue);
  lightLeft(blue);
  digitalWrite(13, LOW);
  digitalWrite(12, LOW);
  digitalWrite(9, LOW);
  digitalWrite(8, LOW);
  analogWrite(11, 255);
  analogWrite(3, 255);
  delay(100);
  analogWrite(11, s);
  analogWrite(3, s);
  delay(t);
  analogWrite(11, 0);
  analogWrite(3, 0);
  digitalWrite(9, HIGH);
  digitalWrite(8, HIGH);
  turnOffLights();
}
void turnRight(int t, int s){
  lightRight(blue);
  lightLeft(green);
  digitalWrite(13, HIGH);
  digitalWrite(12, LOW);
  digitalWrite(9, LOW);
  digitalWrite(8, LOW);
  analogWrite(11, 255);
  analogWrite(3, 255);
  delay(100);
  analogWrite(11, s);
  analogWrite(3, s);
  delay(t);
  analogWrite(11, 0);
  analogWrite(3, 0);
  digitalWrite(9, HIGH);
  digitalWrite(8, HIGH);
  turnOffLights();
}
void turnLeft(int t, int s){
  lightRight(green);
  lightLeft(blue);
  digitalWrite(13, LOW);
  digitalWrite(12, HIGH);
  digitalWrite(9, LOW);
  digitalWrite(8, LOW);
  analogWrite(11, 255);
  analogWrite(3, 255);
  delay(100);
  analogWrite(11, s);
  analogWrite(3, s);
  delay(t);
  analogWrite(11, 0);
  analogWrite(3, 0);
  digitalWrite(9, HIGH);
  digitalWrite(8, HIGH);
  turnOffLights();
}

