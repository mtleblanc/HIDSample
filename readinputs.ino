#define X 14
#define Y 15
#define Z 2
#define A 4
#define B 5
#define C 6
#define D 7

const int pins[] = { Z, A, B, C, D };
const char values[] = { 'Z', 'A', 'B', 'C', 'D' };
const int defaults[] = { HIGH, LOW, LOW, LOW, LOW };

void setup() {
  for (int i = 0; i < sizeof(pins); i++)
    pinMode(pins[i], INPUT);
  pinMode(X, INPUT);
  Serial.begin(9600);
}

// the loop function runs over and over again forever
void loop() {
  char floats[10];
  delay(1000);
  for (int i = 0; i < sizeof(values); i++)
    if (digitalRead(pins[i]) != defaults[i])
      Serial.print(values[i]);
  int value = analogRead(X);
  sprintf(floats, "%d", value);
  Serial.println(floats);
}
