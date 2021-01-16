#pragma once
#include <cstdint>
#include <cstdlib>
#include <ctime>
class World;


class Organism //abstract
{
public:
	Organism();
	struct POS {
		int x;
		int y;
		POS(int px, int py) : x(px), y(py) { }
		POS() : x(0), y(0) {}
	};

	int getStr();
	int getInit();
	void setStr(int newStr);
	int getPosX();
	int getPosY();

	int getlastX();
	char getSign();
	int getlastY();
	bool getLiveStatus();
	void killOrg();
	void setAge(int age);
	int getAge();
	void increaseAge();
	virtual void action(int range = 1) = 0;
	virtual void colision() = 0;
	virtual void draw() = 0;
	virtual bool has_defence(Organism* enemy) = 0;
	virtual void counter(Organism* enemy) = 0;
	~Organism();

protected:
	Organism* detect(int x, int y);
	int str;
	int init;

	POS currpos;
	POS lastpos;

	World* world;

	int age;

	bool alive;
	char sign;
	void printxy(int x, int y, char sign);
	bool isOutsideMap(int newX, int newY);

	friend class Antylope;
};