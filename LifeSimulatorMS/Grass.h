#pragma once
#include "Plant.h"
#include <typeinfo>
class Grass : public Plant
{
public:
	Grass(int x, int y, World* world);

	~Grass();
};

