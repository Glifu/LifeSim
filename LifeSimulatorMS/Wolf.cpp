#include "Wolf.h"
#include<cstdio>


Wolf::Wolf(int x, int y, World* world) :Animal(world, POS(x, y))
{
	this->init = 5;
	this->str = 9;
	this->sign = '<';
}

Wolf::~Wolf()
{

}
