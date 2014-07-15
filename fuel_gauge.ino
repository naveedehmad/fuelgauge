/*
Fuel Gauge

@author Naveed Ahmad
@version 0.0.1
*/

#define FLOAT_SWITCH A0

int g0 = 2;
int g1 = 3;
int g2 = 4;
int g3 = 5;
int rd = 6;

int fuelStatus = 0;

int tankFull = 75;
int tankEmpty = 400;

int range0 = 140;
int range1 = 206;
int range2 = 272;
int range3 = 338;

boolean off = false;

void setup() {
  pinMode(g0, OUTPUT);
  pinMode(g1, OUTPUT);
  pinMode(g2, OUTPUT);
  pinMode(g3, OUTPUT);
  pinMode(rd, OUTPUT);

  Serial.begin(9600);
  
  while(!Serial);
  Serial.println("Gauge initialized");
}

void loop() {
  fuelStatus = analogRead(FLOAT_SWITCH);
  
  Serial.print("*********** ");
  Serial.print(fuelStatus);
  Serial.println(" ***********");
  
  digitalWrite(rd, LOW);

  if(fuelStatus <= tankFull) {
    digitalWrite(g0, HIGH);
    digitalWrite(g1, HIGH);
    digitalWrite(g2, HIGH);
    digitalWrite(g3, HIGH);
    
    Serial.println("Tank full");
  } else if(fuelStatus >= tankEmpty) {
    digitalWrite(g0, LOW);
    digitalWrite(g1, LOW);
    digitalWrite(g2, LOW);
    digitalWrite(g3, LOW);
    
    if(off) {
      digitalWrite(rd, HIGH);
    } else {
      digitalWrite(rd, LOW);
    }
    off = !off;
    
    Serial.println("Tank empty!!");
  } else {
    if(fuelStatus > tankFull && fuelStatus <= range0) {
      digitalWrite(g0, HIGH);
      digitalWrite(g1, HIGH);
      digitalWrite(g2, HIGH);
      digitalWrite(g3, LOW);

      Serial.println("4 Dots!");
    } else if(fuelStatus > range0 && fuelStatus <= range1) {
      digitalWrite(g0, HIGH);
      digitalWrite(g1, HIGH);
      digitalWrite(g2, HIGH);
      digitalWrite(g3, LOW);

      Serial.println("3 Dots!");
    } else if(fuelStatus > range1 && fuelStatus <= range2) {
      digitalWrite(g0, HIGH);
      digitalWrite(g1, HIGH);
      digitalWrite(g2, LOW);
      digitalWrite(g3, LOW);

      Serial.println("2 Dots!");
    } else if(fuelStatus > range2 && fuelStatus < tankEmpty) {
      digitalWrite(g0, HIGH);
      digitalWrite(g1, LOW);
      digitalWrite(g2, LOW);
      digitalWrite(g3, LOW);

      Serial.println("1 Dot!");
    }
  }
  
  delay(500);
}
