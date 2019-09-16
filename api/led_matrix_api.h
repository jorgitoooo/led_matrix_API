#ifndef __LED_MATRIX_API__
#define __LED_MATRIX_API__

#include "defs.h"

// typedefs (uc, sc, us) found in 'defs.h'

void load_word();

void send_word(uc reg, uc data);

void clear_all(uc num_of_matrices);

void set_brightness(uc brightness, uc num_of_matrices);

void init_led_matrices(uc num_of_matrices);

#endif
