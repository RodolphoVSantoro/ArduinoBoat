int velocidade = 5; //m1
int direcao = 7;
// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin 13 as an output.
  pinMode(direcao, OUTPUT);
  pinMode(velocidade, OUTPUT);
}

// the loop function runs over and over again forever
void loop() {
  digitalWrite(direcao, LOW);
  analogWrite(velocidade, 200);
  delay(5000);
  digitalWrite(velocidade, LOW);
  delay(1000);
  digitalWrite(direcao, HIGH);
  analogWrite(velocidade, 200);
  delay(5000);
  digitalWrite(velocidade, LOW);
  delay(1000);
}
