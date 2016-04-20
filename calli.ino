void setup()
{
Serial.begin(9600);
Serial1.begin(9600);
}
void loop()
{
//calliberate(5);
}
void calliberate(int triggerpin)
{
Serial1.write(0xC0);
pinMode(triggerpin,OUTPUT);  
digitalWrite(triggerpin,HIGH);
delay(200);
digitalWrite(triggerpin,LOW);
delay(200);
digitalWrite(triggerpin,HIGH);
delay(200);
Serial1.write(0xC1);
}
