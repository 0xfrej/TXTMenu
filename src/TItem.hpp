/*
 * TItem.hpp
 *
 * Created: 11/22/2018
 *  Author: Peter Karaba
 */


#ifndef __TITEM_HPP__
#define __TITEM_HPP__

#include "TBase.hpp"
#include "arrCreator.hpp"
#include "redirect.hpp"
#include <stdio.h>
#include <string.h>

namespace TItem {

	class label : public TBase::item{
	protected:
		const char** labelArr;
		uint8_t labelArrSize;

	public:
		label(arrCreator<const char*>& __larrc);
		virtual void render(uint8_t* currentLanguage);
		virtual TBase::item* add();
	};


	class fItem : public label{
	private:
		void (*fptr)();

	public:
		fItem(arrCreator<const char*>& __larrc, void (*__fptr)());
		void callFunction();
	};


	class submenu : public label{
	protected:
		TBase::container subContainer;
	public:
		submenu(arrCreator<const char*>& __larrc);
		bool forward();
		TBase::item* add(arrCreator<TBase::item*>& __iarrc);
	};


	template<typename T>
	class print : public label{
	protected:
		T* variable;
		const char* fmt;

	public:
		print(arrCreator<const char*>& __larrc, T* varPtr, const char* __fmt);
		void render(uint8_t* currentLanguage);
		virtual bool forward();
	};

	template<typename T>
	print<T>::print(arrCreator<const char*>& __larrc, T* varPtr, const char* __fmt) : label(__larrc){
		fmt = __fmt;
		variable = varPtr;
	}

	template<typename T>
	void print<T>::render(uint8_t* currentLanguage){
		this->label::render(currentLanguage);

		uint8_t labelLen = 0;
		if (labelArrSize != 0){
			if (labelArrSize <= *currentLanguage)
				labelLen = strlen(this->labelArr[0]);
			else
				labelLen = strlen(this->labelArr[*currentLanguage]);
		}
			if (labelLen + 2 < OUTPUT_LINE_LENGHT)
				fprintf(ios, "%s", ": "), fprintf(ios, fmt, *variable);
	}

	template<typename T>
	bool print<T>::forward(){
		return false;
	}


	template<typename T>
	class var : public print<T>{

	public:
		var(arrCreator<const char*>& __larrc, T* varPtr, const char* __fmt);
		bool forward();
	};

	template<typename T>
	var<T>::var(arrCreator<const char*>& __larrc, T* varPtr, const char* __fmt) : print<T>(__larrc, varPtr, __fmt){

	}

	template<typename T>
	bool var<T>::forward(){
		char* tmp = TBase::varEdit();
		if (tmp != NULL){
			sscanf(tmp, this->fmt, this->variable);
			free(tmp);
		}
		return false;
	}

}

#endif /* __TITEM_HPP__ */
