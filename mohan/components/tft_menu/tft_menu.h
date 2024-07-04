#pragma once

#include "esphome/core/component.h"
#include "esphome/core/log.h"

namespace esphome {
namespace tft_menu {

static const char *const TAG = "tft_menu";

class TFTMenuComponent : public Component {
 public:
  void setup() override;
  void loop() override;
  void dump_config() override;
  void key_pressed(int key);

 private:
  uint8_t index;
  int key;
};



}  // namespace tft_menu
}  // namespace esphome


