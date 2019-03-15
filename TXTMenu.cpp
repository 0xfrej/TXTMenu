/*
 * TXTMenu.cpp
 *
 * Created: 12/30/2018 14:40:38
 *  Author: Peter Karaba
 */

#include "TXTMenu.hpp"
#include "config.hpp"
#include <stddef.h>
#include "src/redirect.hpp"

TXTMenu::TXTMenu(arrCreator<TBase::item*>& __iarrc, uint8_t* language) : TBase::menuCtrl(__iarrc){
	currentLanguage = language;
}

void TXTMenu::start(){
	iosinit(); // Init IO streams
	render(); // First render
	navigation(); // Let's get starteeeed
}

void TXTMenu::render(){
	output_clear();

	for (uint8_t i = 0; i < OUTPUT_LINE_COUNT && i < TBase::getCurrentContainer()->arrSize; i++){
		if(i == selectedCharPos)
			output_gotoxy(0,i), output_putc(SITEMCHAR), TBase::getCurrentContainer()->render(selected, currentLanguage);
		else{
			output_gotoxy(1,i);
			if(i < selectedCharPos)
				TBase::getCurrentContainer()->render(selected - selectedCharPos - i, currentLanguage);
			else
				TBase::getCurrentContainer()->render(selected - selectedCharPos + i, currentLanguage);
		}
	}
}

void TXTMenu::navigation(){
	while(1){
		switch(input_getc()){
			case Key_UP: // Key_Up is pressed
				if (selectedCharPos > 0)
					selectedCharPos--;

				if (selected > 0) // If actual item is first then go to last item  else go to previous item
					selected--;
				else
					selected = TBase::getCurrentContainer()->arrSize - 1, selectedCharPos = OUTPUT_LINE_COUNT - 1;
				break;

			case Key_DOWN: // Key_Down pressed
				if (selectedCharPos < OUTPUT_LINE_COUNT - 1)
					selectedCharPos++;

				if (selected == TBase::getCurrentContainer()->arrSize - 1) // If actual item is last then go to first item else go to next item
					selected = 0, selectedCharPos = 0;
				else
					selected++;
				break;

			case Key_LEFT: // Key_Left pressed
				// If actual item has a parent menu then go to that menu
				TBase::navBackward();
				selected = 0, selectedCharPos = 0;
				break;

			case Key_RIGHT: // Key_Right pressed
				if (TBase::getCurrentContainer()->forward(selected) == true) // if item has subcontainer 
					selected = 0, selectedCharPos = 0;
				break;

			case Key_OK: // Key_Ok pressed
				// If selected item has function then call it
				TBase::getCurrentContainer()->callFunction(selected);
				break;

			default:
				break;
		}
		render();
		delay_ms(NAVDELAY);
	}
}