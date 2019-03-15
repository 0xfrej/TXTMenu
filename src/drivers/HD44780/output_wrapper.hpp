/*
 * output_wrapper.hpp
 *
 * Created: 11/22/2018
 *  Author: Peter Karaba
 */


#ifndef __OUTPUT_WRAPPER_HPP__
#define __OUTPUT_WRAPPER_HPP__

#include <stdint.h>

#define OUTPUT_LINE_LENGHT 16
#define OUTPUT_LINE_COUNT	2 // How many lines to render (i.e.: LCD line count)

void output_init();

void output_putc(const char& c);

void output_clear();

void output_gotoxy(const uint8_t& x, const uint8_t& y);

void output_enterEditMode();

void output_exitEditMode();
#endif /* __OUTPUT_WRAPPER_HPP__ */