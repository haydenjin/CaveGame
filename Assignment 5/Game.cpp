#include "Game.h"
#include <cassert>

Game::Game(const std::string& filename)
{
	char raw[MAP_SIZE_SOUTH][MAP_SIZE_EAST];
	rawMapLoad(raw, filename);
	rawMapPrint(raw);
	cout << endl << endl;
	for (int i = 0; i < MAP_SIZE_SOUTH; i++)
	{
		for (int j = 0; j < MAP_SIZE_EAST; j++)
		{
			if (m2.isCavern(toPosition(i, j)) == false)
			{
				if (rawMapIsCavern(raw, i, j) == false)
				{
					m2.setAt(toPosition(i, j), rawMapCalculateShape(raw, i, j));
				}
				else
				{
					Cavern c1 = rawMapCalculateCavern(raw, i, j);
					m2.setRectangle(toPosition(i, j), c1.getSouthSize(), c1.getEastSize(), shapeGetCavernShape(cm2.getCount()));
					cm2.add(c1);
				}
			}
		}
	}
	m2.printMap();
	pp = rawMapGetPlayerStart(raw);
}

void Game::printDescription() const
{
	assert(invariant());
	if (m2.isCavern(pp) == true)
	{
		cm2.get(m2.getCavernIndex(pp)).print();
	}
	if (m2.isCavern(pp) == false)
	{
		m2.printDescription(pp);
	}
}

void Game::move(Direction direction)
{
	assert(direction < DIRECTION_COUNT);
	if (canMakeFirstMove(direction) == true)
	{
		makeFirstMove(direction);
		followTunnel(direction);
	}
	else
		cout << "There is no way to go in that direction." << endl;
}

bool Game::invariant() const
{
	if (isInMap(pp) == true && m2.isOpen(pp) == true)
		return true;
	else
		return false;
}

bool Game::canMakeFirstMove(Direction direction) const
{
	assert(invariant());
	if (m2.isCavern(pp) == true)
	{
		if (cm2.get(m2.getCavernIndex(pp)).isExit(direction) == true)
			return true;
		else
			return false;
	}
	if (m2.isCavern(pp) == false)
	{
		if (m2.isTunnelDirection(pp, direction) == true)
			return true;
		else
			return false;
	}
}

void Game::makeFirstMove(Direction direction)
{
	assert(invariant());
	assert(canMakeFirstMove(direction) == true);
	if (m2.isCavern(pp) == true)
	{
		pp = cm2.get(m2.getCavernIndex(pp)).getExitPosition(direction);
		cout << "You leave the cavern and start walking..." << endl;
	}
	if (m2.isCavern(pp) == false)
	{
		pp = moveDirection(pp, direction);
		cout << "You start walking..." << endl;
	}
}

void Game::followTunnel(Direction direction)
{
	assert(invariant());
	cout << "10 ft..." << endl;
	for (int i = 2; m2.isTunnelStraight(pp); i++)
	{
		pp = moveDirection(pp, direction);
		cout << i << "0 ft..." << endl;
	}
}
