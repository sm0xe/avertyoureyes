int hackyOutPin = 11;
int buttonPin = 5;
int lightPin = 3; //3,5,6,9,10,11
int magnetPin = 4;
int soundPin = 6;

int lightLimit = 305; //Må tunes

void buttonWait(){
  bool status = digitalRead(buttonPin);
  Serial.println(status);
  while(status==LOW){
    delay(100);
    status = digitalRead(buttonPin);
    Serial.println(status); //DEBUG
  }
}

void lightWait(){
  int value = analogRead(lightPin);
  while(value>lightLimit){ //Kanskje >?
    delay(100);
    value = analogRead(lightPin);
    Serial.println(value); //DEBUG
  }
  Serial.println("\nLight task completed");
}

void magnetWait(){
  bool status = digitalRead(magnetPin);
  Serial.println(status);
  while(status==LOW){
    delay(100);
    status = digitalRead(magnetPin);
    Serial.println(status); //DEBUG
  }
  Serial.println("\nMagnet task completed");
}

void soundWait(){
  bool status = digitalRead(soundPin);
  Serial.println(status);
  while(status==LOW){
    delay(100);
    status = digitalRead(soundPin);
    Serial.println(status); //DEBUG
  }
  Serial.println("\nSound task completed");
}

void setup() {
  Serial.begin(115200);
  pinMode(hackyOutPin, OUTPUT);
  pinMode(buttonPin, INPUT);
  pinMode(magnetPin, INPUT);
  pinMode(lightPin, INPUT);
  pinMode(soundPin, INPUT);
  digitalWrite(hackyOutPin, HIGH);
  Serial.println("Ready");
}

void loop() {
  int magnetValue = digitalRead(magnetPin);
  int lightValue = analogRead(lightPin);
  int soundValue = digitalRead(soundPin);
  int buttonValue = digitalRead(buttonPin);
  Serial.print("{\"button\":");
  Serial.print(buttonValue);
  Serial.print(",\"light\":");
  Serial.print(lightValue);
  Serial.print(",\"sound\":");
  Serial.print(soundValue);
  Serial.print(",\"magnet\":");
  Serial.print(magnetValue);
  Serial.print("}\n");
  delay(100);
  /*while(Serial.available()>0){
    int task = Serial.parseInt();
    if (Serial.read() == '\n'){
      Serial.print("Starting task ");
      Serial.print(task);
      Serial.print("\n");
      switch(task){
        case 1:
          buttonWait();
          break;
        case 2:
          lightWait();
          break;
        case 3:
          magnetWait();
          break;
        case 4:
          soundWait();
          break;
        default:
          break;
      }
    }
  }*/
}
