

// these constants describe the pins. They won't change:
const int groundpin = 18;             // analog input pin 4 -- ground
const int powerpin = 19;              // analog input pin 5 -- voltage
const int xpin = A3;                  // x-axis of the accelerometer
const int ypin = A2;                  // y-axis
const int zpin = A1;                  // z-axis (only on 3-axis models)

int xvalue;
int yvalue;
int zvalue;

void setup() {
  // initialize the serial communications:
  Serial.begin(9600);

  // Provide ground and power by using the analog inputs as normal digital pins.
  // This makes it possible to directly connect the breakout board to the
  // Arduino. If you use the normal 5V and GND pins on the Arduino,
  // you can remove these lines.
  //pinMode(groundpin, OUTPUT);
  //pinMode(powerpin, OUTPUT);
  //digitalWrite(groundpin, LOW);
  //digitalWrite(powerpin, HIGH);
}

void loop() {
  
  xvalue = analogRead(xpin);
  int x = map(xvalue, 262, 393, -100, 100);
  float xg = (float)x/(-100.00);
  Serial.print(xg);
  //Serial.print("g    ");
  
  yvalue = analogRead(ypin);
  int y = map(yvalue, 262, 393, -100, 100);
  float yg = (float)y/(-100.00);
  Serial.print("\t");
  Serial.print(yg);
  //Serial.print("g    ");
  
  zvalue = analogRead(zpin);
  int z = map(zvalue, 270, 401, -100, 100);
  float zg = (float)z/(-100.00);
  Serial.print("\t");
  Serial.println(zg);
  //Serial.println("g    ");
  
  delay(100);
}
