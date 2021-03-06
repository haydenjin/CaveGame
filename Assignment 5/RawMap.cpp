#include "MapSize.h"
#include "Shape.h"
#include "RawMap.h"

void rawMapLoad(char raw[][MAP_SIZE_EAST], const string& filename)
{
	string my_filename = "map5.txt";
	ifstream input1;
	input1.open("map5.txt");
	if (input1.fail())
		cerr << "map5.txt could not be opened." << endl;
	for (int i = 0; i < MAP_SIZE_SOUTH; i++)
	{
		for (int j = 0; j < MAP_SIZE_EAST; j++)
		{
			input1 >> raw[i][j];
		}
		input1.ignore(1000, '\n');
	}
	cout << "map5.txt was opened." << endl;
	input1.close();
}
void rawMapPrint(const char raw[][MAP_SIZE_EAST])
{
	for (int i = 0; i < MAP_SIZE_SOUTH; i++)
	{
		for (int j = 0; j < MAP_SIZE_EAST; j++)
		{
			cout << raw[i][j];
		}
		cout << endl;
	}
}
bool rawMapIsOpen(const char raw[][MAP_SIZE_EAST], int south, int east)
{
	if (south >= MAP_SIZE_SOUTH ||
		south < 0 ||
		east < 0 ||
		east >= MAP_SIZE_EAST ||
		raw[south][east] == '#')
		return false;
	else
		return true;
}
Shape rawMapCalculateShape(const char raw[][MAP_SIZE_EAST], int south, int east)
{
	bool up, down, right, left = false;
	if (rawMapIsOpen(raw, south, east) == false)
		return SHAPE_SOLID;
	else
	{
		if (rawMapIsOpen(raw, south - 1, east) == false)
			up = false;
		else
			up = true;
		if (rawMapIsOpen(raw, south + 1, east) == false)
			down = false;
		else
			down = true;
		if (rawMapIsOpen(raw, south, east - 1) == false)
			left = false;
		else
			left = true;
		if (rawMapIsOpen(raw, south, east + 1) == false)
			right = false;
		else
			right = true;
	}
	return shapeCalculate(up, down, right, left);
}

bool rawMapIsCavern(const char raw[][MAP_SIZE_EAST], int south, int east)
{
	if (rawMapIsOpen(raw, south, east) == true &&
		rawMapIsOpen(raw, south + 1, east) == true &&
		rawMapIsOpen(raw, south, east + 1) == true &&
		rawMapIsOpen(raw, south + 1, east + 1) == true)
		return true;
	else
		return false;
}

int rawMapGetCavernSouthSize(const char raw[][MAP_SIZE_EAST], int south, int east)
{
	for (int i = 0; i < MAP_SIZE_SOUTH; i++)
	{
		if (rawMapIsOpen(raw, south + i, east) == true && rawMapIsOpen(raw, south + i, east + 1) == true)
			;
		else
			return i;
	}
	return -1;
}

int rawMapGetCavernEastSize(const char raw[][MAP_SIZE_EAST], int south, int east)
{
	for (int i = 0; i < MAP_SIZE_EAST; i++)
	{
		if (rawMapIsOpen(raw, south, east) == true && rawMapIsOpen(raw, south + 1, east) == true)
			east = east + 1;
		else
			return i;
	}
	return -1;
}

Cavern rawMapCalculateCavern(const char raw[][MAP_SIZE_EAST], int south, int east)
{
	int south_size = rawMapGetCavernSouthSize(raw, south, east);
	int east_size = rawMapGetCavernEastSize(raw, south, east);

	Cavern a(south_size, east_size);

	int exit_north = rawMapFindExitToSouth(raw, south - 1, east, east_size);
	int exit_south = rawMapFindExitToSouth(raw, south + south_size, east, east_size);
	int exit_east = rawMapFindExitToEast(raw, south, east + east_size, south_size);
	int exit_west = rawMapFindExitToEast(raw, south, east - 1, south_size);

	Position pos_north = toPosition(south - 1, east + exit_north);
	Position pos_south = toPosition(south + south_size, east + exit_south);
	Position pos_east = toPosition(south + exit_east, east + east_size);
	Position pos_west = toPosition(south + exit_west, east - 1);

	for (int i = south; i < (south + south_size); i++)
		{
			for (int j = east; j < (east + east_size); j++)
			{
				if (animalOrNot(raw, i, j) == true)
					a.addAnimal(getAnimalValue(raw, i, j));
			}
		}

	
	if (exit_north != -1)
	{
		a.addExit(NORTH, pos_north);
		a.getExitPosition(NORTH);
	}

	if (exit_south != -1)
	{
		a.addExit(SOUTH, pos_south);
		a.getExitPosition(SOUTH);
	}

	if (exit_east != -1)
	{
		a.addExit(EAST, pos_east);
		a.getExitPosition(EAST);
	}

	if (exit_west != -1)
	{
		a.addExit(WEST, pos_west);
		a.getExitPosition(WEST);
	}
	return a;
}

int rawMapFindExitToSouth(const char raw[][MAP_SIZE_EAST], int south, int east, int max_distance)
{
	for (int i = 0; i <= max_distance; i++)
	{
		if (rawMapIsOpen(raw, south, east) == true)
		{
			return i;
		}
		else
			east += 1;
	}
	return -1;
}

int rawMapFindExitToEast(const char raw[][MAP_SIZE_EAST], int south, int east, int max_distance)
{
	for (int i = 0; i <= max_distance; i++)
	{
		if (rawMapIsOpen(raw, south, east) == true)
		{
			return i;
		}
		else
			south += 1;
	}
	return -1;
}

Position rawMapGetPlayerStart(const char raw[][MAP_SIZE_EAST])
{
	Position p;
	p.south = 0;
	p.east = 0;
	for (int i = 0; i < MAP_SIZE_SOUTH; i++)
	{
		for (int j = 0; j < MAP_SIZE_EAST; j++)
		{
			if (raw[i][j] == '@')
				p = toPosition(i, j);
		}
	}
	return p;
}

bool animalOrNot(const char raw[][MAP_SIZE_EAST], int s, int e)
{
	const int SPECIES_COUNT = ANIMAL_KINDS;
	if (raw[s][e] >= 'A' && raw[s][e] < ('A' + SPECIES_COUNT))
		return true;
	else
		return false;
}

int getAnimalValue(const char raw[][MAP_SIZE_EAST], int s, int e)
{
	assert(animalOrNot(raw, s, e) == true);
	int value = raw[s][e];
	value = value - 'A';
	return value;
}