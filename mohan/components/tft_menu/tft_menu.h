#pragma once

#include "esphome/core/component.h"
#include "esphome/core/log.h"
#include <vector>

namespace esphome {
namespace tft_menu {

static const char *const TAG = "tft_menu";

class TFTMenuComponent : public Component {
 public:
  void setup() override;
  void loop() override;
  void dump_config() override;
  void key_pressed(int key);
  void set_top_menu(std::vector<std::string> && top_menu);
  void set_menu_options(std::vector<std::vector<std::string>> && menu_options);

 private:
  uint8_t index;
  int key;
  std::vector<std::string> top_menu_;
  std::vector<std::vector<std::string>> menu_options_;
};



}  // namespace tft_menu
}  // namespace esphome


