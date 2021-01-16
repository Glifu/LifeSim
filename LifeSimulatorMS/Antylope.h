#pragma once
#include "Animal.h"
class Antylope :
	public Animal
{
public:
	Antylope(int x, int y, World* world);
	void action(int range);
	bool has_defence(Organism* enemy);
	void counter(Organism* enemy);
	~Antylope();
};

