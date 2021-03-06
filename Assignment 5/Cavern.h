#pragma once
#include "Position.h"
#include "AnimalList.h"
const int CAVERN_SIZE_MIN = 2;

class Cavern 
{
public:

	// Cavern (default)
	//
	// Purpose: Initializes the properties of the cavern
	// Parameter(s):
	//  <1> param1: N/A
	// Precondition(s):
	//  <1>: N/A
	// Returns: N/A
	// Side effect: N/A
	//
	Cavern();

	// Cavern
	//
	// Purpose: Initializes the properties of the cavern
	// Parameter(s):
	//  <1> param2: Southsize of the cavern
	//  <2> param3: Eastsize of the cavern
	// Precondition(s):
	//  <1>: south and east sizes have to be bigger than CAVERN_SIZE_MIN
	// Returns: N/A
	// Side effect: N/A
	//
	Cavern(int south_size1, int east_size1);


	// getSouthSize
	//
	// Purpose: gets the south size of the cavern
	// Parameter(s):
	//  <1> param1: N/A
	// Precondition(s):
	//  <1>: N/A
	// Returns: south size of the cavern
	// Side effect: N/A
	//
	int getSouthSize() const;


	// getEastSize
	//
	// Purpose: gets the east size of the cavern
	// Parameter(s):
	//  <1> param1: N/A
	// Precondition(s):
	//  <1>: N/A
	// Returns: east size of the cavern
	// Side effect: N/A
	//
	int getEastSize() const;


	// isExit
	//
	// Purpose: finds if there is a exit in any of the directions 
	// Parameter(s):
	//  <1> param2: A particular direction 
	// Precondition(s):
	//  <1>: direction must be less than DIRECTION_COUNT
	// Returns: yes or no
	// Side effect: N/A
	//
	bool isExit(Direction direction) const;


	// getExitPosition
	//
	// Purpose: returns the position of the exit
	// Parameter(s):
	//  <1> param2: A particular direction 
	// Precondition(s):
	//  <1>: direction must be less than DIRECTION_COUNT 
	//  <2>: there is an exit in that direction
	// Returns: a position
	// Side effect: N/A
	//
	Position getExitPosition(Direction direction) const;


	// addExit
	//
	// Purpose: adds an exit to the cavern for a location without one 
	// Parameter(s):
	//  <1> param2: A particular direction 
	//  <2> param3: The position of the exit 
	// Precondition(s):
	//  <1>: direction must be less than DIRECTION_COUNT 
	//  <2>: there is not already an exit in that direction
	// Returns: N/A
	// Side effect: N/A
	//
	void addExit(Direction direction, const Position& position);


	// print
	//
	// Purpose: prints the cavern 
	// Parameter(s):
	//  <1> param1: N/A
	// Precondition(s):
	//  <1>: N/A
	// Returns: N/A
	// Side effect: N/A
	//
	void print() const;

	void addAnimal(unsigned int species_number);
private:
	int south;
	int east;
	bool exitOrNot[4];
	Position exitLocation[4];
	AnimalList animal;
	bool invariant() const;
};