#include <LiquidCrystal.h>

LiquidCrystal lcd(A6, A5, 8, 9, 10, 11);
int water_level= 0;

long duration;
int distance;
float waterlevelpercent;

volatile bool button1Pressed = true;
volatile bool button2Pressed = true;
volatile bool button3Pressed = true;
volatile bool button4Pressed = true;

const int trig_pin = A2;
const int echo_pin = 3;
const int ws_data = A1;
const int sole_trig = A4;
const int button1 = 4;
const int button2 = 5;
const int button3 = 6;
const int button4 = 7;

volatile unsigned long lastTimeButtonPressed4debounce = millis();
volatile unsigned long lastTimeButtonPressed4waterflow = millis();
volatile unsigned long lastTimeButtonPressed4display = millis();
unsigned long debounceDelay = 50;

void solenoidturnon(unsigned long time) 
{
  digitalWrite(A4, HIGH);
  unsigned long timeNow1 = millis(); 
  if (timeNow1 - lastTimeButtonPressed4waterflow > time) {
  lastTimeButtonPressed4waterflow = timeNow1;
  digitalWrite(A4,LOW);
}
 }
void solenoidturnon4ever()
{
  digitalWrite(A4, HIGH);

}

void button1PressedInterrupt()
{
  unsigned long timeNow2 = millis();
  if (timeNow2 - lastTimeButtonPressed4debounce > debounceDelay) {
    lastTimeButtonPressed4debounce = timeNow2;
    if (button1Pressed){
      button1Pressed = false;
    }
    else {
      button1Pressed = true;
    }
    }
  }
  

void button2PressedInterrupt()
{
  unsigned long timeNow3 = millis();
  if (timeNow3 - lastTimeButtonPressed4debounce > debounceDelay) {
    lastTimeButtonPressed4debounce = timeNow3;
    if (button2Pressed){
      button2Pressed = false;
    }
    else {
      button2Pressed = true;
    }
    }
  }


void button3PressedInterrupt()
{
  unsigned long timeNow4 = millis();
  if (timeNow4 - lastTimeButtonPressed4debounce > debounceDelay) {
    lastTimeButtonPressed4debounce = timeNow4;
    if (button3Pressed){
      button3Pressed = false;
    }
    else {
      button3Pressed = true;
    }
    }
  }


void button4PressedInterrupt()
{
  unsigned long timeNow5 = millis();
  if (timeNow5 - lastTimeButtonPressed4debounce > debounceDelay) {
    lastTimeButtonPressed4debounce = timeNow5;
    if (button4Pressed){
      button4Pressed = false;
    }
    else {
      button4Pressed = true;
    }
    }
  }


int calculateDistance(){ 
  
  digitalWrite(trig_pin, LOW); 
  delayMicroseconds(2);
  // Sets the trigPin on HIGH state for 10 micro seconds
  digitalWrite(trig_pin, HIGH); 
  delayMicroseconds(10);
  digitalWrite(trig_pin, LOW);
  duration = pulseIn(echo_pin, HIGH); // Reads the echoPin, returns the sound wave travel time in microseconds
  distance= duration*0.034/2;
  return distance; 
}

void setup() {
  pinMode(button1, INPUT);
  pinMode(button2, INPUT);
  pinMode(button3, INPUT);
  pinMode(button4, INPUT);
  pinMode(trig_pin, OUTPUT); 
  pinMode(echo_pin, INPUT);
  pinMode(sole_trig, OUTPUT);
  pinMode(ws_data, INPUT);
  lcd.begin(16, 2);

  attachInterrupt(digitalPinToInterrupt(button1),
                  button1PressedInterrupt,
                  RISING);

  attachInterrupt(digitalPinToInterrupt(button2),
                  button2PressedInterrupt,
                  RISING);
  
  attachInterrupt(digitalPinToInterrupt(button3),
                  button3PressedInterrupt,
                  RISING);

  attachInterrupt(digitalPinToInterrupt(button4),
                  button4PressedInterrupt,
                  RISING);

}

void loop() {
  
if (button1Pressed) {
  
  if (button2Pressed || button3Pressed ) 
  {
    button2Pressed = button3Pressed  = false;
  }
   
 solenoidturnon(5000);
 lcd.setCursor(0, 0);
 lcd.print("Water is Pouring in a");
 lcd.setCursor(0, 1);
 lcd.print("Glass");
 
}
if (button2Pressed) {
  
  if (button1Pressed || button3Pressed) 
  {
    button1Pressed = button3Pressed = false;
  }
   
 solenoidturnon(20000);
 lcd.setCursor(0, 0);
 lcd.print("Water is Pouring in a");
 lcd.setCursor(0, 1);
 lcd.print("Bottle");
 
}
if (button3Pressed) {
  
  if (button2Pressed || button1Pressed ) 
  {
    button2Pressed = button1Pressed  = false;
  }
   
 solenoidturnon4ever();
 lcd.setCursor(0, 0);
 lcd.print("Water is Pouring");
 
}
if (button4Pressed) {
  
 // if (button2Pressed || button3Pressed || button1Pressed) 
 // {
  //  button2Pressed = button3Pressed = button1Pressed = false;
 // }
   
 distance = calculateDistance();
 waterlevelpercent = distance*100/40; //suppose purifier is 40 cm long
 

  lcd.setCursor(0, 0);
  lcd.print("The Water Purifier is filled");
  lcd.setCursor(0, 1);
  lcd.print(waterlevelpercent);
 
  unsigned long timeNow6 = millis(); 
  
  if (timeNow6 - lastTimeButtonPressed4display > 10000) {
   lastTimeButtonPressed4display = timeNow6;
   lcd.setCursor(0, 0);
   lcd.print("");
   lcd.setCursor(0, 1);
   lcd.print("");
   button4Pressed = false;


 }




 
 //or

 //distance = analogRead(A1);
 //waterlevelpercentage = sensorvalue*100/40;
 //lcd.print("The Water Purifier is filled");
 //lcd.setCursor(0, 1);
 //lcd.print(waterlevelpercentage);


}

}
