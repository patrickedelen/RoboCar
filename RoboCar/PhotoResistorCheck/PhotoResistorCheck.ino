//photoresistor pins
const int leftPhotoPin = A0;
const int centerPhotoPin = A1;
const int rightPhotoPin = A2;

void setup() {
  
  //Start serial
  Serial.begin(9600);
  Serial.print("We're alive\n");

}

void loop() {
  
  int leftAnalog = analogRead(leftPhotoPin);
  int rightAnalog = analogRead(rightPhotoPin);
  int centerAnalog = analogRead(centerPhotoPin);
    
  Serial.print("Left: ");
  Serial.println(leftAnalog, DEC);
  Serial.print("Center: ");
  Serial.println(centerAnalog, DEC);
  Serial.print("Right: ");
  Serial.println(rightAnalog, DEC);

  delay(2000);

}
