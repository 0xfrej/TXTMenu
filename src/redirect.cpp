/*
 * redirect.cpp
 *
 * Created: 8. 1. 2017
 *  Author: Peter Karaba
 * Description:
 *		Creating IO streams for stdio to output devices through wrapped drivers
 */

#include "redirect.hpp"

FILE* ios;


// Input stream redirect function
int insf(FILE* _stream){
	return input_getc();
}

// Output stream redirect function
int outsf(const char c, FILE* _stream){
	output_putc(c);
	return 0;
}

// Initialization of io stream redirect
void iosinit(){
	// initialize drivers
	input_init();
	output_init();
	ios = fdevopen(outsf,insf);
}
