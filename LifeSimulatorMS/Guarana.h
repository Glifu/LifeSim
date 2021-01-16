#pragma once
#include "Plant.h"
class Guarana : public Plant
{
public:
	Guarana(int x, int y, World* world);
	bool has_defence(Organism* enemy);
	void counter(Organism* enemy);
	~Guarana();
};

