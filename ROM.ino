int led = 6;
int sensor = 2;
int sensor2 = 4;
int room = 0;

boolean lastRoom = false;
boolean s1 = true;
boolean s2 = true;

void setup() {
  pinMode(sensor, INPUT);
  pinMode(sensor2, INPUT);

  digitalWrite (sensor, HIGH);
  digitalWrite (sensor2, HIGH);
  Serial.begin(9600);
  pinMode(led, OUTPUT);

}

void loop() {
  Serial.println(room);
  if (digitalRead(sensor) == LOW && lastRoom == false && s1 == true)
  {

    room += 1;
    s2 = false;
    lastRoom = true;
    delay(2000);
    s2 = true;

  }
  else
  {
    lastRoom = !digitalRead(sensor);

  }
  if (digitalRead(sensor2) == LOW && lastRoom == false && s2 == true) {
    room -= 1;
    s1 = false;
    lastRoom = true;
    delay(2000);
    s1 = true;
  }
  else
  {
    lastRoom = !digitalRead(sensor2);

  }
  if (room >= 1) {
    digitalWrite(led, HIGH);
  }
  else if (room == 0)
  {
    digitalWrite(led, LOW);
  }
  else if (room < 0)
  {
    room = 0;
  }
}
