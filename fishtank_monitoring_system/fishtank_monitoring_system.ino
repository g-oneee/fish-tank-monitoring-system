#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 2, 16);

int sensorPin = A0;

void setup()
{
    pinMode(2, OUTPUT);
    pinMode(3, OUTPUT);
    Serial.begin(9600);
    // initialize LCD
    lcd.init();
    // turn on LCD backlight
    lcd.backlight();
}
void loop()
{
    Serial.println(" ");
    Serial.println("**************");
    Serial.println(" ");
    int sensorValue = analogRead(sensorPin);
    Serial.println(sensorValue);
    int turbidity = map(sensorValue, 0, 750, 100, 0);
    delay(1000);
    lcd.setCursor(0, 0);
    lcd.print("Turbidity:");
    lcd.print("   ");
    lcd.setCursor(10, 0);
    lcd.print(turbidity);

    delay(100);
    if (turbidity < 20)
    {
        lcd.setCursor(0, 1);
        lcd.print("Water is CLEAR ");
        Serial.println("water is CLEAR ");
    }
    if ((turbidity > 20) && (turbidity < 50))
    {
        lcd.setCursor(0, 1);
        lcd.print("water is CLOUDY ");
        Serial.println("water is CLOUDY ");
    }
    if (turbidity > 50)
    {
        lcd.setCursor(0, 1);
        lcd.print("water is DIRTY ");
        Serial.println("water is DIRTY ");
    }

    int value = analogRead(A1);
    lcd.setCursor(0, 0);
    // lcd.print("Value :");
    // lcd.print(value);
    // lcd.print("   ");
    // Serial.println(value);
    // lcd.setCursor(0, 1);
    // lcd.print("W Level :");
    if (value == 0)
    {
        Serial.println("Empty ");
    }
    else if (value > 1 && value < 350)
    {
        Serial.println("Water Level is LOW   ");
        digitalWrite(2, HIGH);
        digitalWrite(3, LOW);
        delay(1000);
    }
    else if (value > 350)
    { // && value < 510
        Serial.println("Water Level is High");
        // } else if (value > 510){
        //   Serial.println("Water Level is HIGH ");
        digitalWrite(2, LOW);
        digitalWrite(3, HIGH);
        delay(1000);
    }
}
