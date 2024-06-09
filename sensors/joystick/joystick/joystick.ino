/* 
  This program takes values from joytick and outputs the following commands

  [directionOverAxis]"-"[intensity 0-255]

  directionOverAxis X
    *R = Right
    *L = Left

  directionOverAxis Y
    *U = Up
    *D = Down

*/

const int pinX = A0;
const int pinY = A1;

void setup() {
  // Analogic input does not require initialization
  // Initialize serial comunication on 9600 baudios
  Serial.begin(9600);
}

void loop() {

  Serial.print("X:");
  Serial.print(getX());
  Serial.print(" - Y:");
  Serial.println(getY());

  delay(100);
}

String getX() {
  int x = analogRead(pinX);
  if (x >= 480 && x <= 520)
    return "C-0";
  else if (x < 480)
    return "L-" + String(map(x, 0, 480, 255, 0));
  else
    return "R-" + String(map(x, 520, 1023, 0, 255));
}

String getY() {
  int y = analogRead(pinY);
  if (y >= 480 && y <= 520)
    return "C-0";
  else if (y < 480)
    return "D-" + String(map(y, 0, 480, 255, 0));
  else
    return "U-" + String(map(y, 520, 1023, 0, 255));
}
