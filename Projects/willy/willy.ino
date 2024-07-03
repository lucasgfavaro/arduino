/*

  Arduino Bluetooth Controlled Car
  Install Adafruit Motor Shield Library before uploading this code.
  AFMotor Library https://learn.adafruit.com/adafruit-motor-shield/library-install

  -> If you need helping guide on how to install library for the motor shield or how to use motor shield then
     watch this: https://youtu.be/vooJEyco1J4

     Caution: Remove the jumper or switch off the battery switch before connecting the Arduino board to computer.

     For more support contact me on Telegram: @UtGoTech


*/


#include <AFMotor.h>
#include <SoftwareSerial.h>

SoftwareSerial bluetoothSerial(9, 10); // RX, TX

//initial motors pin
 AF_DCMotor motor1(1, MOTOR12_64KHZ);
 AF_DCMotor motor2(2, MOTOR12_64KHZ);
 AF_DCMotor motor3(3, MOTOR34_64KHZ);
 AF_DCMotor motor4(4, MOTOR34_64KHZ);

char command;
int speed = 255;
int steeringSpeed = 130;

void setup()
{
  Serial.begin(9600);
  bluetoothSerial.begin(38400);
  Serial.println("OK");   //Set the baud rate to your Bluetooth module.
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
        backward(speed);
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
    motor1.run(FORWARD);  //rotate the motor clockwise
    motor2.run(FORWARD);  //rotate the motor clockwise
    motor3.run(FORWARD);  //rotate the motor clockwise
    motor4.run(FORWARD);  //rotate the motor clockwise 
   for (int speed = 110; speed <= 255; speed += 3) {
     motor1.setSpeed(speed); //Define maximum velocity
     motor2.setSpeed(speed); //Define maximum velocity
     motor3.setSpeed(speed); //Define maximum velocity
     motor4.setSpeed(speed); //Define maximum velocity
     delay(1);
   }
}

void backward(int speed)
{
    motor1.run(BACKWARD);  //rotate the motor clockwise
    motor2.run(BACKWARD);  //rotate the motor clockwise
    motor3.run(BACKWARD);  //rotate the motor clockwise
    motor4.run(BACKWARD);  //rotate the motor clockwise 
   for (int speed = 110; speed <= 255; speed += 3) {
     motor1.setSpeed(speed); //Define maximum velocity
     motor2.setSpeed(speed); //Define maximum velocity
     motor3.setSpeed(speed); //Define maximum velocity
     motor4.setSpeed(speed); //Define maximum velocity
     delay(1);
   }
}

void left(int speed)
{
  motor1.setSpeed(speed); //Define maximum velocity
  motor1.run(BACKWARD); //rotate the motor anti-clockwise
  motor2.setSpeed(speed); //Define maximum velocity
  motor2.run(BACKWARD); //rotate the motor anti-clockwise
  motor3.setSpeed(speed); //Define maximum velocity
  motor3.run(FORWARD);  //rotate the motor clockwise
  motor4.setSpeed(speed); //Define maximum velocity
  motor4.run(FORWARD);  //rotate the motor clockwise
}

void right(int speed)
{
  motor1.setSpeed(speed); //Define maximum velocity
  motor1.run(FORWARD);  //rotate the motor clockwise
  motor2.setSpeed(speed); //Define maximum velocity
  motor2.run(FORWARD);  //rotate the motor clockwise
  motor3.setSpeed(speed); //Define maximum velocity
  motor3.run(BACKWARD); //rotate the motor anti-clockwise
  motor4.setSpeed(speed); //Define maximum velocity
  motor4.run(BACKWARD); //rotate the motor anti-clockwise
}

void Stop()
{
  motor1.setSpeed(0);  //Define minimum velocity
  motor1.run(RELEASE); //stop the motor when release the button
  motor2.setSpeed(0);  //Define minimum velocity
  motor2.run(RELEASE); //rotate the motor clockwise
  motor3.setSpeed(0);  //Define minimum velocity
  motor3.run(RELEASE); //stop the motor when release the button
  motor4.setSpeed(0);  //Define minimum velocity
  motor4.run(RELEASE); //stop the motor when release the button
}
