/*
 * input_wrapper.cpp
 *
 * Created: 11/22/2018
 *  Author: Peter Karaba
 */

#include "input_wrapper.hpp"

extern "C"{
	#include "KBMatrix.h"
};

void input_init(){
	KBMInit();
}

char input_getc(){
	return KBMGet();
}