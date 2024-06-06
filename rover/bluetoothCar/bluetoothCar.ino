#include <AFMotor.h>
#include <SoftwareSerial.h>

SoftwareSerial bluetoothSerial(9, 10); // RX, TX

 // Initial motors pin
 AF_DCMotor motor1(1, MOTOR12_64KHZ);
 AF_DCMotor motor2(2, MOTOR12_64KHZ);
 AF_DCMotor motor3(3, MOTOR34_64KHZ);
 AF_DCMotor motor4(4, MOTOR34_64KHZ);

char command;
// Back and forth speed at maximum speed
int speed = 255;
// steering reduce almost to the half to have better control
int steeringSpeed = 130;

void setup()
{
  Serial.begin(9600);
  //Set the baud rate to your Bluetooth module
  bluetoothSerial.begin(9600); 
}

void loop() {

  if (bluetoothSerial.available() > 0) {
    
    command = bluetoothSerial.read();
    Serial.println(command); 

    Stop(); //initialize with motors stoped
    
    switch (command) {
      case 'F':
        forward(speed);
        break;
      case 'B':
        back(speed);
        break;
      case 'L':
        left(steeringSpeed);
        break;
      case 'R':
        right(steeringSpeed);
        break;
    }
  }
}

void forward(int speed)
{
    motor1.run(FORWARD);
    motor2.run(FORWARD); 
    motor3.run(FORWARD);
    motor4.run(FORWARD);
    // Progressive velocity
    // TODO: Is this possible to achive in any other way?
   for (int speed = 110; speed <= 255; speed += 3) {
     motor1.setSpeed(speed);
     motor2.setSpeed(speed);
     motor3.setSpeed(speed);
     motor4.setSpeed(speed);
     delay(1);
   }
}

void back(int speed)
{
  motor1.setSpeed(speed);
  motor1.run(BACKWARD);
  motor2.setSpeed(speed);
  motor2.run(BACKWARD);
  motor3.setSpeed(speed);
  motor3.run(BACKWARD);
  motor4.setSpeed(speed);
  motor4.run(BACKWARD);
}

void left(int speed)
{
  motor1.setSpeed(speed);
  motor1.run(BACKWARD);
  motor2.setSpeed(speed);
  motor2.run(BACKWARD);
  motor3.setSpeed(speed);
  motor3.run(FORWARD);
  motor4.setSpeed(speed);
  motor4.run(FORWARD);
}

void right(int speed)
{
  motor1.setSpeed(speed);
  motor1.run(FORWARD);
  motor2.setSpeed(speed);
  motor2.run(FORWARD);
  motor3.setSpeed(speed);
  motor3.run(BACKWARD);
  motor4.setSpeed(speed);
  motor4.run(BACKWARD);
}

void Stop()
{
  motor1.setSpeed(0);
  motor1.run(RELEASE);
  motor2.setSpeed(0);
  motor2.run(RELEASE);
  motor3.setSpeed(0);
  motor3.run(RELEASE);
  motor4.setSpeed(0);
  motor4.run(RELEASE);
}
