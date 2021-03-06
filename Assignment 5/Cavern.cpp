#include "Cavern.h"
#include <cassert>
#include <iostream> 
using namespace std;


Cavern::Cavern() : animal()
{
	south = CAVERN_SIZE_MIN;
	east = CAVERN_SIZE_MIN;
	for (int i = 0; i < 4; i++)
		exitOrNot[i] = false;
}
Cavern::Cavern(int south_size1, int east_size1) : animal()
{
	assert(south_size1 >= CAVERN_SIZE_MIN && east_size1 >= CAVERN_SIZE_MIN);
	south = south_size1;
	east = east_size1;
	for (int i = 0; i < 4; i++)
		exitOrNot[i] = false;
}

int Cavern::getSouthSize()const
{
	return south;
}

int Cavern::getEastSize()const
{
	return east;
}

bool Cavern::isExit(Direction direction)const
{
	assert(direction < DIRECTION_COUNT);
	if (exitOrNot[direction] == true)
		return true;
	else
		return false;
}

Position Cavern::getExitPosition(Direction direction)const
{
	assert(direction < DIRECTION_COUNT);
	assert(isExit(direction) == true);
	return exitLocation[direction];
}

void Cavern::addExit(Direction direction, const Position& position)
{
	assert(invariant());
	assert(direction < DIRECTION_COUNT);
	assert(isExit(direction) == false);
	if (direction == 0)
	{
		exitOrNot[0] = true;
		exitLocation[0] = position;
	}
	if (direction == 1)
	{
		exitOrNot[1] = true;
		exitLocation[1] = position;
	}
	if (direction == 2)
	{
		exitOrNot[2] = true;
		exitLocation[2] = position;
	}
	if (direction == 3)
	{
		exitOrNot[3] = true;
		exitLocation[3] = position;
	}
}

void Cavern::addAnimal(unsigned int species_number)
{
	assert(species_number >= 0 && species_number < 21);
	animal.add(species_number);
}

void Cavern::print()const 
{
	cout << "You are in a Cavern " << east << "0 ft East by " << south << "0 ft South in size." << endl;
	if (isExit(0) == true)
		cout << "There is an exit leading North." << endl;
	if (isExit(1) == true)
		cout << "There is an exit leading South." << endl;
	if (isExit(2) == true)
		cout << "There is an exit leading East." << endl;
	if (isExit(3) == true)
		cout << "There is an exit leading West." << endl;
	animal.print();
}

bool Cavern::invariant()const
{
	if (south >= CAVERN_SIZE_MIN && east >= CAVERN_SIZE_MIN)
		return true;
	else
		return false;
}