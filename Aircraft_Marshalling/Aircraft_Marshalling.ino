#include <NewPing.h>
#include <LiquidCrystal.h>  

const int buttonPin = 3;
const int rs = 7, en = 8, d4 = 9, d5 = 10, d6 = 11, d7 = 12;

#define TRIGGER_PIN  12  
#define ECHO_PIN     11  
#define MAX_DISTANCE 200 

#define FLASH_DISTANCE 20
#define STOP_DISTANCE  5

#define LED_PIN 5

NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE); 
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);  // Create an LCD object

void flash_LED(){
  pinMode(LED_PIN)
}


void setup() {
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:
  int distance = sonar.ping()
  

}
