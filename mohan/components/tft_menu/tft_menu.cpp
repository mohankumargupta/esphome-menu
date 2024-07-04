#include "tft_menu.h"

namespace esphome {
namespace tft_menu {

void TFTMenuComponent::setup() {}

void TFTMenuComponent::loop() {}

void TFTMenuComponent::dump_config() {}

void TFTMenuComponent::key_pressed(int key) {
  ESP_LOGI("tft_menu", "key pressed from component: %d", key);
  switch (this->menu_state_) {
    case MenuState::MAIN_MENU:
      this->menu_state_ = MenuState::SUBMENU;
      break;

    case MenuState::SUBMENU:
    this->menu_state_ = MenuState::MAIN_MENU;
      break;
  }
}

void TFTMenuComponent::set_top_menu(std::vector<std::string> &&top_menu) { this->top_menu_ = std::move(top_menu); }

void TFTMenuComponent::set_menu_options(std::vector<std::vector<std::string>> &&menu_options) {
  this->menu_options_ = std::move(menu_options);
}

}  // namespace tft_menu
}  // namespace esphome