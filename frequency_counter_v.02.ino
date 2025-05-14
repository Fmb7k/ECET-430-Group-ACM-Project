// Frequency counter V.0.2

#include <LiquidCrystal.h>
#include <FreqCount.h>

// Input signal connected to Pin 5 of Arduino

unsigned long freq;   // frequency

LiquidCrystal lcd(2, 1, 4, 12, 6, 7);    // associate data pins to lcd's rs, enable, d4, d5, d6, d7

void setup()
{
    FreqCount.begin(1000);
}
void loop()
{
    if(FreqCount.available())
    {
      freq = FreqCount.read();

	  lcd.clear();            // delete previous values from display
      lcd.setCursor(0, 0);    // set cursor to the beginning of display
      lcd.print(freq);        // print frequency value on display
      lcd.print(" Hz");       // add measurement unit to the display output
    }

    delay(500);             // prevent display from flickering too much
}
