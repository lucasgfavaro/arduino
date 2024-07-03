#include <SoftwareSerial.h>

SoftwareSerial BTSerial(3, 2); // RX | TX

void setup() {
  Serial.begin(9600);
  BTSerial.begin(38400);

  // Iniciar conexión con el esclavo (usar la dirección del esclavo obtenida anteriormente)
  BTSerial.print("AT+BIND=98D3:31:F707A1"); // Reemplaza con la dirección de tu esclavo
  delay(1000);
  BTSerial.print("AT+CMODE=0");
  delay(1000);
  BTSerial.print("AT+LINK=98D3:31:F707A1"); // Reemplaza con la dirección de tu esclavo
}

void loop() {
  if (BTSerial.available()) {
    Serial.write(BTSerial.read());
  }
  if (Serial.available()) {
    BTSerial.write(Serial.read());
  }
}