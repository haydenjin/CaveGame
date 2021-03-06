#pragma once
#include "MapSize.h"
#include "Shape.h"
#include "Position.h"

class Map {
public:
	// Map
	//
	// Purpose: Initializes the properties of the cavern
	// Parameter(s):
	//  <1> param1: N/A
	// Precondition(s):
	//  <1>: N/A
	// Returns: N/A
	// Side effect: Initializes the properties of the cavern
	//
	Map();

	// printMap
	//
	// Purpose: Prints the map
	// Parameter(s):
	//  <1> param1: N/A
	// Precondition(s):
	//  <1>: N/A
	// Returns: N/A
	// Side effect: Prints the map
	//
	void printMap() const;

	// isOpen
	//
	// Purpose: Checks if the map is open at that location
	// Parameter(s):
	//  <1> param1: A position
	// Precondition(s):
	//  <1>: The position is in the map
	// Returns: N/A
	// Side effect: returns true or false
	//
	bool isOpen(const Position& pos) const;

	// isTunnel
	//
	// Purpose: Checks if the map is a tunnel at that location
	// Parameter(s):
	//  <1> param1: A position
	// Precondition(s):
	//  <1>: The position is in the map
	// Returns: N/A
	// Side effect: returns true or false
	//
	bool isTunnel(const Position& pos) const;

	// isCavern
	//
	// Purpose: Checks if the map is a cavern at that location
	// Parameter(s):
	//  <1> param1: A position
	// Precondition(s):
	//  <1>: The position is in the map
	// Returns: N/A
	// Side effect: returns true or false
	//
	bool isCavern(const Position& pos) const;

	// getCavernIndex
	//
	// Purpose: Gets the cavern that you are looking for 
	// Parameter(s):
	//  <1> param1: A position
	// Precondition(s):
	//  <1>: The position is in the map
	//  <2>: The position is a cavern
	// Returns: the number that the cavern is in the array
	// Side effect: N/A
	//
	unsigned int getCavernIndex(const Position& pos) const;

	// printDescription
	//
	// Purpose: Tells the user their position and what they can do
	// Parameter(s):
	//  <1> param1: A position
	// Precondition(s):
	//  <1>: The position is in the map
	//  <2>: The position is not a cavern
	// Returns: N/A
	// Side effect: prints where the user is and what they are able to do
	//
	void printDescription(const Position& pos) const;

	// setAt
	//
	// Purpose: Sets the position to a shape
	// Parameter(s):
	//  <1> param1: A position
	//  <2> param1: A shape
	// Precondition(s):
	//  <1>: N/A
	// Returns: N/A
	// Side effect: Sets the position to a shape
	//
	void setAt(const Position& pos, Shape shape);

	// setRectangle
	//
	// Purpose: Sets portions of the map
	// Parameter(s):
	//  <1> param1: The minimum position
	//  <2> param1: south size of the area
	//  <3> param1: east size of the area
	//  <4> param1: A shape
	// Precondition(s):
	//  <1>: south size is bigger or equal to 0
	//  <2>: east size is bigger or equal to 0
	//  <3>: the area is in the map
	// Returns: N/A
	// Side effect: N/A
	//
	void setRectangle(const Position& pos_min, int south_size, int east_size, Shape shape);

	// isTunnelStraight
	//
	// Purpose: Sees if the tunnel is straight 
	// Parameter(s):
	//  <1> param1: A position
	// Precondition(s):
	//  <1>: N/A
	// Returns: true or false
	// Side effect: N/A
	//
	bool isTunnelStraight(const Position& pos)const;

	// isTunnelDirection
	//
	// Purpose: Sees which directions you can go 
	// Parameter(s):
	//  <1> param1: A position
	//  <2> param1: A direction
	// Precondition(s):
	//  <1>: The position is in the map
	//  <2>: Direction has to be <= direction count
	// Returns: true or false
	// Side effect: N/A
	//
	bool isTunnelDirection(const Position& pos, Direction direction) const;

	// getPlayerStart
	//
	// Purpose: Gets the starting position of the player 
	// Parameter(s):
	//  <1> param1: N/A
	// Precondition(s):
	//  <1>: N/A
	// Returns: The position
	// Side effect: N/A
	//
	Position getPlayerStart() const;

	// setPlayerStart
	//
	// Purpose: Sets the starting position of the player 
	// Parameter(s):
	//  <1> param1: The starting position
	// Precondition(s):
	//  <1>: The position is in the map
	// Returns: N/A
	// Side effect: Sets the starting position of the player 
	//
	void setPlayerStart(const Position& start1);

private:
	Position start;
	Shape map[MAP_SIZE_SOUTH][MAP_SIZE_EAST];
	Shape getAt(const Position& pos, Shape shape);
};

