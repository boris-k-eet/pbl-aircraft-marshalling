#include <NewPing.h>
#include <LiquidCrystal.h>  

const int rs = 7, en = 8, d4 = 9, d5 = 10, d6 = 11, d7 = 12;

#define TRIGGER_PIN  2  
#define ECHO_PIN     3  
#define MAX_DISTANCE 200 

#define FLASH_DISTANCE 20
#define STOP_DISTANCE  5

#define LED_PIN 5

NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE); 
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);  // Create an LCD object

void flash_LED(){
  state = digitalRead(LED_PIN);
  if (state == 0){
    digitalWrite(LED_PIN, 1);
  } else if (state == 1){
    digitalWrite(LED_PIN, 0);
  }

}

void setup() {
  // put your setup code here, to run once:
  pinMode(LED_PIN, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  lcd.clear();
  int distance = sonar.ping_cm();

  if (distance < STOP_DISTANCE){
    // LED is ON and the LCD displays prints 'STOP!'
    digitalWrite(LED_PIN, 0);
    lcd.print("STOP!")

  } else if (distance < FLASHING_DISTANCE){
    // LED is flashing and the LCD displays the distance
    flash_LED();
    lcd.print("Distance: ");
    lcd.print(distance);
  
  } else {
    // LED is off and the LCD displays the distance
    digitalWrite(LED_PIN, 0);
    lcd.print("Distance: ");
    lcd.print(distance);
  }

}
