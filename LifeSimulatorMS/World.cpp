#include "World.h"
#include <Windows.h>
#include <typeinfo>
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

World::World()
{

	this->x = 20;
	this->y = 20;
	this->turnCount = 0;
	orgTab = NULL;
}

World::World(int x, int y)
{

	this->x = x;
	this->y = y;
	this->turnCount = 0;
	orgTab = NULL;
}

void World::init()
{
	int px, py, type;
	orgTab = new Organism * *[this->y + 1];
	for (int py = 0; py < this->y + 1; py++)
	{
		orgTab[py] = new Organism * [this->x];
	}
	for (int py = 0; py < this->y + 1; py++)
	{
		for (int px = 0; px < this->x + 1; px++)
		{
			orgTab[py][px] = NULL;
		}

	}

	drawBorder();
	px = rand() % this->x + 1;
	py = rand() % this->y + 1;
	char types[] = { '@', '<', 'V', 'L', 'B', 'G', '#', '^' };
	for (int i = 1; i < ORGANISM_NUMBER; i++)
	{
		Sleep(100);
		type = rand() % 8;
		do {
			px = rand() % this->x + 1;
			py = rand() % this->y + 1;
		} while (orgTab[py][px] != NULL);
		createOrg(px, py, types[type]);
	}

}


void World::draw()
{
	clearMap();
	for (int i = VECTOR_TAB_SIZE - 1; i >= 0; i--) {
		if (organism[i].empty()) continue;
		for (int j = 0; j < organism[i].size(); j++) {
			organism[i][j]->draw();
		}
	}
}

void World::turn()
{
	this->turnCount++;
	for (int i = VECTOR_TAB_SIZE - 1; i >= 0; i--) {
		if (organism[i].empty()) continue;
		for (int j = 0; j < organism[i].size(); j++) {
			organism[i][j]->action();
			organism[i][j]->colision();
			organism[i][j]->increaseAge();
			if (organism[i][j]->getLiveStatus() == false) {
				orgTab[organism[i][j]->getlastY()][organism[i][j]->getlastX()] = NULL;
				destroyOrg(organism[i][j]);
			}


		}
	}


}

void World::createOrg(int px, int py, char sign, int age)
{
	Organism* ptr = NULL;
	switch (sign)
	{
	case 'V':
	{
		ptr = new Antylope(px, py, this);
		break;
	}
	case 'B':
	{
		ptr = new Bear(px, py, this);
		break;
	}
	case '#':
	{
		ptr = new Grass(px, py, this);
		break;
	}
	case 'G':
	{
		ptr = new Guarana(px, py, this);
		break;
	}
	case 'L':
	{
		ptr = new Lion(px, py, this);
		break;
	}
	case '@':
	{
		ptr = new Sheep(px, py, this);
		break;
	}
	case '<':
	{
		ptr = new Wolf(px, py, this);
		break;
	}
	case '^': {
		ptr = new Thorn(px, py, this);
		break;
	}
	default:
	{
		throw "Unable to read sign";
	}
	}

	orgTab[py][px] = ptr;
	organism[ptr->getInit()].push_back(ptr);
	ptr->setAge(age);
}

World::~World()
{
	for (int i = 0; i < VECTOR_TAB_SIZE; i++) {
		organism[i].clear();
	}

}

void World::destroyOrg(Organism* org)
{
	int index = findOrgIndex(org);
	if (index == -1) throw "Org not found exception";
	orgTab[org->getPosY()][org->getPosX()] = NULL;
	organism[org->getInit()].erase(organism[org->getInit()].begin() + index);
}

//private
void World::clearMap()
{
	for (int y = fromY + 1; y < this->y + fromY + 1; y++) {
		for (int x = fromX + 1; x < this->x + fromX + 1; x++) {
			printxy(x, y, ' ');
		}
	}
}

//private
void World::drawBorder() {

	system("cls");
	enum SIGN {
		SGN_LEFT_BOTTOM = 200,
		SGN_RIGHT_BOTTOM = 188,
		SGN_LEFT_UP = 201,
		SGN_RIGHT_UP = 187,
		SGN_HORIZONTAL = 205,
		SGN_VERTICAL = 186
	};
	for (int i = 0; i < this->x + 1; i++) {
		printxy(fromX + i, fromY + 0, SGN_HORIZONTAL);
		printxy(fromX + i, fromY + this->y + 1, SGN_HORIZONTAL);
	}
	for (int i = 0; i < this->y + 1; i++) {
		printxy(fromX + 0, fromY + i, SGN_VERTICAL);
		printxy(fromX + this->x + 1, fromY + i, SGN_VERTICAL);
	}

	printxy(fromX + 0, fromY + 0, SGN_LEFT_UP);
	printxy(fromX + this->x + 1, fromY + 0, SGN_RIGHT_UP);
	printxy(fromX + 0, fromY + this->y + 1, SGN_LEFT_BOTTOM);
	printxy(fromX + this->x + 1, fromY + this->y + 1, SGN_RIGHT_BOTTOM);
}

//private
void World::printxy(int x, int y, char sign)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	_COORD pos;
	pos.X = x;
	pos.Y = y;
	SetConsoleCursorPosition(hConsole, pos);
	cout << sign;
	pos.X = 20;
	pos.Y = 20;
	SetConsoleCursorPosition(hConsole, pos);
}

int World::findOrgIndex(Organism* org)
{
	int initIndex = org->getInit();
	int py = org->getPosY();
	int px = org->getPosX();
	int index;
	for (index = 0; index < organism[initIndex].size(); index++)
	{
		if (organism[initIndex][index]->getPosX() == px && organism[initIndex][index]->getPosY() == py) {
			return index;
		}
	}
	return -1;
}
