#pragma once
#include "Organism.h"

class Animal : public Organism
{
public:
	Animal();
	Animal(World* world, POS pos);

	virtual void action(int range = 1);
	virtual void colision();
	virtual bool has_defence(Organism* enemy);
	virtual void counter(Organism* enemy);
	void draw();
	~Animal();
protected:
};

