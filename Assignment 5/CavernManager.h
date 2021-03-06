#pragma once
#include "Shape.h"
#include "Cavern.h"

const unsigned int STARTING_CAPACITY = 4;

class CavernManager
{
public:
	// CavernManager
	//
	// Purpose: Initializes the properties of the cavern manager
	// Parameter(s):
	//  <1> param1: N/A
	// Precondition(s):
	//  <1>: N/A
	// Returns: N/A
	// Side effect: Initializes the properties of the cavern manager
	//
	CavernManager();

	CavernManager(const CavernManager& cavern_manager1);
	~CavernManager();
	CavernManager& operator= (const CavernManager& cavern_manager1);
	unsigned int getCapacity() const;

	// isEmpty
	//
	// Purpose: Checks if the cavern manager is empty
	// Parameter(s):
	//  <1> param1: N/A
	// Precondition(s):
	//  <1>: Invariant
	// Returns: True or False
	// Side effect: N/A
	//
	bool isEmpty() const;
	
	// getCount
	//
	// Purpose: Gets how many caverns are in the cavern manager
	// Parameter(s):
	//  <1> param1: N/A
	// Precondition(s):
	//  <1>: Invariant
	// Returns: How many caverns there are 
	// Side effect: N/A
	//
	unsigned int getCount() const;
	// get
	//
	// Purpose: Gets the cavern you are looking for
	// Parameter(s):
	//  <1> param1: The index for the Cavern array
	// Precondition(s):
	//  <1>: Invariant
	//  <2>: Index is between 0 and the max 
	// Returns: A cavern
	// Side effect: N/A
	//
	const Cavern& get(unsigned int index) const;
	// getBack
	//
	// Purpose: Gets the cavern that was most recently added
	// Parameter(s):
	//  <1> param1: N/A
	// Precondition(s):
	//  <1>: Invariant
	//  <2>: The cavern count is 0 or greater
	// Returns: A cavern
	// Side effect: N/A
	//
	const Cavern& getBack() const;
	// getBackShape
	//
	// Purpose: Gets the shape for the tunnel of the cavern that was most recently added
	// Parameter(s):
	//  <1> param1: N/A
	// Precondition(s):
	//  <1>: Invariant
	//  <2>: The cavern count is 0 or greater
	// Returns: A Shape 
	// Side effect: N/A
	//
	Shape getBackShape() const;
	// add
	//
	// Purpose: Adds a cavern to the array and increments the array by one
	// Parameter(s):
	//  <1> param1: The cavern you wish to add
	// Precondition(s):
	//  <1>: The cavern count is less than or equal to the max
	// Returns: N/A
	// Side effect: Adds a cavern to the array and increments the array by one
	//
	void add(const Cavern& cavern1);

private:
	Cavern* pcaverns;
	bool invariant() const;
	unsigned int Ccount = 0;
	unsigned int capacity = 0;
	void copy(const CavernManager& cavern_manager1);
	void expand();
};
