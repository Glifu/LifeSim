#pragma once
#include "Plant.h"
#include <typeinfo>
class Thorn : public Plant
{
public:
	Thorn(int x, int y, World* world);

	~Thorn();
};

