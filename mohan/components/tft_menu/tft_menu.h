#pragma once

#include "esphome/core/component.h"
#include "esphome/core/log.h"
#include <vector>

namespace esphome {
namespace tft_menu {

static const char *const TAG = "tft_menu";

enum class MenuState {
  MAIN_MENU,
  SUBMENU
};

class TFTMenuComponent : public Component {
 public:
  void setup() override;
  void loop() override;
  void dump_config() override;
  void key_pressed(int key);
  void set_top_menu(std::vector<std::string> && top_menu);
  void set_menu_options(std::vector<std::vector<std::string>> && menu_options);
  const std::vector<std::string>& get_menu() const {
    if (this->menu_state_ == MenuState::MAIN_MENU) {
      return top_menu_;
    }

    //else if (this->menu_state_ == MenuState::SUBMENU) {
    return menu_options_[0];
    //}
  } 

 private:
  MenuState menu_state_ = MenuState::MAIN_MENU;
  uint8_t index;
  int key;
  std::vector<std::string> top_menu_;
  std::vector<std::vector<std::string>> menu_options_;
};




}  // namespace tft_menu
}  // namespace esphome


