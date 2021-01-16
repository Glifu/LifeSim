#include "Lion.h"
#include "World.h"


Lion::Lion(int x, int y, World* world) : Animal(world, POS(x, y))
{
	this->init = 7;
	this->str = 11;
	this->sign = 'L';
}

Lion::~Lion()
{
}

