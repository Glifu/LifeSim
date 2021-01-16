#include "Bear.h"
#include "World.h"


Bear::Bear(int x, int y, World* world) : Animal(world, POS(x, y))
{
	this->init = 6;
	this->str = 9;
	this->sign = 'B';
	this->turnToSleep = 1;
}

void Bear::action(int range) {

	if (turnToSleep % 3 == 0) {
		this->str = this->str+1 ;
	}
	else {
		Animal::action(range);
	}
	this->turnToSleep++;
}

Bear::~Bear()
{
}
