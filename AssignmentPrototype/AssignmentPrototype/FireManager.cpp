#include "FireManager.h"

Display d;
RandomNum r;

void FireManager::FireStarter(Cell* forest[21][21])
{
	bool comp = false;
	//While the boolean is false, roll two random numbers for X and Y and see if we can start a fire at that grid square
	while (comp == false)
	{
		d.clear(); //Clear the console window

		// Select some coordinates to check.
		int rX = r.Random(3, 18);
		int rY = r.Random(3, 18);

		if (forest[rX][rY]->icon() == '^')
		{
			Tree* t = static_cast<Tree*>(forest[rX][rY]);
				//If the two coordinates match to a grid square where we can start a fire, set the bool to true
				t->Burn();				
				comp = true;
			}
		}
	}
void FireManager::FireSpreader(Cell* forest[21][21])
{	
	int Wind = r.Random(0, 4); //Choose a wind direction
	string input;
	bool redraw = true;
	// Start spreading the fire
	while (redraw == true)
	{
		d.clear();
		// Display the forest map
		d.displayForest(forest);
		//User input (Enter, X or any other)
		d.displayInstructions(Wind);
		
		getline(cin, input);
		if (input == "x") //The user wants to start another fire
		{
			FireStarter(forest);
		}
		else if (input != "") //If the user wants to quit
		{
			redraw = false;
		}
		else //If the user just presses enter
		{
			Updatefire(forest, CheckforFire(forest, Wind));
		}
	}
}

bool FireManager::CheckNeighbors(Cell* forest[21][21], int x, int y, int Wind) //Is there a cell nearby that is on fire
{
	//Cast our current cell as a tree
	Tree* t = static_cast<Tree*>(forest[x][y]);

	if ((x + 1 <= 21) && (x - 1 >= 0) && (y + 1 <= 21) && (y - 1 >= 0)) //Check there won't be an out of bounds when casting neighbors
	{
		//Cast all the neighbors as a tree
		Tree* tn = static_cast<Tree*>(forest[x][y - 1]);

		Tree* ts = static_cast<Tree*>(forest[x][y + 1]);

		Tree* te = static_cast<Tree*>(forest[x + 1][y]);

		Tree* tw = static_cast<Tree*>(forest[x - 1][y]);

		Tree* tne = static_cast<Tree*>(forest[x + 1][y - 1]);

		Tree* tnw = static_cast<Tree*>(forest[x - 1][y - 1]);

		Tree* tse = static_cast<Tree*>(forest[x + 1][y + 1]);

		Tree* tsw = static_cast<Tree*>(forest[x - 1][y + 1]);

		switch (Wind) //Which direction is the wind going? 
		{
		case 0: //No wind 
			if ((tn->onFire() == true || ts->onFire() == true || te->onFire() == true || tw->onFire() == true))
			{
				return true;
			}
			else
			{
				return false;
			}
			break;

		case 1: // Wind North
			if ((ts->onFire() == true) || (tse->onFire() == true) || (tsw->onFire() == true))
			{
				return true;
			}
			else
			{
				return false;
			}
			break;

		case 2: //Wind South
			if ((tn->onFire() == true) || (tne->onFire() == true) || (tnw->onFire() == true))
			{
				return true;
			}
			else
			{
				return false;
			}
			break;

		case 3: //Wind West
			if ((te->onFire() == true) || (tse->onFire() == true) || (tne->onFire() == true))
			{
				return true;
			}
			else
			{
				return false;
			}
			break;

		case 4: //Wind East
			if ((tw->onFire() == true) || (tsw->onFire() == true) || (tnw->onFire() == true))
			{
				return true;
			}
			else
			{
				return false;
			}
			break;
		}
	}
	else //If it's going to cause an out of bounds error don't start casting the neighbors
	{
		return false;
		cout << "Out of bounds error" << endl; //Shouldn't expect this to actually run, but better safe than sorry
	}
}


bool FireManager::SetFire(Tree* t)
	{
		int n = r.Random(1, 10); //Roll a number between 1 and 10
		if (n <= 3) //If it's less than 4, set fire to a tree
		{
			return true;
		}
		else
		{
			return false;
		}
	}

bool FireManager::PutOut(Tree* t)
	{
		if (t->life() <= 0 && t->onFire() != true) //If the tree is dead, we can put it out
		{
			return true;
		}
		else
		{
			return false;
		}
	}

list<Tree*> FireManager::CheckforFire(Cell* forest[21][21], int Wind)
{
	list<Tree*> TreeList;
	//for each cell in the forest
		for each (Cell* c in forest)
		{
			if (Tree* tree = static_cast<Tree*>(c)) //Can we cast the cell as a tree?
			{
				if (c->icon() == '^' || c->icon() == 'X') // Prevent a border cell from getting set on fire
				{
					//If the tree nearby is on fire, add it to the list of updateable trees
					if (CheckNeighbors(forest, c->x(), c->y(), Wind))
					{
						TreeList.push_back(tree);
					}
					//If the tree is already on fire, add it to a list of updateable trees.
					else if (tree->onFire() == true)
					{
						TreeList.push_back(tree);
					}
				}
			}
		}
	return TreeList; //Return the list of trees
}

void FireManager::Updatefire(Cell* forest[21][21], list<Tree*> list)
{
	for each (Tree* t in list)
	{
		if (SetFire(t) == true) //If it can be set on fire and the random chance is correct, set it on fire
		{
			t->Burn();
		}
		else if (t->onFire() == true) //If it's already on fire, go through the death function (-1 from life, if no life set as dead)
		{
			t->Die();
		}
	} 
}