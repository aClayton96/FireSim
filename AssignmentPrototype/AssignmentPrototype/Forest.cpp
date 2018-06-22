#include "Forest.h"
#include "Random.h"

RandomNum random;

void Forest::InitializeMap()
{
	for (int y = 0; y < 21; y++)
	{
		for (int x = 0; x < 21; x++)
		{
			if (y == 0 || y == 20)
			{
				Border* c = new Border(x, y, '.');
				forestMap[x][y] = c;  // North and south boundary layers
			}
			else if (x == 0 || x == 20)
			{
				Border* c = new Border(x, y, '.');
				forestMap[x][y] = c;  // East and west boundary layers
			}
			else
			{
				Tree* t = new Tree(x, y, '^');
				forestMap[x][y] = t;  // Everything else is a tree
			}
		}
	}
	//Select an X and Y value to start our river from
	int randomX = random.Random(3, 18);
	int randomY = random.Random(3, 18);
	//spread the river
	for (int x = 0; x < 12; x++)
	{
		if (forestMap[randomX][randomY]->icon() != '.') //Don't make border cells into river cells
		{
			River* r = new River(randomX, randomY, '~'); //Create a new instance of river
			forestMap[randomX][randomY] = r; //Set our current cell as a river
			
			int YN = random.Random(1, 4); //Random 1 to 4
			switch (YN)
			{
			case 1: //The river goes along 1 cell
				randomY++;
				break;
			case 2: //The river goes back 1 cell
				randomY--;
				break;
			}
			randomX++;
		}
	}
}
	
	
	
