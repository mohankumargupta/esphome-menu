#include "oled.h"

namespace esphome {
namespace oled {

static const char *TAG = "oled.component";

void Oled::setup() {
    //U8G2_SSD1306_128X64_NONAME_1_SW_I2C u8g2moo (U8G2_R0, 9, 8, U8X8_PIN_NONE);
    U8G2_SSD1306_128X64_NONAME_1_SW_I2C u8g2oled (U8G2_R0, this->scl_pin, this->sda_pin, U8X8_PIN_NONE);
    //U8G2_SSD1306_128X64_NONAME_F_SW_I2C u8g2oled (U8G2_R0, this->scl_pin, this->sda_pin, U8X8_PIN_NONE);
    
    //this->u8g2device = &u8g2oled;
    //u8g2oled.clearBuffer();         
    //u8g2oled.setFont(u8g2_font_t0_11_tf); 
    //u8g2oled.drawStr(0, 12, "Hello World!"); 
    //u8g2oled.sendBuffer();          

    this->u8g2device = &u8g2oled;
    this->u8g2device->begin();
    u8g2oled.firstPage();
      do {
     
    u8g2oled.setFont(u8g2_font_unifont_t_72_73);
    int icon_width;

    switch (this->index)
    {
    case 1:
      icon_width = u8g2oled.getUTF8Width("①");
      u8g2oled.drawUTF8(64 - icon_width/2, 32, "①");
      break;
    case 2:
      icon_width = u8g2oled.getUTF8Width("②");
      u8g2oled.drawUTF8(64 - icon_width/2, 32, "②");      
      break;
    case 3:
      icon_width = u8g2oled.getUTF8Width("③");
      u8g2oled.drawUTF8(64 - icon_width/2, 32, "③");     
      break;
    case 4:
      icon_width = u8g2oled.getUTF8Width("④");
      u8g2oled.drawUTF8(64 - icon_width/2, 32, "④");     
      break;
    case 5:
      icon_width = u8g2oled.getUTF8Width("⑤");
      u8g2oled.drawUTF8(64 - icon_width/2, 32, "⑤");     
      break;
    case 6:
      icon_width = u8g2oled.getUTF8Width("⑥");
      u8g2oled.drawUTF8(64 - icon_width/2, 32, "⑥");     
      break;
    case 7:
      icon_width = u8g2oled.getUTF8Width("⑦");
      u8g2oled.drawUTF8(64 - icon_width/2, 32, "⑦");     
      break;
    case 8:
      icon_width = u8g2oled.getUTF8Width("⑧");
      u8g2oled.drawUTF8(64 - icon_width/2, 32, "⑧");     
      break;
    case 9:
      icon_width = u8g2oled.getUTF8Width("⑨");
      u8g2oled.drawUTF8(64 - icon_width/2, 32, "⑨");     
      break;
    }
    //u8g2oled.drawUTF8(100, 12, "∞");
    //u8g2oled.setFont(u8g2_font_t0_11_tf);
    //u8g2oled.drawStr(0,12,"Hello World!");
    
    //u8g2oled.setFont(u8g2_font_t0_11b_tf);
    //u8g2oled.drawStr(0,24,"Hello World!");
    
    //u8g2oled.setFont(u8g2_font_NokiaSmallPlain_tf);
    //u8g2oled.drawStr(0,37,"Hello World!");
    
    //u8g2oled.setFont(u8g2_font_NokiaSmallBold_tf);
    //u8g2oled.drawStr(0,50,"Hello World!");

    u8g2oled.setFont(u8g2_font_lucasfont_alternate_tf);
    int text_width = u8g2oled.getUTF8Width("Hello World!");
    u8g2oled.drawStr(64 - text_width/2,48,"Hello World!");

  } while ( u8g2oled.nextPage() );
  
}

void Oled::loop() {

}

void Oled::dump_config(){
    ESP_LOGI(TAG, "Setting up OLED Component");
}

void Oled::set_pins(uint8_t _sda_pin, uint8_t _scl_pin) {
    this->sda_pin = _sda_pin;
    this->scl_pin = _scl_pin;
}

void Oled::set_index(uint8_t index) {
    this->index = index;
}

// void Oled::printSomething() {

// }


}  // namespace oled
}  // namespace esphome

