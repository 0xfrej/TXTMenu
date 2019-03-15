/*
 * redirect.hpp
 *
 * Created: 8. 1. 2017
 *  Author: Peter Karaba
 * Description:
 *		Creating IO streams for stdio to output devices through wrapped drivers
 */


#ifndef __REDIRECT_HPP__
#define __REDIRECT_HPP__

#include <stdio.h>
#include "../config.hpp"

extern FILE* ios;

int insf(FILE* _stream);
int outsf(const char& c, FILE* _stream);
void iosinit();

#endif /* __REDIRECT_HPP__ */