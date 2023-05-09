// Pins connected to the relays
int relay1 = 16;
int relay2 = 5;
int relay3 = 4;
int relay4 = 0;
const int potPin = A0; // Define the analog input pin for the potentiometer
int potValue = 0; // Variable to store the potentiometer value

void setup() 
{
    // Set the relay pins as output
    pinMode(relay1, OUTPUT);
    pinMode(relay2, OUTPUT);
    pinMode(relay3, OUTPUT);
    pinMode(relay4, OUTPUT);

    // LEDs off
    digitalWrite(relay1, HIGH); 
    digitalWrite(relay2, HIGH); 
    digitalWrite(relay3, HIGH); 
    digitalWrite(relay4, HIGH);

    //Initialize serial monitor with 9600 baud
    Serial.begin(9600);
    pinMode(potPin, INPUT); // Set the potentiometer pin as an input
    delay(2000);
}

void corner_20_deg()
{
  digitalWrite(relay2, LOW);
  digitalWrite(relay3, HIGH);
  digitalWrite(relay4, HIGH);
}

void corner_40_deg()
{
  digitalWrite(relay2, LOW);
  digitalWrite(relay3, LOW);
  digitalWrite(relay4, HIGH);
}

void corner_60_deg()
{
  digitalWrite(relay2, LOW);
  digitalWrite(relay3, LOW);
  digitalWrite(relay4, LOW);
}


void loop() 
{
  potValue = analogRead(potPin); // Read the value from the potentiometer
  Serial.print("Potentiometer value: "); // Print the value to the serial monitor
  Serial.println(potValue);

  digitalWrite(relay1, LOW);

  if ( (potValue <= 199) || (potValue >= 825) ) {
    Serial.println("aqui 60");
    corner_60_deg();
  }

  if ( (potValue <= 313 && potValue > 199) || (potValue >= 711 && potValue < 825) ) {
    Serial.println("aqui 40");
    corner_40_deg();
  }

  if ( (potValue <= 426 && potValue > 313) || (potValue >= 597 && potValue < 711)) {
    Serial.println("aqui 20");
    corner_20_deg();
  }
  

  delay(500);

  digitalWrite(relay1, HIGH);

  if ( (potValue <= 199) || (potValue >= 825) ) {
    corner_60_deg();
  }
  else if ( (potValue <= 313 && potValue > 199) || (potValue >= 711 && potValue < 825) ) {
    corner_40_deg();
  }
  else if ( (potValue <= 426 && potValue > 313) || (potValue >= 597 && potValue < 711)) {
    corner_20_deg();
  } else {
    digitalWrite(relay2, HIGH);
    digitalWrite(relay3, HIGH);
    digitalWrite(relay4, HIGH);
  }
  

  delay(500);
}

