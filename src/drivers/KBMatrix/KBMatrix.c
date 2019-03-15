/*
 * KBMatrix.c
 *
 * Created: 26.9.2016
 *  Author: Peter Karaba
 * Description:
 *		Library for matrix keyboard
 * Target: any 8bit AVR
 */

#include <avr/io.h>
#include <stdint.h>
#include "KBMatrix.h"
#include <util/delay.h>

#define sbi(b,n) ((b) |= (1<<(n)))          /* Set bit number n in byte b */
#define cbi(b,n) ((b) &= (~(1<<(n))))       /* Clear bit number n in byte b   */
#define fbi(b,n) ((b) ^= (1<<(n)))          /* Flip bit number n in byte b    */
#define rbi(b,n) ((b) & (1<<(n)))           /* Read bit number n in byte b    */

/***************************************************************************/
// User Settings

const char key_matrix[4][4] = {	{'1', '2', '3', 0x26},
								{'4', '5', '6', 0x28},
								{'7', '8', '9', 0x25},
								{'*', '0', '#', 0x27},
};

#define y_row_count 4 //max 4
#define x_row_count 4 //max 4

#define KBMDDR DDRA
#define KBMPORT PORTA
#define KBMPIN PINA
#define YBIT0 0
#define XBIT0 4

/***************************************************************************/

void KBMInit(){
	/***************INITIALIZATION PINS FOR OUTPUT SIGNAL*******************/
	for(uint8_t y=0; y<y_row_count; y++) {
		//Set YBITs as input
		sbi(KBMDDR, YBIT0+y);
		//Enable pull-up resistors for YBITs
		sbi(KBMPORT, YBIT0+y);
	}
	for(uint8_t x=0; x<x_row_count; x++){
		//Enable pull-up resistors for XBITs
		sbi(KBMPORT, XBIT0+x);
	}
	/***********************************************************************/
}
char KBMGet(){
	uint8_t x = 0; uint8_t y = 0;
	while(1){
		for(;x<x_row_count;++x){
			for(;y<y_row_count;++y){
				cbi(KBMPORT, (YBIT0 + y));
				_delay_us(500);
				if(bit_is_clear(KBMPIN, (XBIT0 + x))){ //If some key is pressed then return it's character
					sbi(KBMPORT, (YBIT0 + y)); //Before return character set bit back to it's normal state
					return(key_matrix[y][x]);
				}
				sbi(KBMPORT, (YBIT0 + y));
			}
			y = 0;
		}
		x = 0;
	}
}