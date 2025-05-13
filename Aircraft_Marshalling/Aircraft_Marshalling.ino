#include <NewPing.h>
#include <LiquidCrystal.h>  

// LCD pins
const int rs = 7, en = 8, d4 = 9, d5 = 10, d6 = 11, d7 = 12;

// Ultrasound sensor configuration
#define TRIGGER_PIN  2  
#define ECHO_PIN     3  
#define MAX_DISTANCE 200 

#define FLASH_DISTANCE 20 // When the distance is less than this value the lights start flashing
#define STOP_DISTANCE  5 // When the distance is less than this value the lights stay ON and the LCD displays "STOP!"

#define LED_PIN 5
#define SECOND_LED_PIN 6

NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE); // Create a sonar (ultrasound sensor) object
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);  // Create an LCD object

// Functions flashes LED
void flash_LED(){
  bool state = digitalRead(LED_PIN);
  if (state == 0){
    digitalWrite(LED_PIN, 1);
    digitalWrite(SECOND_LED_PIN, 1);

  } else if (state == 1){
    digitalWrite(LED_PIN, 0);
    digitalWrite(SECOND_LED_PIN, 0);
  }

}

void aircraft_marshalling(int dist){
  if (dist == 0){
    // do nothing
  } else if (dist < STOP_DISTANCE){
    // LED is ON and the LCD displays prints 'STOP!'
    digitalWrite(LED_PIN, 1);
    digitalWrite(SECOND_LED_PIN, 1);
    lcd.print("STOP!");

  } else if (dist < FLASH_DISTANCE){
    // LED is flashing and the LCD displays the distance
    flash_LED();
    lcd.print("Distance: ");
    lcd.print(dist);
  
  } else {
    // LED is off and the LCD displays the distance
    digitalWrite(LED_PIN, 0);
    digitalWrite(SECOND_LED_PIN, 0);
    lcd.print("Distance: ");
    lcd.print(dist);
  }
}

void setup() {
  // set pin modes and initialize the serial monitor
  pinMode(LED_PIN, OUTPUT);
  pinMode(SECOND_LED_PIN, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  lcd.clear(); // clear the screen
  int distance = sonar.ping_cm(); // get the distance
  Serial.println(distance);

  aircraft_marshalling(distance);

  delay(500); // to make sure the lights flash at a constant rate
}
