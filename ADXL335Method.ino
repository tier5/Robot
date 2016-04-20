
int x = 0;      
int y = 0;      
int z = 0;      
int pinx = 3; //Pin number for analog input
int piny = 2; //Pin number for analog input
int pinz = 1; //Pin number for analog input 
void setup()
{ 
  Serial.begin(9600);  
}

void loop()
{
int a = coordinatex();
Serial.println(a);
int b = coordinatey();
Serial.println(b);
int c =coordinatez();
Serial.println(c);
delay(1000);
}

int coordinatex()
{
  x  = analogRead(pinx);    
  //Serial.print("X = ");  
  //Serial.println(x);
  //delay(1000);
  return x;
}
int coordinatey()
{
  y  = analogRead(piny);    
 //Serial.print("Y = ");  
  //Serial.println(y);
  //delay(1000);
  return y;
}
int coordinatez()
{
  z  = analogRead(pinz);    
  //Serial.print("Z = ");  
  //Serial.println(z);
  //delay(1000);
  return z;
}
