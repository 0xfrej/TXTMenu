/*
 * config.hpp
 *
 * Created: 11/22/2018
 *  Author: Peter Karaba
 */


#ifndef __CONFIG_HPP__
#define __CONFIG_HPP__

#define OUTPUT_DRIVER	"src/drivers/HD44780/output_wrapper.hpp"
#define INPUT_DRIVER	"src/drivers/KBMatrix/input_wrapper.hpp"
#define DELAY_DRIVER	"src/drivers/delay/avr/delay_wrapper.hpp"


// Max navigation depth 256
// Max number of items in menu 255
// Max Languages 255
// If you enter more items than is max number, then it will just ignore the ones over limit

#define SITEMCHAR '>' // Selected item mark

// Max depth of menu tree with root menu included
// The higher this number is the higher will be RAM usage
// Library uses normal array for depth navigation because dynamic arrays will probably fragment your memory like hell
// and I used pointers to parent in every menu item once before...it was way worse...so don't change that, thank you very much.
#define MAXDEPTH 2

#define NAVDELAY 250 // Delay which will define maximum scroll speed

#define CHECK_LABEL_LEN 0 // when set to 1, the library will not try to print label bigger than 'OUTPUT_LINE_LENGHT' (when enabled it will add increase program space consumption quite a lot)
#define MULTI_LANG		1 // enable multilangual feature of library

// Set expected values for key flags on input
#define Key_UP 0x26
#define Key_DOWN 0x28
#define Key_LEFT 0x25
#define Key_RIGHT 0x27
#define Key_OK	'#'
#define Key_DEL	'*'

#include OUTPUT_DRIVER
#include INPUT_DRIVER
#include DELAY_DRIVER
#endif /* __CONFIG_HPP__ */
