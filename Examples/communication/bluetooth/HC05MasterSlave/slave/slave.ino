#include <SoftwareSerial.h>


int const HC05_TX_PIN = 2;
 int const HC05_RX_PIN = 3;
 int const NANO_BAUD = 4800; // Set Sketch Seria Monitor to this rate to watch println
 int const HC05_BAUD = 9600; // Sometime it is different

SoftwareSerial HC05_Serial(HC05_TX_PIN, HC05_RX_PIN); // RX | TX // Van invertidos al HC05

void setup() {
  // Inicializar comunicación serial para depuración
  Serial.begin(NANO_BAUD);
  // Inicializar comunicación serial para el HC-05
  HC05_Serial.begin(HC05_BAUD); // La velocidad de comunicación en modo AT es 38400
  // Esperar un poco para asegurarse de que todo esté listo
  delay(1000);
  Serial.println("Enter AT commands:"); 
  // Enviar comando AT para obtener la dirección MAC
  HC05_Serial.println("AT+ADDR?");
}

void loop() {


  if (HC05_Serial.available()) {
      char c = HC05_Serial.read();
      Serial.print(c);
  }
  
}