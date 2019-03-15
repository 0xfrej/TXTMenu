/*
 * TBase.hpp
 *
 * Created: 11/22/2018
 *  Author: Peter Karaba
 */


#ifndef __TBASE_HPP__
#define __TBASE_HPP__

#include "arrCreator.hpp"
#include <stdint.h>

namespace TBase {

	// Base item class for real item type classes to derive from (due to my ugly code it cannot be abstract anymore)
	class item{
	public:
		virtual void render(uint8_t* currentLanguage){};
		virtual bool forward();
		virtual void callFunction(){};
	};


	// Item container
	class container{
	protected:
		uint8_t arrSize = 0;
		item** array = NULL;

	public:
		container();
		void render(uint8_t index, uint8_t* currentLanguage); // Call render function of item in container on index
		bool forward(uint8_t& index); // If item is container, then return and set current container to it
		void callFunction(uint8_t& index); // Call item function in array on index	};
		void setSize(uint8_t newSize);
		uint8_t getSize();
		void setArr(item** newPtr);
	};


	class menuCtrl : container{
	protected:
		uint8_t *currentLanguage=0;

	public:
		menuCtrl(arrCreator<item*>& __iarrc);
		virtual void start(){};
	protected:
		virtual void render(){};
		virtual void navigation(){};
	};


	// Navigation functions
	void navForward(container* nextContainer);
	void navBackward();
	container* getCurrentContainer();

	char* varEdit();

}


#endif /* __TBASE_HPP__ */
