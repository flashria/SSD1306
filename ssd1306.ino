#include <SSD1306.h>
#define LCD_DC 9
#define LCD_CS 10
#define LCD_CLK 13
#define LCD_MOSI 11
#define LCD_RESET 8

SSD1306 lcd(LCD_MOSI,LCD_CLK,LCD_DC,LCD_RESET,LCD_CS);
String comdata = "";
void setup() {
  
  // put your setup code here, to run once:
  Serial.begin(9600);
lcd.SSD1306_init();
lcd.clear_display();
lcd.drawstring(0,0,"Raspberry Pi Server");
lcd.drawstring(1,0,"RUNTIME:131D 25H 13S");

lcd.drawstring(2,0,"CPU:        13.5");
lcd.drawstring(3,0,"RAM:        20%");
lcd.drawstring(4,0,"DISK:       20%");
lcd.drawstring(5,0,"TEMP:       31.1C");
lcd.drawstring(6,0,"IP:192.168.123.188");
lcd.drawstring(7,0,"IP:155.225.214.222");


}

void loop() {

  while (Serial.available() > 0)  
    {
        comdata += char(Serial.read());
        delay(2);
    }
    if (comdata.length() > 0)
    { 
       while(comdata.length()<21){
        comdata +=" ";
       }
       Serial.println(comdata);
        char b[comdata.length()];
        comdata.toCharArray(b,comdata.length()+1);
        lcd.drawstring(3,0,b);
        comdata = "";
    }
}
