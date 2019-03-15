/*
 * output_wrapper.hpp
 *
 * Created: 11/22/2018
 *  Author: Peter Karaba
 */

#include "output_wrapper.hpp"

extern "C"{
	#include "lcd.h"
};



void output_init(){
	lcd_init(LCD_DISP_ON);
}

void output_putc(const char& c){
	lcd_putc(c);
}

void output_clear(){
	lcd_clrscr();
}

void output_gotoxy(const uint8_t& x, const uint8_t& y){
	lcd_gotoxy(x,y);
}

void output_enterEditMode(){
	lcd_command(LCD_DISP_ON_CURSOR_BLINK);
	//lcd_gotoxy(0,0);
}

void output_exitEditMode(){
	lcd_command(LCD_DISP_ON);
}