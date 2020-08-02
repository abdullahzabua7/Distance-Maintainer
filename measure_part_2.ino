/* Welcome to Electronics hub of AZ.
 *  Here is the the program for diatnce maintainer.
 *  make sure how much distance want to keep apart please assign the properly.
 *  in this program we are measuring the ditanse is centimeter.
 */
// defines pins numbers
const int buzzer  = 8;
const int trigPin = 11;
const int echoPin = 12;


// defines variables
long duration;
int distance;

void setup() {
  pinMode(buzzer, OUTPUT);              // Sets the buzzer as an Output
  pinMode(trigPin, OUTPUT);             // Sets the trigPin as an Output
  pinMode(echoPin, INPUT);              // Sets the echoPin as an Input
  pinMode(2,OUTPUT);
  pinMode(3,OUTPUT);
  pinMode(4,OUTPUT);
  pinMode(5,OUTPUT);
  pinMode(6,OUTPUT);
  pinMode(7,OUTPUT);
  Serial.begin(9600);                   // Starts the serial communication
}

void loop() {
           
  digitalWrite(trigPin, LOW);           // Clears the trigPin
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);          // Sets the trigPin on HIGH state for 10 micro seconds
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  duration = pulseIn(echoPin, HIGH);
  // Serial.println (duration);// Reads the echoPin, returns the sound wave travel time in microseconds
  distance = duration * 0.034 / 2;      // Calculating the distance
  
  Serial.print("Distance: ");           // Prints the distance on the Serial Monitor
  Serial.print(distance);
  Serial.println("cm");

 
  if(distance <=7){        // write the distance you want to maintain.
    tone(buzzer,1000,200);
    delay(700);
    digitalWrite(2,HIGH);
    digitalWrite(3,HIGH);
    digitalWrite(4,HIGH);
    Serial.print("Distance: ");           
    Serial.print(distance);
    Serial.println("cm");
    Serial.println("Maintain ditsance.Go Back.");
    delay(1000);
    digitalWrite(2,LOW);
    digitalWrite(3,LOW);
    digitalWrite(4,LOW);
    
  }
  else {
    digitalWrite(5,HIGH);
    digitalWrite(6,HIGH);
    digitalWrite(7,HIGH);
    delay(1000);
    digitalWrite(5,LOW);
    digitalWrite(6,LOW);
    digitalWrite(7,LOW);
  }
  
}
