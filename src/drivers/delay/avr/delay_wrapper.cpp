/*
 * delay_wrapper.cpp
 *
 * Created: 1/15/2019 12:00:44
 *  Author: brost
 */

#include "delay_wrapper.hpp"
#include <util/delay.h>

void delay_ms(unsigned short int ms){
	for(unsigned short int i=0;i<ms;i++){
		_delay_ms(1);
	}
}