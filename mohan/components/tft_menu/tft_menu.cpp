#include "tft_menu.h"

namespace esphome {
namespace tft_menu {



void TFTMenuComponent::setup() {

}

void TFTMenuComponent::loop() {

}

void TFTMenuComponent::dump_config() {

}

void TFTMenuComponent::key_pressed(int key) {
  ESP_LOGI("tft_menu", "key pressed from component: %d", key);
}

}
}