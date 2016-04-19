#include <NewPing.h>
#define MAX_DISTANCE 100
#define LEFT  0
#define MIDDLE  1
#define RIGHT  2

int ir_array[2];//For IR sensors
int sonar_array[3];//For Sonar Sensors 0 = Left, 1 = Middle, 2 = Right
int dir[] = {0, 0};//For motor direction
int t, s;//for motor time on and movement speed
int turn_count = 0;//fire condition for u-turn
bool turn_around_condition = 0;//fire condition to update turn_count
NewPing sonarL(22, 24, MAX_DISTANCE);//Left sonar
NewPing sonarM(26, 28, MAX_DISTANCE);//Middle sonar
NewPing sonarR(30, 32, MAX_DISTANCE);//Right sonar

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(13 , OUTPUT);
  pinMode(12 , OUTPUT);
  pinMode(9 , OUTPUT);
  pinMode(8 , OUTPUT);
  t = 300;//motor fire time
  s = 255;//motor speed
}

void loop() {
  // Robot Loop 
  t = 300; 
  while(fast_move()){
    turn_count = 0;
    forward();
    t = 1000;
    take_step(dir, s, t);
  }
  get_data();
  print_data();
  think();
  //turn_around();
  delay(1000);
  take_step(dir, s, t);  
  Serial.println("=====================");
}
bool fast_move(){
  get_data();
  if(sonar_array[0] == 100 && sonar_array[1] == 100 && sonar_array[2] == 100)
    return true;
  else
    return false;
}
void get_data(){

  //get IR Data
  //0 = left, 1 = middle, 2 = right
  //ir_array[0] = analogRead(3);
  //delay(100);
  //ir_array[1] = analogRead(4);
  //delay(50);
  //ir_array[1] = analogRead(5);
  //delay(50);
  sonar_array[LEFT] = sonarL.ping_cm();
  if(sonar_array[LEFT] == 0)
    sonar_array[LEFT] =  100;
  //delay(100);
  sonar_array[MIDDLE] = sonarM.ping_cm();
  if(sonar_array[MIDDLE] == 0)
    sonar_array[MIDDLE] =  100;
  //delay(100);
  sonar_array[RIGHT] = sonarR.ping_cm();
  if(sonar_array[RIGHT] == 0)
    sonar_array[RIGHT] =  100;
  //delay(100);

  //get Ultrasonic Ping Data

  
}
void print_data(){
  Serial.print("Left Sonar: ");
  Serial.println(sonar_array[0]);
  //Serial.print("Left IR: ");
  //Serial.println(ir_array[0]);
  Serial.print("Middle Sonar: ");
  Serial.println(sonar_array[1]);
  Serial.print("Right Sonar: ");
  Serial.println(sonar_array[2]);
  //Serial.print("Right IR: ");
  //Serial.println(ir_array[1]);
  Serial.println("-------------------"); 
}
void think(){
    t = 300;
   if((sonar_array[LEFT] < 25 && sonar_array[MIDDLE] < 25 && sonar_array[RIGHT] && 25) || sonar_array[MIDDLE] < 10){
      dir[0] = 1;
      dir[1] = 1;
      t = 1000;
      Serial.println("backwards");
   }else if(turn_count > 4){
      turn_around();
   }else if(sonar_array[LEFT] < sonar_array[RIGHT] || sonar_array[MIDDLE] < sonar_array[RIGHT]){
      turn_right();
      take_step( dir,  s,  t);
      forward();
      Serial.println("right");
      if(turn_around_condition == 1)
        turn_count++;
       else
        turn_count = 0;
      turn_around_condition = 0;  
   }else if(sonar_array[RIGHT] < sonar_array[LEFT] || sonar_array[MIDDLE] < sonar_array[LEFT]){
      turn_left();
      take_step( dir,  s,  t);
      forward();
      Serial.println("left");
      if(turn_around_condition == 0)
        turn_count++;
      else
        turn_count = 0;
      turn_around_condition = 1;
   }else{
      dir[0] = 0;
      dir[1] = 0;
      Serial.println("forward");
      t = 1000;
      turn_count = 0;
   }
}
void take_step(int dir[], int s, int t){
  digitalWrite(13, dir[0]);
  digitalWrite(12, dir[1]);
  analogWrite(11, s);
  analogWrite(3, s);
  digitalWrite(9, LOW);
  digitalWrite(8, LOW);
  delay(t);
  analogWrite(11, 0);
  analogWrite(3, 0);
  digitalWrite(9, HIGH);
  digitalWrite(8, HIGH);
}
void turn_right(){
  dir[0] = 0;
  dir[1] = 1;
}
void turn_left(){
  dir[0] = 1;
  dir[1] = 0;
}
void forward(){
  dir[0] = 0;
  dir[1] = 0;
}
void turn_around(){
  turn_right();
  take_step(dir, s, 2500);
  turn_count = 0;
}












