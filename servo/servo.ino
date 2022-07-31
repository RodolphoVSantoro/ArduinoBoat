#include <Servo.h> 
 
Servo myservo;  
char buffer[18];
int valor;
void setup() 
{ 
  Serial.begin(9600);
  Serial.flush();
  myservo.attach(9);
} 

int converte(char *data){
  Serial.print("Data:");
  Serial.println(data);
  int val = strtol(data, NULL, 10);
  
  for(int x = 0; x<16; x++){
    buffer[x] = '\0';
  }
  Serial.flush();
  Serial.println(val);
  return val;
}

void loop() 
{
  if(Serial.available() > 0){
    int index=0;
    delay(100);
    int numChar = Serial.available();
    if (numChar > 15){
      numChar=15;
    }
    while(numChar--){
      buffer[index++] = Serial.read();
    }
    valor = converte(buffer);
  }
  
  switch(valor)
  {
  case 1:
  Serial.println("foi");
  myservo.write(135);
  break;
  
  case 3:
  myservo.write(45);
  break;
  
  case 0:
  myservo.write(90);
  break;
} 
}
