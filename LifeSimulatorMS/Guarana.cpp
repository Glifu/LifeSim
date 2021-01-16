#include "Guarana.h"
#include "World.h"


Guarana::Guarana(int x, int y, World* world) : Plant(world, POS(x, y))
{
	this->str = 0;
	this->sign = 'G';
}

bool Guarana::has_defence(Organism* enemy)
{
	alive = false;
	return true;
}

void Guarana::counter(Organism* enemy)
{
	enemy->setStr(enemy->getStr() + 3);
}

Guarana::~Guarana()
{
}
