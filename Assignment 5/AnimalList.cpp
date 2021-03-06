#include "AnimalList.h"

AnimalList::AnimalList()
{
	head = nullptr;
	assert(invariant());
}

void AnimalList::deleteLinkedList(Element* p_list_head) const
{
	assert(invariant());
	while (p_list_head != nullptr)
	{
		Element* pTemp = p_list_head;
		p_list_head = p_list_head->next;
		delete pTemp;
	}
}

AnimalList::~AnimalList()
{
	assert(invariant());
	deleteLinkedList(head);
}

Element* AnimalList:: copyLinkedList(const Element* p_old_head) const
{
	if (p_old_head == nullptr)
	{
		return nullptr;
	}
	Element* nhead = new Element;
	nhead->snumber = p_old_head->snumber;
	nhead->acount = p_old_head->acount;
	const Element* p1 = p_old_head;
	Element* p2 = nhead;
	while (p1->next != nullptr)
	{
		p2->next = new Element;
		p1 = p1->next;
		p2 = p2->next;
		p2->acount = p1->acount;
		p2->snumber = p1->snumber;
	}
	p2->next = nullptr;
	return nhead;
}

AnimalList:: AnimalList(const AnimalList& animal_list1)
{
	head = copyLinkedList(animal_list1.head);
	assert(invariant());
}

AnimalList& AnimalList::operator= (const AnimalList& animal_list1)
{
	assert(invariant());
	if (&animal_list1 != this)
	{
		deleteLinkedList(head);
		head = copyLinkedList(animal_list1.head);
	}
	assert(invariant());
	return *this;
}

void AnimalList:: print() const
{
	assert(invariant());
	Element* p = head;
	
	while (p != nullptr)
	{
		if(p->snumber == 0)
			cout << "There is a colony of bats here." << endl;
		if (p->snumber == 1 && p->acount == 1)
			cout << "There is a cave salamander here." << endl;
		if (p->snumber == 1 && p->acount > 1)
			cout << "There are " << p->acount << " cave salamanders here." << endl;
		if (p->snumber == 2 && p->acount == 1)
			cout << "There is a cave dwelling ratsnake here." << endl;
		if (p->snumber == 2 && p->acount > 1)
			cout << "There are " << p->acount << " cave dwelling ratsnakes here." << endl;
		if (p->snumber == 3 && p->acount == 1)
			cout << "There is a arachnocampa here." << endl;
		if (p->snumber == 3 && p->acount > 1)
			cout << "There are " << p->acount << " arachnocampas here." << endl;
		if (p->snumber == 4 && p->acount == 1)
			cout << "There is a Nelson cave spider here." << endl;
		if (p->snumber == 4 && p->acount > 1)
			cout << "There are " << p->acount << " Nelson cave spiders here." << endl;
		if (p->snumber == 5 && p->acount == 1)
			cout << "There is a trogloraptor here." << endl;
		if (p->snumber == 5 && p->acount > 1)
			cout << "There are " << p->acount << " trogloraptors here." << endl;
		if (p->snumber == 6 && p->acount == 1)
			cout << "There is a Kaua'i cave wolf spider here." << endl;
		if (p->snumber == 6 && p->acount > 1)
			cout << "There are " << p->acount << " Kaua'i cave wolf spiders here." << endl;
		if (p->snumber == 7 && p->acount == 1)
			cout << "There is a Kaua'i cave amphipod here." << endl;
		if (p->snumber == 7 && p->acount > 1)
			cout << "There are " << p->acount << " Kaua'i cave amphipods here." << endl;
		if (p->snumber == 8 && p->acount == 1)
			cout << "There is a dragon millipede here." << endl;
		if (p->snumber == 8 && p->acount > 1)
			cout << "There are " << p->acount << " dragon millipedes here." << endl;
		if (p->snumber == 9 && p->acount == 1)
			cout << "There is a titanophyllum here." << endl;
		if (p->snumber == 9 && p->acount > 1)
			cout << "There are " << p->acount << " titanophyllums here." << endl;
		if (p->snumber == 10 && p->acount == 1)
			cout << "There is a cyber-centipede here." << endl;
		if (p->snumber == 10 && p->acount > 1)
			cout << "There are " << p->acount << " cyber-centipedes here." << endl;
		if (p->snumber == 11 && p->acount == 1)
			cout << "There is a blind tetra here." << endl;
		if (p->snumber == 11 && p->acount > 1)
			cout << "There are " << p->acount << " blind tetras here." << endl;
		if (p->snumber == 12 && p->acount == 1)
			cout << "There is a Congo blind barb here." << endl;
		if (p->snumber == 12 && p->acount > 1)
			cout << "There are " << p->acount << " Congo blind barbs here." << endl;
		if (p->snumber == 13 && p->acount == 1)
			cout << "There is a phantom blindcat here." << endl;
		if (p->snumber == 13 && p->acount > 1)
			cout << "There are " << p->acount << " phantom blindcats here." << endl;
		if (p->snumber == 14 && p->acount == 1)
			cout << "There is a toothless blindcat here." << endl;
		if (p->snumber == 14 && p->acount > 1)
			cout << "There are " << p->acount << " toothless blindcats here." << endl;
		if (p->snumber == 15 && p->acount == 1)
			cout << "There is a blind cave loach here." << endl;
		if (p->snumber == 15 && p->acount > 1)
			cout << "There are " << p->acount << " blind cave loachs here." << endl;
		if (p->snumber == 16 && p->acount == 1)
			cout << "There is a cave molly here." << endl;
		if (p->snumber == 16 && p->acount > 1)
			cout << "There are " << p->acount << " cave mollys here." << endl;
		if (p->snumber == 17 && p->acount == 1)
			cout << "There is a Cuban cusk-eel here." << endl;
		if (p->snumber == 17 && p->acount > 1)
			cout << "There are " << p->acount << " Cuban cusk-eels here." << endl;
		if (p->snumber == 18 && p->acount == 1)
			cout << "There is a blind cave eel here." << endl;
		if (p->snumber == 18 && p->acount > 1)
			cout << "There are " << p->acount << " blind cave eels here." << endl;
		if (p->snumber == 19 && p->acount == 1)
			cout << "There is a grotto sculpin here." << endl;
		if (p->snumber == 19 && p->acount > 1)
			cout << "There are " << p->acount << " grotto sculpins here." << endl;
		if (p->snumber == 20 && p->acount == 1)
			cout << "There is a Mexican blind brotula here." << endl;
		if (p->snumber == 20 && p->acount > 1)
			cout << "There are " << p->acount << " Mexican blind brotulas here." << endl;
		p = p->next;
	}
}

