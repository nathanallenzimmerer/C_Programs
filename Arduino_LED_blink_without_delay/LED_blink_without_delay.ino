/*
 * Nathan Zimmerer
 * Program Name: LED Blink without Delay
 * Program Description:
 * Blink the LED using a finite state machine
 */
const int ledPin = LED_BUILTIN;// the number of the LED pinconst long interval = 1000;
// interval at which to blink (milliseconds)

int ledState = LOW; // ledState used to set the LED
unsigned long previousMillis = 0; // will store last time LED was updated

// set the digital pin as output:
 pinMode(ledPin, OUTPUT); // Arduino pin 13
}

void loop() {

// check to see if it's time to blink the LED;
 unsigned long currentMillis = millis();

if (currentMillis - previousMillis >= interval) {
 // save the last time you blinked the LED
 previousMillis = currentMillis;

// if the LED is off turn it on and vice-versa:
 if (ledState == LOW) {
 ledState = HIGH;
 } else {
 ledState = LOW;
 }

// set the LED with the ledState of the variable:
 digitalWrite(ledPin, ledState);
 }
}
