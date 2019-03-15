/*
 * arrCreator.hpp
 *
 * Created: 11/22/2018 14:12:50
 *  Author: Peter Karaba
 * Description:
 *	Class for creating dynamic arrays of any type and then returning it's pointer.
 *	 !!!! DO NOT FORGET TO FREE THE ARRAY !!!!
 *
 * Object definition example:
 * T - desired array typename
 *
 *	arrCreator<const char*> TLac;
 *
 * Usage example:
 *	arrCreatorObject << "Hello" << "World";
 *	uint8_t labelArrSize = arrCreatorObject.getOC();
 *	char** labelArr = arrCreatorObject.getArr();
 */


#ifndef __ARRCREATOR_HPP__
#define __ARRCREATOR_HPP__

#include <stdlib.h>
#include <stdint.h>

template<typename T>
class arrCreator{
private:
	T* array;
	uint8_t objectCount = 0;

public:
	arrCreator& operator << (T object){
		if (objectCount < 255){
			if (objectCount == 0)
				array = (T*)malloc(sizeof(T)*(1));
			else
				array = (T*)realloc(array, sizeof(T)*(objectCount+1));

			array[objectCount++] = object;
		}
		return *this;
	}
	uint8_t getOC(){ // Get count of objects in array
		return objectCount;
	}
	T* getArr(){ // Get pointer to created array
		if (objectCount != 0){
			objectCount = 0;
			return array;
		}
		return NULL;
	}
};

#endif /* __ARRCREATOR_HPP___ */