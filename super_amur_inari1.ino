#include<Wire.h>
#include<LiquidCrystal_I2C.h>
//pins for potentiometer and led
const int potPin = A0;
const int greenledPin = 10;
const int yellowledPin = 11;
const int redledPin = 12;

//LCD object with I2C address 0x27 16 x 2
LiquidCrystal_I2C lcd(0x20, 16, 2);

//thresholds for temp in celcius
const int warnTempThresh = 50;//warning temp
const int dangerTempThresh = 80;//danger temp

void setup()
{
  //sets up LCD
  lcd.begin(16, 2); //initializes the LCD
  lcd.backlight(); // turns on the backlight for the LCD

  
  //displays a welcome message 
  lcd.setCursor(0, 0);
  lcd.print("Temperature monitor ");
  
  delay(2000); //2 second pause
  lcd.clear(); //clears the screen 
  
  //initial serial communication
  Serial.begin(9600);
  
  //set up led pin as output 
  pinMode(greenledPin, OUTPUT);
  pinMode(yellowledPin, OUTPUT);
  pinMode(redledPin, OUTPUT);
}

void loop()
{
  //read potentiometer value (0 to 1023)
  int potValue = analogRead(potPin);
  
  //map potentiometer value to temperature range (0 to 100) degrees celsius
  int temp = random(0, 101);
  //int temp = map(potValue, 0, 1023, 0, 100);
  
  Serial.print("Temperature: ");
  Serial.print(temp);
  Serial.print(" degrees celcius\n");
  
  //turn on led if temperature exceeds threshold
  if(temp < warnTempThresh){
    //green light for safe
    digitalWrite(greenledPin, HIGH);
    digitalWrite(yellowledPin, LOW);
    digitalWrite(redledPin, LOW);
    Serial.print("Safe\n");
    lcd.setCursor(0, 0);
    lcd.print("Temp: ");
    lcd.print(temp);
    lcd.print("C ");
  }
  else if(temp < dangerTempThresh) {
    //yellow light for warning 
    digitalWrite(greenledPin, LOW);
    digitalWrite(yellowledPin, HIGH);
    digitalWrite(redledPin, LOW);
    Serial.print("Warning\n");
    lcd.setCursor(0, 0);
    lcd.print("Temp: ");
    lcd.print(temp);
    lcd.print("C ");
  }
  else {
    //red light for danger
    digitalWrite(greenledPin, LOW);
    digitalWrite(yellowledPin, LOW);
    digitalWrite(redledPin, HIGH);
    Serial.print("Danger\n");
    lcd.setCursor(0, 0);
    lcd.print("Temp: ");
    lcd.print(temp);
    lcd.print("C ");
  }
  
  lcd.setCursor(0, 0);
  lcd.print("Temp: ");
  lcd.print(temp);
  lcd.print("C ");
  
  //small delay for readbility
  delay(2000); // Wait for 1000 millisecond(s)
}