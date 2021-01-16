#include "Plant.h"
#include "World.h"


Plant::Plant(World* world, POS pos) : Organism()
{
	currpos = lastpos = pos;
	this->world = world;
	this->init = 0;
}

void Plant::action(int range)
{
	Organism* neighbour;
	int spawnChance = rand() % 50;
	if (spawnChance != 1) return;

	for (int y = currpos.y - 1; y <= currpos.y + 1; y++) {
		for (int x = currpos.x - 1; x <= currpos.x + 1; x++) {
			if (isOutsideMap(x, y)) continue;
			if (x == currpos.x && y == currpos.y) continue;
			neighbour = detect(x, y);
			if (neighbour == NULL) {
				world->createOrg(x, y, this->sign);
				x = currpos.x + 3;
				y = currpos.y + 3;
			}
		}
	}
}

void Plant::colision() {}
void Plant::draw()
{
	printxy(currpos.x, currpos.y, this->sign);
}
bool Plant::has_defence(Organism* enemy) { return false; }
void Plant::counter(Organism* enemy) {}

Plant::~Plant()
{
}
