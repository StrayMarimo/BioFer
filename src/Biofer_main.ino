// Relay with 2 servo motors and 1 weight sensor
#include <Servo.h> //include the library for servo
#include <HX711_ADC.h> // iclude the library for HX711 with Load Cell

  Servo servoleft; //initialize servo for the left hand
  Servo servoright; //initialize servo for the right hand

HX711_ADC LoadCell(8,9);  //attach dout to pin 8 and sck to pin 9 
  
int channelblender = 7;  //This is the Arduino Pin that will contr  ol the blender
int channelsuction pump = 6;  //This is the Arduino Pin that will control the suction pump
int channelpulverizer = 5;  //This is the Arduino Pin that will control the pulverizer
int channelarduino = 4; //This is the Arduino Pin that will control Relay #4
  
  void setup() 
  {
    LoadCell.begin(); // the load cell will initialize
    LoadCell.start(2000); // will wait for 2 seconds for calibration
    LoadCell.setCalFactor(696.0); // set the calibration factor
    
  pinMode(channelblender, OUTPUT); //set pin 7 as output+
  pinMode(channelsuction pump, OUTPUT); //set pin 6 as output
  pinMode(channelpulverizer, OUTPUT); //set pin 5 as output
  pinMode(channelarduino, OUTPUT); //set pin 4 as output
 
  digitalWrite(channelblender, LOW); //set pin 7 as output
  digitalWrite(channelsuction pump, LOW); //set pin 6 as output
  digitalWrite(channelpulverizer, LOW); //set pin 5 as output
  digitalWrite(channelarduino, LOW); //set pin 4 as output
  
 servoleft.attach(10); //attach the left servo in pin 10
 servoright.attach (11); //attachthe right servo in pin 11
 

}

void loop() 
{

LoadCell.update();
float i = LoadCell.getData();

if (i>0 && i < 25) // the process will continue if the variable i is greater than 0 and less than 25
{

servoleft.write(180); //write the left servo in 180 degrees
servoright.write(0); //write the right servo in 0 degrees
delay (5000); //wait for 5 seconds

servoleft.write(90); //write the left servo in 90 degress
servoright.write(90); //write the left servo in 90 degrees
delay (5000); //wait for 5 seconds

  digitalWrite(channelblender, HIGH); // turn blender on
  delay(60000); // wait for 1 minute
  digitalWrite(channelblender, LOW); // turn blender off
  delay (10000); // wait for 10 seconds
  
  digitalWrite(channelblender, HIGH);//turn blender on
  digitalWrite(channelsuction pump, HIGH); //turn suction pump on
  delay(60000); // wait for 1 minute
  digitalWrite(channelblender, LOW); // turn blender off
  digitalWrite(channelsuction pump, LOW); //turn  suction pump off
  delay(10000); // wait for 10 seconds
  
  digitalWrite(channelblender, HIGH); // turn blender on
  digitalWrite(channelsuction pump, HIGH); // turn suction pump on
  delay(60000); // wait for 1 minute
  digitalWrite(channelblender, LOW); // turn blender off
  digitalWrite(channelsuction pump, LOW); // turn suction pump off
  delay(10000); // wait for 10 seconds  

  digitalWrite(channelpulverizer, HIGH); // turn pulverizer on
  delay(60000); // wait for 1 minute
  digitalWrite(channelpulverizer, LOW); // turn pulverizer off
  delay(10000); // wait for 10 seconds
  
  digitalWrite(channelpulverizer, HIGH); // turn pulverizer on
  digitalWrite(channelsuction pump, HIGH); //turn suction pump on
  delay(60000); // wait for 1 minute
  
  digitalWrite(channelpulverizer, LOW); // turn pulverizer off
  digitalWrite(channelsuction pump, LOW); //turn suction pump off
  delay(10000); // wait for 10 seconds

  digitalWrite(channelpulverizer, HIGH); // turn pulverizer on
  digitalWrite(channelsuction pump, HIGH); // turn suction pump on
  delay(60000); // wait for 1 minute
  
  digitalWrite(channelpulverizer, LOW); // turn pulverizer off
  digitalWrite(channelsuction pump, LOW); // turn pulverizer off
  delay(10000); // wait for 10 seconds

}
}}
