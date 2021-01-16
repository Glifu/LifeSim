#include "Sheep.h"



Sheep::Sheep(int x, int y, World* world) :Animal(world, POS(x, y))
{
	this->init = 4;
	this->str = 4;
	this->sign = '@';
}


Sheep::~Sheep()
{
}
