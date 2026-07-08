int segmentPins[] = { 2, 3, 4, 5, 6, 7, 9 };  // a, b, c, d, e, f, g

// The segment patterns required for the digits  from 0–9
byte digitPattern[10][7] = {
  { 1, 1, 1, 1, 1, 1, 0 },  // 0
  { 0, 1, 1, 0, 0, 0, 0 },  // 1
  { 1, 1, 0, 1, 1, 0, 1 },  // 2
  { 1, 1, 1, 1, 0, 0, 1 },  // 3
  { 0, 1, 1, 0, 0, 1, 1 },  // 4
  { 1, 0, 1, 1, 0, 1, 1 },  // 5
  { 1, 0, 1, 1, 1, 1, 1 },  // 6
  { 1, 1, 1, 0, 0, 0, 0 },  // 7
  { 1, 1, 1, 1, 1, 1, 1 },  // 8
  { 1, 1, 1, 1, 0, 1, 1 }   // 9
};

int buzzerPin = 8;
int numOfSegments = 7;

// The display digits function
void showDigits(int d) {
  if (d < 0 || d > 9)
    return;

  for (int n = 0; n < numOfSegments; n++) {
    digitalWrite(segmentPins[n], digitPattern[d][n]);
  }
}

void setup() {
  Serial.begin(9600);

  pinMode(buzzerPin, OUTPUT);

  for (int n = 0; n < numOfSegments; n++) {
    pinMode(segmentPins[n], OUTPUT);
  }

  Serial.println();
  Serial.println("=== Countdown Begins ===");

  int totalCount = 9;

  while (totalCount >= 1) {
    Serial.print("Counting: ");
    Serial.println(totalCount);

    showDigits(totalCount);
    tone(buzzerPin, 1000, 200);

    delay(1000);
    totalCount = totalCount - 1 ;
  }

  showDigits(0);
  tone(buzzerPin, 1500, 1000);

  Serial.println("=== Countdown Complete ===");
}

void loop() {
  //empty
  //RichieSika
}
