#pragma once
#include <iostream>
#include "Display.h"
#include <string>
#include "Random.h"
#include "Forest.h"
#include <list>

using namespace std;

class FireManager
{
private:
	//These functions are not accessed outside the class, so they can be made private
	bool SetFire(Tree*);
	bool PutOut(Tree*);
	bool CheckNeighbors(Cell* forest[21][21], int x, int y, int Wind);
	list<Tree*> CheckforFire(Cell* forest[21][21], int Wind);
	void Updatefire(Cell * forest[21][21], list<Tree*> list);
public:
	void FireStarter(Cell* forest[21][21]);
	void FireSpreader(Cell* forest[21][21]);
};