#include "Antylope.h"
#include "World.h"

Antylope::Antylope(int x, int y, World* world) : Animal(world, POS(x, y))
{
	this->init = 4;
	this->str = 4;
	this->sign = 'V';
}

void Antylope::action(int range)
{
	range = 2;
	Animal::action(range);
}
void Antylope::counter(Organism* enemy)
{
	Organism* org;
	do {
		Animal::action(1);
		org = detect(this->currpos.x, this->currpos.y);
	} while (this->currpos.x == enemy->getPosX() && this->currpos.y == enemy->getPosY() || org != NULL);
	world->orgTab[currpos.y][currpos.x] = this;
	world->orgTab[lastpos.y][lastpos.x] = enemy;
	world->orgTab[enemy->lastpos.y][enemy->lastpos.x] = NULL;
}



bool Antylope::has_defence(Organism* enemy)
{
	int abilityToRun = rand() % 2;
	if (abilityToRun == 1) return true;
	else return false;
}

Antylope::~Antylope()
{
}
