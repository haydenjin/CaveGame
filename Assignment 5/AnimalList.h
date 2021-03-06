#pragma once
#include "SpeciesCount.h"
#include <iostream>
#include <cassert>
using namespace std;

struct Element
{
	unsigned int snumber;
	unsigned int acount;
	Element* next;
};

class AnimalList
{
public:
	AnimalList();
	AnimalList(const AnimalList& animal_list1);
	~AnimalList();
	AnimalList& operator= (const AnimalList& animal_list1);
	void print() const;
	void add(unsigned int species_number1);
private:
	Element* copyLinkedList(const Element* p_old_head) const;
	void deleteLinkedList(Element* p_list_head) const;
	bool invariant() const;
	void addStart(unsigned int species_number1);
	void addEnd(unsigned int species_number1);
	void insert(unsigned int species_number1);
	Element* head;
};