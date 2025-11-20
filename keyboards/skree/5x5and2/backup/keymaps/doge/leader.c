// Including external files
#include "sharedDefines.h"

bool leader_key_is_running = false;

uint16_t scroll_delay_timer;

LEADER_EXTERNS();

void matrix_scan_user(void) {
  LEADER_DICTIONARY() {
    leading = false;

  leader_end();
}

  uint16_t current_timer_value = timer_read();

  if(scrollwheel_up_on || scrollwheel_down_on){
    if(timer_elapsed(scroll_delay_timer) > 50){ //call this every 100ms(Default)
        register_code16(scrollwheel_up_on ? KC_MS_WH_UP : KC_MS_WH_DOWN);
        unregister_code16(scrollwheel_up_on ? KC_MS_WH_UP : KC_MS_WH_DOWN);
        scroll_delay_timer = current_timer_value;
    }
  }

}

void leader_start(void) {
    leader_key_is_running = true;
}

void leader_end(void) {
    leader_key_is_running = false;
}