void AnimalList:: add(unsigned int species_number1)
{
	assert(invariant());
	assert(species_number1 >= 0 && species_number1 < 21);
	Element* current = head;
	if (head == nullptr)
	{
		addStart(species_number1);
	}
	else if (species_number1 < current->snumber)
	{
		addStart(species_number1);
	}
	else
	{
		Element* prev = current;
		while (current != nullptr && species_number1 > current->snumber)
		{
			prev = current;
			current = current->next;
		}
		if (current != nullptr && species_number1 == current->snumber)
		{
			current->acount = (current->acount + 1);
		}
		else if(prev->next == nullptr)
		{
			addEnd(species_number1);
		}
		else
		{
			insert(species_number1);
		}
	}
	assert(invariant());
}
void AnimalList::addStart(unsigned int species_number1)
{
	assert(invariant());
	assert(species_number1 >= 0 && species_number1 < 21);
	Element* newNode = new Element;
	newNode->snumber = species_number1;
	newNode->acount = 1;
	if (head == nullptr)
	{
		newNode->next = nullptr;
		head = newNode;
	}
	else
	{
		newNode->next = head;
		head = newNode;
	}
	assert(invariant());
}

void AnimalList::addEnd(unsigned int species_number1)
{
	assert(invariant());
	assert(species_number1 >= 0 && species_number1 < 21);
	Element* newNode = new Element;
	newNode->snumber = species_number1;
	newNode->acount = 1;
	newNode->next = nullptr;
	Element* p = head;
	while (p->next != nullptr)
	{
		p = p->next;
	}
	p->next = newNode;
	assert(invariant());
}

void AnimalList::insert(unsigned int species_number1)
{
	assert(invariant());
	assert(species_number1 >= 0 && species_number1 < 21);
	Element* newNode = new Element;
	Element* prev = head;
	newNode->snumber = species_number1;
	newNode->acount = 1;
	newNode->next = nullptr;
	Element* p = head;
	while (p->snumber < species_number1)
	{
		prev = p;
		p = p->next;
	}
	prev->next = newNode;
	newNode->next = p;
	assert(invariant());
}

bool AnimalList::invariant() const
{
	Element* p = head;
	while (p != nullptr)
	{
		if (p->acount < 1)
			return false;
		if (p->snumber > ANIMAL_KINDS)
			return false;
		p = p->next;
	}
	return true;
}