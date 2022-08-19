#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,16,2);  // set the LCD address to 0x3F for a 20 chars and 4 line display

void setup()
{
  lcd.init();                      // initialize the lcd   
  lcd.backlight();
  ///
 pinMode(LED_BUILTIN, OUTPUT);     // Initialize the LED_BUILTIN pin as an output
  }

//////////funções
void ledstdby (void)
{
  digitalWrite(LED_BUILTIN, LOW);   // Turn the LED on (Note that LOW is the voltage level
  // but actually the LED is on; this is because
  // it is active low on the ESP-01)
  delay(1500);                      // Wait for a second
  digitalWrite(LED_BUILTIN, HIGH);  // Turn the LED off by making the voltage HIGH
  delay(3000);  
}

void loop()
{
  lcd.setCursor(0,0);
  lcd.print("    Welcome     ");  
  lcd.setCursor(0,1);
  lcd.print(" MIYAKODA TECH  ");
  ///
  ledstdby;


  ///
  
}
