#include "Shape.h"
#include <cassert>
bool shapeIsTunnel(Shape shape)
{
	if (shape < SHAPE_SOLID)
		return true;
	else
		return false;
}

bool shapeIsTunnelStraight(Shape shape)
{
	assert(shapeIsTunnel(shape) == true);
	if (shape == SHAPE_NS_STRAIGHT || shape == SHAPE_EW_STRAIGHT)
		return true;
	else
		return false;
}
bool shapeIsTunnelDirection(Shape shape, Direction direction)
{
	assert(shapeIsTunnel(shape) == true);
	assert(direction <= DIRECTION_COUNT);
	if (shape == SHAPE_BUBBLE)
	{
		return false;
	}
	if (shape == SHAPE_N_DEAD_END && direction == NORTH)
		return true;
	else if (shape == SHAPE_N_DEAD_END && direction != NORTH)
		return false;

	if (shape == SHAPE_S_DEAD_END && direction == SOUTH)
		return true;
	else if (shape == SHAPE_S_DEAD_END && direction != SOUTH)
		return false;
	if (shape == SHAPE_E_DEAD_END && direction == EAST)
		return true;
	else if (shape == SHAPE_E_DEAD_END && direction != EAST)
		return false;
	if (shape == SHAPE_W_DEAD_END && direction == WEST)
		return true;
	else if (shape == SHAPE_W_DEAD_END && direction != WEST)
		return false;
	if (shape == SHAPE_NS_STRAIGHT)
	{
		if (direction == NORTH || direction == SOUTH)
			return true;
		else
			return false;
	}
	if (shape == SHAPE_EW_STRAIGHT)
	{
		if (direction == EAST || direction == WEST)
			return true;
		else
			return false;
	}
	if (shape == SHAPE_NE_CORNER)
	{
		if (direction == NORTH || direction == EAST)
			return true;
		else
			return false;
	}
	if (shape == SHAPE_NW_CORNER)
	{
		if (direction == NORTH || direction == WEST)
			return true;
		else
			return false;
	}
	if (shape == SHAPE_SE_CORNER)
	{
		if (direction == SOUTH || direction == EAST)
			return true;
		else
			return false;
	}
	if (shape == SHAPE_SW_CORNER)
	{
		if (direction == SOUTH || direction == WEST)
			return true;
		else
			return false;
	}
	if (shape == SHAPE_NSE_T_JUNCTION)
	{
		if (direction == NORTH || direction == SOUTH || direction == EAST)
			return true;
		else
			return false;
	}
	if (shape == SHAPE_NSW_T_JUNCTION)
	{
		if (direction == NORTH || direction == SOUTH || direction == WEST)
			return true;
		else
			return false;
	}
	if (shape == SHAPE_NEW_T_JUNCTION)
	{
		if (direction == NORTH || direction == WEST || direction == EAST)
			return true;
		else
			return false;
	}
	if (shape == SHAPE_SEW_T_JUNCTION)
	{
		if (direction == WEST || direction == SOUTH || direction == EAST)
			return true;
		else
			return false;
	}
	if (shape == SHAPE_NSEW_CROSSROAD)
		return true;
}
char shapeGetMapChar(Shape shape)
{
	const int TUNNEL_SHAPES = 17;
	char shapes[TUNNEL_SHAPES];

	shapes[0] = 'O';
	shapes[1] = 'N';
	shapes[2] = 'S';
	shapes[3] = 'E';
	shapes[4] = 'W';
	shapes[5] = '|';
	shapes[6] = '-';
	shapes[7] = '\\';
	shapes[8] = '/';
	shapes[9] = '/';
	shapes[10] = '\\';
	shapes[11] = '>';
	shapes[12] = '<';
	shapes[13] = '^';
	shapes[14] = 'v';
	shapes[15] = '+';
	shapes[16] = ' ';

	if (shapeIsCavern(shape) == true)
	{
		if (shape % 2 == 0)
			return ':';
		else
			return '.';
	}
	else
		return shapes[shape];
}
Shape shapeCalculate(bool is_open_north, bool is_open_south, bool is_open_east, bool is_open_west)
{
	if (is_open_north == false && is_open_south == false && is_open_east == false && is_open_west == false)
		return SHAPE_BUBBLE;
	if (is_open_north == true && is_open_south == false && is_open_east == false && is_open_west == false)
		return SHAPE_N_DEAD_END;
	if (is_open_north == false && is_open_south == true && is_open_east == false && is_open_west == false)
		return SHAPE_S_DEAD_END;
	if (is_open_north == false && is_open_south == false && is_open_east == true && is_open_west == false)
		return SHAPE_E_DEAD_END;
	if (is_open_north == false && is_open_south == false && is_open_east == false && is_open_west == true)
		return SHAPE_W_DEAD_END;
	if (is_open_north == true && is_open_south == true && is_open_east == false && is_open_west == false)
		return SHAPE_NS_STRAIGHT;
	if (is_open_north == false && is_open_south == false && is_open_east == true && is_open_west == true)
		return SHAPE_EW_STRAIGHT;
	if (is_open_north == true && is_open_south == false && is_open_east == true && is_open_west == false)
		return SHAPE_NE_CORNER;
	if (is_open_north == true && is_open_south == false && is_open_east == false && is_open_west == true)
		return SHAPE_NW_CORNER;
	if (is_open_north == false && is_open_south == true && is_open_east == true && is_open_west == false)
		return SHAPE_SE_CORNER;
	if (is_open_north == false && is_open_south == true && is_open_east == false && is_open_west == true)
		return SHAPE_SW_CORNER;
	if (is_open_north == true && is_open_south == true && is_open_east == true && is_open_west == false)
		return SHAPE_NSE_T_JUNCTION;
	if (is_open_north == true && is_open_south == true && is_open_east == false && is_open_west == true)
		return SHAPE_NSW_T_JUNCTION;
	if (is_open_north == true && is_open_south == false && is_open_east == true && is_open_west == true)
		return SHAPE_NEW_T_JUNCTION;
	if (is_open_north == false && is_open_south == true && is_open_east == true && is_open_west == true)
		return SHAPE_SEW_T_JUNCTION;
	if (is_open_north == true && is_open_south == true && is_open_east == true && is_open_west == true)
		return SHAPE_NSEW_CROSSROAD;
}

bool shapeIsCavern(Shape shape)
{
	if (shape >= SHAPE_FIRST_CAVERN)
		return true;
	else
		return false;
}

unsigned int shapeGetCavernIndex(Shape shape)
{
	return shape - SHAPE_FIRST_CAVERN;
}

Shape shapeGetCavernShape(unsigned int cavern_index)
{
	return cavern_index + SHAPE_FIRST_CAVERN;
}