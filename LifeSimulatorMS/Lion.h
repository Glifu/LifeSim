#pragma once
#include "Animal.h"

class Lion : public Animal
{
public:
	Lion(int x, int y, World* world); //specjalna umiejetnosc lwa zastosowan dla wszystkich zwierzat w counter -> Animal
	~Lion();
};

