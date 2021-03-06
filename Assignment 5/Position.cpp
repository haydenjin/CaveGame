#include "Position.h"
#include "MapSize.h"
Position toPosition(int south, int east)
{
	Position here;
	here.south = south;
	here.east = east;
	return here;
}
bool isInMap(const Position& position)
{
	if (position.south >= MAP_SIZE_SOUTH || position.south < 0 || position.east < 0 || position.east >= MAP_SIZE_EAST)
		return false;
	else
		return true;
}
bool isInMap(const Position& pos_min, int south_size, int east_size)
{
	if (pos_min.south < 0 || pos_min.east < 0 || pos_min.south + south_size > MAP_SIZE_SOUTH || pos_min.east + east_size > MAP_SIZE_EAST)
		return false;
	else
		return true;
}
Position moveDirection(const Position& position, Direction direction)
{
	Position position1;
	if (direction == 0)
	{
		position1.south = position.south - 1;
		position1.east = position.east;
	}
	if (direction == 1)
	{
		position1.south = position.south + 1;
		position1.east = position.east;
	}
	if (direction == 2)
	{
		position1.east = position.east + 1;
		position1.south = position.south;
	}
	if (direction == 3)
	{
		position1.east = position.east - 1;
		position1.south = position.south;
	}
	return position1;
}