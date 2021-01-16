#include "Grass.h"



Grass::Grass(int x, int y, World* world) : Plant(world, POS(x, y))
{
	this->str = 0;
	this->sign = '#';
}



Grass::~Grass()
{
}
