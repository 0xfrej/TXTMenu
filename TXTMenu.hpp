/*
 * TXTMenu.hpp
 *
 * Created: 11/22/2018
 *  Author: Peter Karaba
 */

#ifndef __TXTMENU_HPP__
#define __TXTMENU_HPP__

#include "src/TBase.hpp"
#include "src/TItem.hpp"
#include "src/arrCreator.hpp"
#include <stdint.h>


#define _CAC_ cac
#define _LAC_ lac
#define menuDefSTART() \
	using namespace TItem; \
	arrCreator<TBase::item*> _CAC_; \
	arrCreator<const char*> _LAC_;
#define menuDefEND() \
	_CAC_.~arrCreator(); \
	_LAC_.~arrCreator();

class TXTMenu : public TBase::menuCtrl{
private:
	uint8_t	selected = 0;
	uint8_t selectedCharPos = 0;

public:
	TXTMenu(arrCreator<TBase::item*>& __iarrc, uint8_t* language);
	void start();

private:
	void render();
	void navigation();
};

#endif /* __TXTMENU_HPP__ */
