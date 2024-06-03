// Including external files
#include "sharedDefines.h"

// starting scroll delay on keyboard post
void keyboard_post_init_user(void) {
    scroll_delay_timer = timer_read();
}
