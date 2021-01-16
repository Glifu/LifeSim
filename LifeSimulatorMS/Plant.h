#pragma once
#include "Organism.h"
class Plant : public Organism
{
public:
	Plant(World* world, POS pos);
	virtual void action(int range = 1);
	virtual void colision();
	virtual void draw();
	virtual bool has_defence(Organism* enemy);
	virtual void counter(Organism* enemy);
	~Plant();

protected:

};

