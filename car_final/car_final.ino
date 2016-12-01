//Motor pins. 1 is right motor, 2 is left motor
const int motor1a = 4;
const int motor1b = 5;
const int motor1En = 3;
const int motor2a = 7;
const int motor2b = 8;
const int motor2En = 6;

//Motor states
int m1aState= LOW;
int m1bState = LOW;
int m1EnState= LOW;
int m2aState= LOW;
int m2bState= LOW;
int m2EnState= LOW;

//Toggle car active button pin
const int buttonPin = 12;

//Toggle start and stop state
const int ACTIVE = 1;
const int INACTIVE = 0;
int carStatus = ACTIVE;
int justStarted = ACTIVE;

//Sensor pins
const int leftPhotoPin = A0;
const int centerPhotoPin = A1;
const int rightPhotoPin = A2;

//Thresholds
int blackThreshold = 850;
int whiteThreshold = 250;
int redThreshold = 100;
int differenceThreshold = 30;

//Current State
const int RIGHT = 10;
const int LEFT = 11;
const int FORWARD = 12;
const int STOPPED = 13;
int state = STOPPED;

//Initialization function
void setup() {
  //Begin serial output
  Serial.begin(9600);
  Serial.print("We're alive\n");
  
  //Put each pin in the correct mode. 
  //Motor control pins are output
  pinMode(motor1a, OUTPUT); 
  pinMode(motor1b, OUTPUT);
  pinMode(motor2a, OUTPUT);
  pinMode(motor2b, OUTPUT);
  pinMode(motor1En, OUTPUT);
  pinMode(motor2En, OUTPUT);
  
  //Button pin is input
  pinMode(buttonPin, INPUT);
}

//Infinite loop called automatically by the Arduino board
void loop() {
  //Check to see if the active state is going to be toggled
//  int button = digitalRead(buttonPin);
//  if(button == HIGH) {
//    //Toggle the car status
//    if(carStatus == ACTIVE) {
//      carStatus = INACTIVE;
//      justStarted = INACTIVE;
//    }
//    else {
//      carStatus = ACTIVE;
//      justStarted = ACTIVE;
//    }
//    
//    //Wait for the button to be released
//    while(button == HIGH) {
//      button = digitalRead(buttonPin);
//      delay(100);
//      Serial.print("Status: ");
//      Serial.println(carStatus, DEC);
//    }
//  }
  
  int left = analogRead(leftPhotoPin);
  int right = analogRead(rightPhotoPin);
  int center = analogRead(centerPhotoPin);
  left = left - 25;
    
  Serial.print("Left: ");
  Serial.println(left, DEC);
  Serial.print("Center: ");
  Serial.println(center, DEC);
  Serial.print("Right: ");
  Serial.println(right, DEC);
  if(left < 625 && right < 625) {
      forward();
  } else if(center >= right && center >= left) {
    forward();  
  } else if(left >= center && left >= right) {
    turnCounterClockwise(); 
  } else if(right >= center && right >= left) {
    turnClockwise();
  } else {
    forward();
  }
//  //Do stuff only if the car is active
//  if(carStatus == ACTIVE) {
//    Serial.println("Active");
//    if(center >= right && center >= left /* && center >= blackThreshold/*(max(right, left) - center) > differenceThreshold */) {
//      if(state != FORWARD) {
//        forward();
//        state = FORWARD;
//      }
//    }
//    //Otherwise, if the right side is seeing black, turn left
//    else if(right >= center && right >= left /* && right >= blackThreshold/*(max(left, center) - right) > differenceThreshold */) {
//      if(state != RIGHT) {
//        turnClockwise();
//        state = RIGHT;
//      }
//    }
//    else if(left >= center && left >= right /* && left >= blackThreshold/*(max(center, right) - left) > differenceThreshold */) {
//      if(state != LEFT) {
//        turnCounterClockwise();
//        state = LEFT;
//      }
//    }
//  }
//  //If the car is not active, halt
//  else {
//    halt();
//  }

  //Wait 10 milliseconds before starting the loop again
  delay(10);
}

