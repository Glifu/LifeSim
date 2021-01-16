#include "Thorn.h"



Thorn::Thorn(int x, int y, World* world) : Plant(world, POS(x, y))
{
	this->str = 2;
	this->sign = '^';
}



Thorn::~Thorn()
{
}
