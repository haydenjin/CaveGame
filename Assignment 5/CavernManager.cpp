#include "CavernManager.h"
#include <cassert>

CavernManager::CavernManager()
{
	capacity = STARTING_CAPACITY;
	pcaverns = new Cavern[capacity];
	Ccount = 0;
}

CavernManager::~CavernManager()
{
	assert(invariant());
	delete[] pcaverns;
}

CavernManager::CavernManager(const CavernManager& cavern_manager1)
{
	assert(cavern_manager1.invariant());
	copy(cavern_manager1);
	assert(invariant());
}

 CavernManager& CavernManager::operator= (const CavernManager& cavern_manager1)
{
	 assert(invariant());
	 assert(cavern_manager1.invariant());
	 if (&cavern_manager1 != this)
	 {
		 delete[] pcaverns;
		 copy(cavern_manager1);
	 }
	 return*this;
	 assert(invariant());
}

bool CavernManager::isEmpty() const
{
	assert(invariant());
	if (Ccount == 0)
		return true;
	else
		return false;
}

unsigned int CavernManager::getCount() const
{
	assert(invariant());
	return Ccount;
}

const Cavern& CavernManager::get(unsigned int index) const
{
	assert(invariant());
	assert(index >= 0);
	return pcaverns[index];
}

const Cavern& CavernManager::getBack() const
{
	assert(invariant());
	assert(Ccount >= 0);
	return pcaverns[Ccount - 1];
}

Shape CavernManager::getBackShape() const
{
	assert(invariant());
	assert(Ccount >= 0);
	return shapeGetCavernShape(Ccount - 1);
}

void CavernManager::add(const Cavern& cavern1)
{
	assert(invariant());
	if (Ccount == capacity)
	{
		expand();
	}
	pcaverns[Ccount] = cavern1;
	Ccount++;
	assert(invariant());
}

void CavernManager::copy(const CavernManager& cavern_manager1)
{
	Ccount = cavern_manager1.Ccount;
	capacity = cavern_manager1.capacity;
	pcaverns = new Cavern[capacity];
	for (int i = 0; i < Ccount; i++)
	{
		pcaverns[i] = cavern_manager1.pcaverns[i];
	}
}

void CavernManager:: expand()
{
	capacity = capacity * 2;
	Cavern* pnewcaverns = new Cavern[capacity];
	for (int i = 0; i < capacity / 2; i++)
	{
		pnewcaverns[i] = pcaverns[i];
	}
	delete[] pcaverns;
	pcaverns = pnewcaverns;
}

unsigned int CavernManager::getCapacity() const
{
	return capacity;
}

bool CavernManager::invariant() const
{
	if (pcaverns != NULL && capacity >= STARTING_CAPACITY && Ccount <= capacity)
		return true;
	else
		return false;
}