int computeThreshold(int left, int center, int right) {
  
}

void turnCounterClockwise()
{
  Serial.println("Turning CCW");
  //left motor backwards, right motor forward
  digitalWrite(motor1En, HIGH);
  m1EnState= HIGH;
  digitalWrite(motor1a, HIGH);
  m1aState= HIGH;
  digitalWrite(motor1b, LOW);
  m1bState= LOW;
  digitalWrite(motor2En, LOW);
  m2EnState= LOW;
  digitalWrite(motor2a, HIGH);
  m2aState= LOW;
  digitalWrite(motor2b, LOW);
  m2bState= LOW;

  delay(1);
  digitalWrite(motor1En, LOW);
  m1EnState = LOW;
  digitalWrite(motor2En, LOW);
  m2EnState = LOW;
  delay(5);
  digitalWrite(motor1En, HIGH);
  m1EnState = HIGH;
  digitalWrite(motor2En, LOW);
  m2EnState = LOW;  
  
}

void turnClockwise(){
  Serial.println("Turning CW");
  //left motor forward, right motor backwards
  digitalWrite(motor1En, LOW);
  m1EnState= LOW;
  digitalWrite(motor1a, HIGH);
  m1aState= HIGH;
  digitalWrite(motor1b, LOW);
  m1bState= LOW;
  digitalWrite(motor2En, HIGH);
  m2EnState= HIGH;
  digitalWrite(motor2a, HIGH);
  m2aState= LOW;
  digitalWrite(motor2b, LOW);
  m2bState= HIGH;

  delay(1);
  digitalWrite(motor1En, LOW);
  m1EnState = LOW;
  digitalWrite(motor2En, LOW);
  m2EnState = LOW;
  delay(5);
  digitalWrite(motor1En, LOW);
  m1EnState = LOW;
  digitalWrite(motor2En, HIGH);
  m2EnState = HIGH;
  
}

void halt(){
  //stops motors by turning enables for both motors off
  digitalWrite(motor1En, LOW);
  m1EnState= LOW;
  digitalWrite(motor2En, LOW);
  m2EnState= LOW;
}

void forward()
{
  Serial.println("Going Forward");
  //both motors forward
  digitalWrite(motor1En, HIGH);
  m1EnState= HIGH;
  digitalWrite(motor1a, HIGH);
  m1aState= HIGH;
  digitalWrite(motor1b, LOW);
  m1bState= LOW;
  digitalWrite(motor2En, HIGH);
  m2EnState= HIGH;
  digitalWrite(motor2a, HIGH);
  m2aState= HIGH;
  digitalWrite(motor2b, LOW);
  m2bState= LOW;

  delay(1);
  digitalWrite(motor1En, LOW);
  m1EnState = LOW;
  digitalWrite(motor2En, LOW);
  m2EnState = LOW;
  delay(10);
  digitalWrite(motor1En, HIGH);
  m1EnState = HIGH;
  digitalWrite(motor2En, HIGH);
  m2EnState = HIGH;
  
}

void backward() 
{
  Serial.println("Going Backwards");
  //both motors back
  digitalWrite(motor1En, HIGH);
  m1EnState= HIGH;
  digitalWrite(motor1a, LOW);
  m1aState= LOW;
  digitalWrite(motor1b, HIGH);
  m1bState= HIGH;
  digitalWrite(motor2En, HIGH);
  m2EnState= HIGH;
  digitalWrite(motor2a, LOW);
  m2aState= LOW;
  digitalWrite(motor2b, HIGH);
  m2bState= HIGH;

  delay(100);
//  digitalWrite(motor1En, LOW);
//  m1EnState = LOW;
//  digitalWrite(motor2En, LOW);
//  m2EnState = LOW;

}

void resume(){
  //restores states
 digitalWrite(motor1En, m1EnState);
 digitalWrite(motor1a, m1aState);
 digitalWrite(motor1b, m1bState);
 digitalWrite(motor2En, m2EnState);
 digitalWrite(motor2a, m2aState);
 digitalWrite(motor2b, m2bState);
}

  

