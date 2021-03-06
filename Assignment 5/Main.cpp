//Hayden Jin
//200406675
//Nov 16 2019

#include "MapSize.h"
#include "Shape.h"
#include "Position.h"
#include "Cavern.h"
#include <iostream>
#include <cstdlib>
#include "Game.h"
using namespace std;

int main()
{
	Game G("map5.txt");
	cout << endl << endl;
	G.printDescription();
	char direc = ' ';
	while (direc != 'q')
	{
		cout << "Next? ";
		cin >> direc;
		cout << endl;
		if (direc == 'n')
		{
			G.move(NORTH);
		}
		if (direc == 's')
		{
			G.move(SOUTH);
		}
		if (direc == 'e')
		{
			G.move(EAST);
		}
		if (direc == 'w')
		{
			G.move(WEST);
		}
		if (direc == ' ')
			;
		G.printDescription();
	}

}