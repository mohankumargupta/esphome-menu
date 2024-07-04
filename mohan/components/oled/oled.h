#pragma once

#include "esphome/core/component.h"
#include "esphome/core/log.h"

#include <U8g2lib.h>

namespace esphome {
namespace oled {

class Oled : public Component {
 public:
  void setup() override;
  void loop() override;
  void dump_config() override;
  
  //void printSomething();
  void set_pins(uint8_t sda_pin, uint8_t scl_pin);
  void set_index(uint8_t index);

  private:
    uint8_t sda_pin;
    uint8_t scl_pin;
    uint8_t index;
    U8G2_SSD1306_128X64_NONAME_1_SW_I2C* u8g2device = nullptr;
    //U8G2_SSD1306_128X64_NONAME_F_SW_I2C* u8g2device = nullptr;
};


}  // namespace empty_component
}  // namespace esphome