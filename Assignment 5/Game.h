#pragma once
#include "Map.h"
#include "CavernManager.h"
#include "RawMap.h"
#include <cstring>
#include <iostream>

class Game
{
public:
	Game(const std::string& filename);
	void printDescription() const;
	void move(Direction direction);

private:
	Map m2;
	CavernManager cm2;
	Position pp;
	bool invariant() const;
	bool canMakeFirstMove(Direction direction) const;
	void makeFirstMove(Direction direction);
	void followTunnel(Direction direction);
};
