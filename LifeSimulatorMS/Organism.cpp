#include "Organism.h"
#include <Windows.h>
#include<stdio.h>
#include "World.h"
#include <iostream>

using namespace std;

Organism::Organism()
{
	this->age = 0;
	this->alive = true;
}

char Organism::getSign()
{
	return this->sign;
}

int Organism::getlastX()
{
	return this->lastpos.x;
}
int Organism::getlastY()
{
	return this->lastpos.y;
}

bool Organism::getLiveStatus()
{
	return this->alive;
}

void Organism::killOrg()
{
	this->alive = false;
}

int Organism::getAge()
{
	return this->age;
}

void Organism::setAge(int age)
{
	this->age = age;
}

void Organism::increaseAge()
{
	this->age++;
}

int Organism::getStr()
{
	return this->str;
}

void Organism::setStr(int newStr)
{
	this->str = newStr;
}

int Organism::getInit()
{
	return this->init;
}

int Organism::getPosX()
{
	return this->currpos.x;
}

int Organism::getPosY()
{
	return this->currpos.y;
}

Organism::~Organism()
{

}

Organism* Organism::detect(int x, int y)
{
	if (world->orgTab[y][x] != NULL) {
		return world->orgTab[y][x];
	}
	return NULL;
}

void Organism::printxy(int x, int y, char sign)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	_COORD pos;
	pos.X = x;
	pos.Y = y;
	SetConsoleCursorPosition(hConsole, pos);
	cout << sign;
	pos.X = 0;
	pos.Y = 22;
	SetConsoleCursorPosition(hConsole, pos);
}

bool Organism::isOutsideMap(int newX, int newY)
{
	if (newX > world->fromX&& newX <= world->x + world->fromX) {
		if (newY > world->fromY&& newY <= world->y + world->fromY) {
			return false;
		}
	}
	return true;
}
