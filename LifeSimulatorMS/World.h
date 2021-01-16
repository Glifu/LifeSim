#pragma once
#include"Organism.h"
#include "Wolf.h"
#include "Sheep.h"
#include "Antylope.h"
#include "Bear.h"
#include "Lion.h"
#include "Grass.h"
#include "Guarana.h"
#include "Thorn.h"


#include <vector>

#define VECTOR_TAB_SIZE 8
#define ORGANISM_NUMBER 8

class World
{
public:


	const static int fromX = 0;
	const static int fromY = 0;
	World();
	World(int x, int y);
	void init();
	void draw();
	void turn();
	void createOrg(int px, int py, char sign, int age = 0);
	~World();

private:
	std::vector<Organism*> organism[VECTOR_TAB_SIZE]; //kontener na organizmy
	Organism*** orgTab;
	int x;
	int y;
	int turnCount;
	void printxy(int x, int y, char sign);
	void drawBorder();
	void clearMap();
	int findOrgIndex(Organism* org);
	void destroyOrg(Organism* org);

	friend class Organism;
	friend class Animal;
	friend class Plant;
	friend class Antylope;
	friend class Lion;
	friend class Guarana;
	friend class Thorn;
	friend class Bear;
};

