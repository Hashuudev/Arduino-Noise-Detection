#define sensorPin A0
#define LED 2
// Variable to store the time when last event happened
unsigned long lastEvent = 0;

void setup() {
	pinMode(sensorPin, INPUT);	// Set sensor pin as an INPUT
	pinMode(LED, OUTPUT);
  Serial.begin(9600);

}

void loop() {
	// Read Sound sensor
	int sensorData = analogRead(sensorPin);
  Serial.println("Sound:");
  Serial.println(sensorData);
  delay(1000);
	// If pin goes LOW, sound is detected
	if (sensorData>18) {
		
	
		Serial.println("Noise detected!");
    digitalWrite(LED, HIGH);
    delay(2000);
    }
		
  else
    {
       digitalWrite(LED, LOW);
    }
		
		//Remember when last event happened
		
	
}