#include "MapSize.h"
#include "RawMap.h"
#include "Shape.h"
#include "Map.h"
#include <iostream>
#include "Position.h"
#include <cassert>
using namespace std;

Map::Map()
{
	for (int i = 0; i < MAP_SIZE_SOUTH; i++)
	{
		for (int j = 0; j < MAP_SIZE_EAST; j++)
		{
			map[i][j] = SHAPE_SOLID;
		}
	}
	start.south = 0;
	start.east = 0;
}
void Map::setAt(const Position& pos, Shape shape)
{
	map[pos.south][pos.east] = shape;
}
void Map::setRectangle(const Position& pos_min, int south_size, int east_size, Shape shape)
{
	assert(south_size >= 0);
	assert(east_size >= 0);
	assert(isInMap(pos_min, south_size, east_size) == true);
	for (int i = 0; i < south_size; i++)
	{
		for (int j = 0; j < east_size; j++)
		{
			map[pos_min.south + i][pos_min.east + j] = shape;
		}
	}
}

bool Map::isOpen(const Position& pos)const
{
	assert(isInMap(pos) == true);
	if (map[pos.south][pos.east] == SHAPE_SOLID)
		return false;
	else
		return true;
}

void Map::printMap()const
{
	for (int i = 0; i < MAP_SIZE_SOUTH; i++)
	{
		for (int j = 0; j < MAP_SIZE_EAST; j++)
		{
			cout << shapeGetMapChar(map[i][j]);
		}
		cout << endl;
	}
}
bool Map::isTunnel(const Position& pos)const
{
	assert(isInMap(pos) == true);
	return shapeIsTunnel(map[pos.south][pos.east]);
}
void Map::printDescription(const Position& pos)const
{
	assert(isInMap(pos) == true);
	assert(isCavern(pos) == false);
	if (isTunnel(pos) == true)
		cout << "You are in a tunnel" << endl;
	else
		cout << "You are in solid rock" << endl;
	if (isTunnelStraight(pos) == true)
	{
		cout << "The tunnel is straight here." << endl;
	}
	if (isTunnelDirection(pos, NORTH))
		cout << "You can go North" << endl;
	if (isTunnelDirection(pos, SOUTH))
		cout << "You can go South" << endl;
	if (isTunnelDirection(pos, EAST))
		cout << "You can go East" << endl;
	if (isTunnelDirection(pos, WEST))
		cout << "You can go West" << endl;
}

bool Map::isCavern(const Position& pos)const
{
	assert(isInMap(pos) == true);
	return shapeIsCavern(map[pos.south][pos.east]);
}

unsigned int Map::getCavernIndex(const Position& pos)const
{
	assert(isInMap(pos) == true);
	assert(isCavern(pos) == true);
	return shapeGetCavernIndex(map[pos.south][pos.east]);
}

bool Map::isTunnelStraight(const Position& pos)const
{
	if (isTunnel(pos) == true)
		return shapeIsTunnelStraight(map[pos.south][pos.east]);
	else if (isTunnel(pos) != true)
		return false;

}
bool Map::isTunnelDirection(const Position& pos, Direction direction) const
{
	assert(isInMap(pos) == true);
	assert(direction <= DIRECTION_COUNT);
	if (isTunnel(pos) == true)
		return shapeIsTunnelDirection(map[pos.south][pos.east], direction);
	else if (isTunnel(pos) != true)
		return false;
}

Position Map::getPlayerStart() const
{
	return start;
}
void Map::setPlayerStart(const Position& start1)
{
	assert(isInMap(start1) == true);
	start = start1;
}