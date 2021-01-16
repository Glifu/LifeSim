#include "Animal.h"
#include "World.h"
#include <typeinfo>
Animal::Animal(World* world, POS pos) : Organism() {
	srand(time(NULL));
	this->world = world;
	this->currpos = this->lastpos = pos;
	world->orgTab[currpos.y][currpos.x] = this;
}

Animal::Animal() {}

Animal::~Animal() {}

void Animal::action(int range)
{
	int px, py;
	lastpos = currpos;
	do {
		px = (rand() % 3) - 1;
		py = (rand() % 3) - 1;
	} while (px == 0 && py == 0);
	currpos.x += range * px;
	currpos.y += range * py;
	if (isOutsideMap(currpos.x, currpos.y)) {
		currpos = lastpos;
	}
}

void Animal::counter(Organism* enemy) {

	if ((enemy->getSign() == 'L') && (enemy->getStr() > 5)) {
		Animal::action(1);
	}
}

void Animal::colision()
{
	Organism* org = detect(currpos.x, currpos.y);
	if (org == NULL) {
		world->orgTab[currpos.y][currpos.x] = this;
		world->orgTab[lastpos.y][lastpos.x] = NULL;
	}
	else if (org == this) {
		world->orgTab[currpos.y][currpos.x] = this;
	}
	else
	{
		if (typeid(*this) == typeid(*org)) { // rozmnazanie
			int px, py;
			do {
				px = (rand() % 3) - 1 + this->currpos.x;
				py = (rand() % 3) - 1 + this->currpos.y;

			} while (px == this->lastpos.x && py == this->lastpos.y || px == org->getPosX() && py == getPosY() || isOutsideMap(px, py));

			if (detect(px, py) == NULL) {
				world->createOrg(px, py, this->sign);
			}
			this->currpos = this->lastpos;

		}
		else {//walka
			if (this->str > org->getStr()) {
				world->destroyOrg(org);
				world->orgTab[currpos.y][currpos.x] = this;
				world->orgTab[lastpos.y][lastpos.x] = NULL;
			}
			else if (this->str <= org->getStr()) {
				this->currpos = this->lastpos;
			}
		}
	}
}

bool Animal::has_defence(Organism* enemy)
{
	return false;
}

void Animal::draw()
{
	printxy(currpos.x, currpos.y, this->sign);
}


