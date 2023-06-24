#define trigPin 12 // define trigger pin in pin 12
#define echoPin 13 // define echo pin in pin 13

int leftwheel = 10; //initialize the leftwheel in pin 10
int rightwheel = 11; // initialize the rightwheel in pin 11
 
void setup()
{ 
  pinMode(trigPin, OUTPUT);// set the trigger pin as outpput
  pinMode(echoPin, INPUT);// set the echo pin as input

  pinMode(leftwheel, OUTPUT); //set the leftwheel as output
  pinMode(rightwheel, OUTPUT); //set the rightwheel as output
  digitalWrite(leftwheel, LOW); //set leftwheel as low
  digitalWrite(rightwheel, LOW); // set rightwheel as low
}
 
void loop() {

  int duration, distance; // start the scan
  
  digitalWrite(trigPin, LOW); //sets trigger pin low in sending waves
  delayMicroseconds(2); // delay for 2 miliseconds.
  
  digitalWrite(trigPin, HIGH); // sets trigger pin high in sending waves
  delayMicroseconds(10); //delay for 10 miliseconds
  
  digitalWrite(trigPin, LOW); //sets tigger pin low
  
  duration = pulseIn(echoPin, HIGH); //sets duration with the recieved waves
  distance = (duration/2) / 29.1;// convert the distance to centimeters.

if (distance>0 && distance < 5) //if the given distance is already 5cm this will process

{   
 
 digitalWrite(leftwheel, HIGH); //set the leftwheel as High
 digitalWrite(rightwheel, HIGH); //set the rightwheel as High
 delay(500); //wait for 500 milisecond before it stops
 
 } 

else  
{

digitalWrite(leftwheel,LOW); //set leftwheel as low
digitalWrite(rightwheel, LOW); // set rightwheel as low
delay(500); // wait for 500 milisecond before it stops

}
}

