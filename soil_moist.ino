
int moisture = 0;

void setup()
{
  pinMode(A0, OUTPUT);
  pinMode(A1, INPUT);
  Serial.begin(9600);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(3,OUTPUT);
}

void loop()
{
  // Apply power to the soil moisture sensor
  digitalWrite(A0, HIGH);
  delay(10); // Wait for 10 millisecond(s)
  moisture = analogRead(A1);
  // Turn off the sensor to reduce metal corrosion
  // over time
  digitalWrite(A0, LOW);
  Serial.println(moisture);
  digitalWrite(8, LOW);
  digitalWrite(9, LOW);
  digitalWrite(10, LOW);
  digitalWrite(11, LOW);
  digitalWrite(12, LOW);
  if (moisture < 200) {
    digitalWrite(12, HIGH);
    digitalWrite(3,HIGH);
  } else {
    if (moisture < 400) {
      digitalWrite(11, HIGH);
      digitalWrite(3,HIGH);
    } else {
      if (moisture < 600) {
        digitalWrite(10, HIGH);
        digitalWrite(3,HIGH);
      } else {
        if (moisture < 800) {
          digitalWrite(9, HIGH);
          digitalWrite(3,LOW);
        } else {
          digitalWrite(8, HIGH);
          digitalWrite(3,LOW);
        }
      }
    }
  }
  delay(100); // Wait for 100 millisecond(s)
}