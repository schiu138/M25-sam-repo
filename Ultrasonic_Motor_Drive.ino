const int trigPin = 7;
const int echoPin = 8;
  
void setup() {
  Serial.begin(115200);

  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}

void loop() {
  long duration;
  float distance;

  // Clear the trigger pin
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  //Send 10 microsecond pulse to trigger
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin,LOW);

  // Read the echo pin (time in microseconds)
  duration = pulseIn(echoPin, HIGH);

  // Convert time to distance (cm)
  distance = (duration * 0.034) / 2;

  // Blinks LED when an object 8 inches (20.32 cm) or closer 
  if (distance <= 20.32){
    digitalWrite(13, HIGH);
    delay(500);
    digitalWrite(13,LOW);}

  //Print result
  Serial.print("Distance:");
  Serial.print(distance);
  Serial.println(" cm");

  delay(500); // half second delay between readings
}
