//Including external files
#include "sharedDefines.h"

// Defining scrolling
bool scrollwheel_down_on = false;
bool scrollwheel_up_on = false;
// Defining Combos -- Update combo count after in config.h
enum combo_events {
    COMBO_SCROLL_UP,
    COMBO_SCROLL_DOWN
};

const uint16_t PROGMEM combo_scroll_up[] = {KC_PGUP, COMBO_END};
const uint16_t PROGMEM combo_scroll_down[] = {KC_PGDN, COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
    [COMBO_SCROLL_UP] = COMBO_ACTION(combo_scroll_up),
    [COMBO_SCROLL_DOWN] = COMBO_ACTION(combo_scroll_down)
};

void process_combo_event(uint16_t combo_index, bool pressed) {

    switch(combo_index) {
      case COMBO_SCROLL_UP:
          if (pressed) {
              scrollwheel_up_on = true;
          }else{
              scrollwheel_up_on = false;
          }
    break;
      case COMBO_SCROLL_DOWN:
          if (pressed) {
              scrollwheel_down_on = true;
          }else{
              scrollwheel_down_on = false;
   }
 }
}
