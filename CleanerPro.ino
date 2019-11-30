//standard library
#include<Servo.h>


const int trigPin = 4;
 
const int echoPin = 3;
int enA = 10;
int in1 = 9;
int in2 = 8;



//define our servos
Servo servo1;
Servo servo2;
Servo servo3;
//Servo servo4;

//servo position in degrees
int serpos=0;

void setup()
{ Serial.begin(9600);
  pinMode(trigPin,INPUT);
  pinMode(trigPin, OUTPUT);
  servo1.attach(5); 
  servo2.attach(6);
  servo3.attach(2);
  servo1.write(0);
  servo2.write(0);
  servo3.write(0);
 
  pinMode(enA, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  
}

void loop()
{
  long duration, inches, cm;
  
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  duration = pulseIn(echoPin, HIGH);
 // convert the time into a distance
 
 inches = microsecondsToInches(duration);
 
 cm = microsecondsToCentimeters(duration);
 
 //Tell the Arduino to print the measurement in the serial console
 
 Serial.print(inches);
 
 Serial.print("in, ");
 
 Serial.print(cm);
 
 Serial.print("cm");
 
 Serial.println();

 delay(100);
 
 // This if-else statement tells the Arduino at what distance
 
 // it should trigger the servo, what the servo should do,
 
 // and what it should do if the distance is too far away.
 
 if (inches <= 1) 
 {
  sweep();
  demoOne();
  
  
 }
 
 else if (inches >= 1) 
 {
  servo1.write(serpos);
  servo2.write(serpos);
  servo3.write(serpos);
  //servo4.write(serpos);

  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);  
  

 }
 
 
 
 // Tell the Arduino to wait 0.10 seconds before pinging the
 
 // Ultrasonic Sensor again.
 
 delay(100);
 
}


long microsecondsToInches(long microseconds)
 
{
 
 // According to Parallax's datasheet for the PING))), there are
 
 // 73.746 microseconds per inch (i.e. sound travels at 1130 feet per
 
 // second). This gives the distance travelled by the ping, outbound
 
 // and return, so we divide by 2 to get the distance of the obstacle.
 
 // See: http://www.parallax.com/dl/docs/prod/acc/28015-PING-v1.3.pdf
 
 return microseconds / 74 / 2;
 
}
long microsecondsToCentimeters(long microseconds) 
{
  // The speed of sound is 340 m/s or 29 microseconds per centimeter.
  // The ping travels out and back, so to find the distance of the
  // object we take half of the distance travelled.
  return microseconds / 29 / 2;
}


void sweep()
 
{ 
  //scan from 0 to 90 degrees
  for(serpos=0;serpos<180;serpos+=15)
  {
    servo1.write(serpos);
    servo2.write(serpos);
    servo3.write(serpos);
    //servo4.write(serpos);
    delay(20);
  }
  for(serpos=180;serpos>0;serpos-=15)
  {
    servo1.write(serpos);
    servo2.write(serpos);
    servo3.write(serpos);
    //servo4.write(serpos);
    delay(20);
    
  }
  
}

void demoOne()
{
  digitalWrite(in1,HIGH);
  digitalWrite(in2,LOW);
  // set speed to 200 out of possible range 0~255
  digitalWrite(enA, 100);
  //Serial.print("a");
  //delay(2000);
  
}
