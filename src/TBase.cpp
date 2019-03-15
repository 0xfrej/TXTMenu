/*
 * TBase.cpp
 *
 * Created: 11/22/2018
 *  Author: Peter Karaba
 */

#include "TBase.hpp"
#include "../config.hpp"
#include "redirect.hpp"
#include <stdio.h>

namespace TBase {

	static TBase::container*	navDepthArr[MAXDEPTH];
	static uint8_t				currentContainerIndex=0;

	bool item::forward(){
		return false;
	}

	container::container(){
	}
	void container::render(uint8_t index, uint8_t* currentLanguage){
		array[index]->render(currentLanguage);
	}

	bool container::forward(uint8_t& index){
		return array[index]->forward();
	}

	void container::callFunction(uint8_t& index){
		array[index]->callFunction();
	}

	void container::setSize(uint8_t newSize){

	}

	uint8_t container::getSize(){

	}
	void container::setArr(item** newPtr){

	}

	menuCtrl::menuCtrl(arrCreator<item*>& __iarrc){
		arrSize = __iarrc.getOC();
		array = __iarrc.getArr();
		navDepthArr[0] = this; // Set root container for navigation
	}


	void navForward(TBase::container* nextContainer){
		if (currentContainerIndex < 255)
			navDepthArr[++currentContainerIndex] = nextContainer;
	}

	void navBackward(){
		if (currentContainerIndex > 0)
			currentContainerIndex--;
	}

	TBase::container* getCurrentContainer(){
		return navDepthArr[currentContainerIndex];
	}

	char* varEdit(){

		output_enterEditMode();

		char key; // pressed key
		char* retValue = NULL;
		char* newValueStr = (char*)malloc(sizeof(char)); // Typed string
			newValueStr[0] = '\0';
		uint8_t digitCount = 0; // Counter for typed digits

		while(1){

			output_clear();
			fprintf(ios, ":%s", newValueStr);
			key = input_getc();

			if (!( (key >= 'a' && key <= 'z') || (key >= 'A' && key <= 'Z') || (key - 48 >= 0 && key - 48 <= 9) || key == '.' || key == Key_DEL || key == Key_OK || key == Key_UP ||
			key == Key_DOWN || key == Key_LEFT || key == Key_RIGHT )) // if character is forbidden, then skip
				continue;

			switch(key){

				case Key_LEFT:
				{
					free(newValueStr);
					goto escape;
				}
				case Key_DEL: //Delete one digit
					if (digitCount == 0)
						break;
					newValueStr[--digitCount] = '\0';
					break;
				case Key_OK: // Exit & save
					retValue = newValueStr;
					goto escape;
				case Key_RIGHT: case Key_UP: case Key_DOWN: break;
				default:
					newValueStr = (char*)realloc(newValueStr,sizeof(char)*(digitCount+2));
					newValueStr[digitCount] = key; //Copy key to string
					newValueStr[++digitCount] = '\0';
					break;

			}
			delay_ms(NAVDELAY);
		}
		escape:
		output_exitEditMode();
		return retValue;
	}

}
