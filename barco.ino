char buffer[18];
//Leme(portas 5 e 7) no M1 e Motor(portas 6 e 8) no M2
int valor;
int velocidadeLeme = 5; // HIGH = ligado, LOW = desligado
int velocidade = 6;
int direcaoLeme = 7; // HIGH = direita, LOW = esquerda
int direcao = 8;
int potenciometro = 1; // 0 = esquerda,1 = meio,  2 = direita
int servo = -1;
int motor = -1;

void setup() 
{ 
  Serial.begin(9600);
  Serial.flush();
  
  pinMode(velocidade, OUTPUT);
  pinMode(direcao, OUTPUT);
  pinMode(velocidadeLeme, OUTPUT);
  pinMode(direcaoLeme, OUTPUT);
} 

int converte(char *data){
  int val = strtol(data, NULL, 10);
  
  for(int x = 0; x<16; x++){
    buffer[x] = '\0';
  }
  Serial.flush();
  return val;
}
void metade_esquerda()
{
  digitalWrite(direcaoLeme, LOW);
  analogWrite(velocidadeLeme, 150);
  delay(150);
  digitalWrite(velocidadeLeme, LOW);
}
void giro_esquerda()
{
  digitalWrite(direcaoLeme, LOW);
  analogWrite(velocidadeLeme, 200);
  delay(300);
  digitalWrite(velocidadeLeme, LOW);
}
void metade_direita()
{
  digitalWrite(direcaoLeme, HIGH);
  analogWrite(velocidadeLeme, 150);
  delay(150);
  digitalWrite(velocidadeLeme, LOW);
}
void giro_direita()
{
  digitalWrite(direcaoLeme, HIGH);
  analogWrite(velocidadeLeme, 200);
  delay(300);
  digitalWrite(velocidadeLeme, LOW);
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
      if(valor == 8)
      {
        Serial.println("Pra frente");
      }
      if(valor == 2)
      {
        Serial.println("Pra tras");
      }
  }
  if(valor == 4 || valor == 5 || valor == 6)
    {
      servo = valor;
    }
    else
    {
      if(valor == 8 || valor == 2)
      {
        motor = valor;
      }
      else
      {
        motor = -1;
        servo = -1;
        if(potenciometro == 0)
        {
          metade_direita();
          potenciometro = 1;
          Serial.println("Esta agora no meio");
        }
        if(potenciometro == 2)
        {
          metade_esquerda();
          potenciometro = 1;
          Serial.println("Esta agora no meio");
        }
      }
    }
  
  switch(servo)
  {
    case 4: //leme pra esquerda
    if(potenciometro == 1)
    {
      metade_esquerda();
      potenciometro = 0;
      Serial.println("Esta agora na esquerda");
    }
    else{
      if(potenciometro == 2)
          {
            giro_esquerda();
            potenciometro = 0;
            Serial.println("Esta agora na esquerda");
          }
     }
    break;

    case 5: // leme pro meio
    if(potenciometro == 0)
    {
      metade_direita();
      potenciometro = 1;
      Serial.println("Esta agora no meio");
    }
    else{
      if(potenciometro == 2)
          {
            metade_esquerda();
            potenciometro = 1;
            Serial.println("Esta agora no meio");
          }
     }
    break;
    
    case 6: // leme pra direita
    if(potenciometro == 0)
    {
      giro_direita();
      potenciometro = 2;
      Serial.println("Esta agora na direita");
    }
    else
    {
      if(potenciometro == 1)
          {
            metade_direita();
            potenciometro = 2;
            Serial.println("Esta agora na direita");
          }
     }
    break;
    
    default:
    
    if(potenciometro == 1)
    {
      digitalWrite(velocidadeLeme, LOW);
    }
    else
    {
      if(potenciometro == 0)
      {
        metade_direita();
        potenciometro = 1;
      }
        if(potenciometro == 2)
        {
          metade_esquerda();
          potenciometro = 1;
        }
     }
    break;
  }
  switch(motor){
  
  case 2:
  digitalWrite(direcao, LOW);
  analogWrite(velocidade, 200);
  break;
  
  case 8:
  digitalWrite(direcao, HIGH);
  analogWrite(velocidade, 200);
  break;
  
  default:
  digitalWrite(velocidade, LOW);
  break;
  }
} 

