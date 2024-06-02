// Adafruit Motor shield library
// copyright Adafruit Industries LLC, 2009
// this code is public domain, enjoy!

#include <AFMotor.h>

//AF_DCMotor motor(4);

AF_DCMotor motor_izq1(1);
AF_DCMotor motor_izq2(2);
AF_DCMotor motor_der1(4);
AF_DCMotor motor_der2(3);
int potencia = 170;

void setup() {
  Serial.begin(9600);  // set up Serial library at 9600 bps
  Serial.println("Motor test!");
  
}

void loop() {
  Serial.print("tick");
  adelante(potencia);
  //delay(2000);
  izquierda(potencia);
  delay(7000);
}


void adelante(int potencia) {
  uint8_t i;
  motor_der1.run(FORWARD);
  motor_izq1.run(FORWARD);
  motor_der2.run(FORWARD);
  motor_izq2.run(FORWARD);

//  for (i = 1; i < 200; i++) {
    motor_der1.setSpeed(potencia);
    motor_izq1.setSpeed(potencia);
    motor_der2.setSpeed(potencia);
    motor_izq2.setSpeed(potencia);
    delay(2000);
//  }
  motor_der1.run(RELEASE);
  motor_izq1.run(RELEASE);
  motor_der2.run(RELEASE);
  motor_izq2.run(RELEASE);
}

void izquierda(int potencia) {
  uint8_t i;
  motor_izq1.run(BACKWARD);
  motor_izq2.run(BACKWARD);
  motor_der1.run(FORWARD);
  motor_der2.run(FORWARD);

  for (i = 1; i < 60; i++) {
    motor_izq1.setSpeed(potencia);
    motor_izq2.setSpeed(potencia);
    motor_der1.setSpeed(potencia);
    motor_der2.setSpeed(potencia);
    delay(10);
  }
  motor_der1.run(RELEASE);
  motor_der2.run(RELEASE);
  motor_izq1.run(RELEASE);
  motor_izq2.run(RELEASE);
}
