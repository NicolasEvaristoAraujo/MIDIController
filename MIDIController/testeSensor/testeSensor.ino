int LIGHTSENSOR = 0; //the # of the analog pin which the light sensor is connected to
int AMBIENT_OFFSET = 0;

void setup() {

    Serial.begin(9600);
        for (int i = 0; i < 30; i++) {
    AMBIENT_OFFSET += analogRead(LIGHTSENSOR);
    Serial.print("LightAverage = ");
    Serial.println(AMBIENT_OFFSET);
        Serial.print("i = ");
        Serial.println(i);


  }

  AMBIENT_OFFSET = AMBIENT_OFFSET / 30;
      Serial.println("");
      Serial.println(AMBIENT_OFFSET);

      delay(2000);
}

void loop() {
  
    Serial.print("**LightAverage** = ");
    Serial.println(AMBIENT_OFFSET);
    Serial.println("  ");
    Serial.print("LightSensor = ");
  Serial.println(analogRead(LIGHTSENSOR));
  delay(500);
}
