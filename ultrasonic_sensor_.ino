const int trigPin = 23;
const int echoPin = 19;
#define LEDPIN1 32
#define LEDPIN2 33

long duration;
int distance,min_distance,max_distance,brightness;


void setup() {
  //set trigPin as OUTPUT, echoPin as INPUT
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  //LED pins for HCSR04 sensor
  pinMode(LEDPIN1, OUTPUT); //Sets LED 1 as OUTPUT
  pinMode(LEDPIN2, OUTPUT); // Sets LED 2 as OUTPUT 
  
  Serial.begin(9600);
}

void loop() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);
  
  distance = (duration*0.03432)/2;
  // set the minimum and maximum distances for the LED brightness
  min_distance = 0;
  max_distance = 100;

  //map the distance to a value between 255 and 0
  brightness = map(distance, min_distance, max_distance, 255, 0);

  //limit the brightness to a value between 0 and 255
  brightness = constrain(brightness, 0, 255);

  //LED brightness depending on distance from obstacle
  analogWrite(LEDPIN1, brightness);
  analogWrite(LEDPIN2, brightness);

  Serial.print("Distance: ");
  Serial.println(distance);

}
