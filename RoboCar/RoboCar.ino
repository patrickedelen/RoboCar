/*
 * EE302 Robot Car Final Project
 */
 
// Enable is pin 8, HIGH enables the H-Bridge
#define ENABLE 8
// Define motor one
#define MOT1A 9
#define MOT1B 10
// Define motor 2
#define MOT2A 11
#define MOT2B 12
 
void setup() {
  // set all pins to output
  pinMode(ENABLE, OUTPUT);
  pinMode(MOT1A, OUTPUT);
  pinMode(MOT1B, OUTPUT);
  pinMode(MOT2A, OUTPUT);
  pinMode(MOT2B, OUTPUT);

  digitalWrite(ENABLE, HIGH);
  //Run the directions
  forward();
  reverse();
  stopAll();

  //end
  digitalWrite(ENABLE, LOW);
}

void forward() {
  //All forward
  digitalWrite(MOT1A, HIGH);
  digitalWrite(MOT1B, LOW);
  digitalWrite(MOT2A, HIGH);
  digitalWrite(MOT2B, LOW);
  delay(1000);
}

void reverse() {
  //All reverse
  digitalWrite(MOT1A, LOW);
  digitalWrite(MOT1B, HIGH);
  digitalWrite(MOT2A, LOW);
  digitalWrite(MOT2B, HIGH);
  delay(1000);
}

void stopAll() {
  digitalWrite(MOT1A, LOW);
  digitalWrite(MOT1B, LOW);
  digitalWrite(MOT2A, LOW);
  digitalWrite(MOT2B, LOW);
}

void loop() {
  // put your main code here, to run repeatedly:

}
