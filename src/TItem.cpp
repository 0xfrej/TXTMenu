/*
 * TItem.cpp
 *
 * Created: 11/22/2018
 *  Author: Peter Karaba
 */


#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include "TItem.hpp"
#include "redirect.hpp"

namespace TItem {

	label::label(arrCreator<const char*>& __larrc){
		labelArrSize = __larrc.getOC();
		labelArr = __larrc.getArr();
	}
	void label::render(uint8_t* currentLanguage){
		if (labelArrSize != 0){

		#if CHECK_LABEL_LEN
			if (labelArrSize <= *currentLanguage)
				fprintf(ios, "%.*s", OUTPUT_LINE_LENGHT, labelArr[0]);
			else
				fprintf(ios, "%.*s", OUTPUT_LINE_LENGHT, labelArr[*currentLanguage]);
		#else
			if (labelArrSize <= *currentLanguage)
				fprintf(ios, "%s", labelArr[0]);
			else
				fprintf(ios, "%s", labelArr[*currentLanguage]);
		#endif

		}
	}
	TBase::item* label::add(){
		return this;
	}

	fItem::fItem(arrCreator<const char*>& __larrc, void (*__fptr)()) : label(__larrc){
		fptr = __fptr;
	}
	void fItem::callFunction(){
		(*fptr)();
	}

	submenu::submenu(arrCreator<const char*>& __larrc) : label(__larrc){

	}
	bool submenu::forward(){
		TBase::navForward(&subContainer);
		return true;
	}
	TBase::item* submenu::add(arrCreator<TBase::item*>& __iarrc){
		subContainer.arrSize = __iarrc.getOC();
		subContainer.array = __iarrc.getArr();
		return this;
	}

}
