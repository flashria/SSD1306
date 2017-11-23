#if ARDUINO >= 100
 #include "Arduino.h"
#else
 #include "WProgram.h"
#endif

#define swap(a, b) { uint8_t t = a; a = b; b = t; }


////////////////////CMD///////////////////

#define Set_Display                 0xAF//显示开
#define Clr_Display                 0xAE//显示关

#define Set_Invert                 0xA7//反色开
#define Clr_Invert                 0xA6//反色关

#define RESET           0xE2//复位

#define Set_SEG_Direction     0xA0//列正向
#define Clr_SEG_Direction     0xA1//列反向

#define Set_COM_Direction     0xc0//行正向
#define Clr_COM_Direction     0xc8//行反向


#define Set_All_Pixel       0xA5//所有像素显示
#define Clr_All_Pixel 0xA4 //正常显示模式

class SSD1306 {
 public:
 
  SSD1306(int8_t SID, int8_t SCLK, int8_t DC, int8_t RST, int8_t CS) :sid(SID), sclk(SCLK), dc(DC), rst(RST), cs(CS) {}
  SSD1306(int8_t SID, int8_t SCLK, int8_t DC, int8_t RST) :sid(SID), sclk(SCLK), dc(DC), rst(RST), cs(-1) {}
  
  void SSD1306_init();
  void SSD1306_command(uint8_t c);
  void SSD1306_data(uint8_t c);
  void clear_display(void);
  void clear();
  void invert(uint8_t i);
  void display();
  void hide();
  void drawstring(uint8_t x, uint8_t line, char *c);
  void WR_ADD(uint8_t ye,uint8_t wei);
  void  drawchar(uint8_t c);
 private:
  int8_t sid, sclk, dc, rst, cs;
  void spiwrite(uint8_t c);
};
