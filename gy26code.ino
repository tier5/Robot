char valuebyte[8];
int degree = 0;
int counter = 0;
byte value = 0;
int a =0;
void setup() 
{
Serial.begin(9600);
Serial1.begin(9600);
}

void loop() 
{
 rotation();
}

int rotation() 
{
value = 0;
Serial1.write(0x31);
while (value == 0) 
{
 if (Serial1.available()) 
  {
      valuebyte[counter] = Serial1.read();
      counter = (counter + 1) % 8;
      if (counter == 0) 
      {
        degree = (valuebyte[2] - 48) * 100 + (valuebyte[3] - 48) * 10 + (valuebyte[4] - 48);
        value = 1;
      }
   }
}
 
  return degree;
}
