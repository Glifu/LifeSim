#pragma once
#include "Animal.h"
class Bear : public Animal
{
public:

	int turnToSleep;
	void action(int range);  // niedzwiedz jako specjalna akcje zasypia raz na 3 tury, nie wykonujac ruchu, ale zwiekszajac swoja sile o 1
	Bear(int x, int y, World* world);
	~Bear();
};

