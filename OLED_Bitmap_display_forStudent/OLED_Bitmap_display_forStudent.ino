//include library
#include <Wire.h>
#include <SPI.h>
#include "SSD1306Wire.h" // legacy include: `#include "SSD1306.h"`
#include "animation.h"
#define Logo_width 64
#define Logo_height 64

//設定腳位
SSD1306Wire  display(0x3c, 22, 23);
const int button_pin=12;
int cur_st=0;
int pox=0;int walk_i=0;int idle_i=0;



void setup() {
  Serial.begin(115200);//設定包率
  pinMode(button_pin,INPUT);
  digitalWrite(button_pin,HIGH);
  display.init();//初始化(init)
  display.setContrast(255); //數值介於0~255，調整對比
  display.clear();//清除螢幕和緩衝區(clear)
}

void loop() { 
  cur_st= digitalRead(12);//讀取(digitalRead)腳位，判斷是否切換圖片 
  if(cur_st==HIGH){
    display.clear();//清除螢幕和緩衝區(clear)
    display.drawXbm(pox, 0, Logo_width,Logo_height,walk[walk_i]);
    display.display();//顯示畫面(display)
    delay(100);
    pox=pox+5;
      if(pox>=127)pox=-30;
        walk_i++;
      if(walk_i==8){walk_i=0;}
  }
    else{
      display.clear();
      display.drawXbm(pox, 0, Logo_width,Logo_height,idle[idle_i]);
      display.display();
      delay(200);
      idle_i++;
      if(idle_i==2)idle_i=0;
      }
}
     
    
