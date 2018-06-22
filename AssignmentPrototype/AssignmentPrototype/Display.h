#ifndef DISPLAY_H
#define DISPLAY_H

#include <iostream>
#include <cstring>
#include "Forest.h"
#include <Windows.h>

using namespace std;

class Display 
{
public:
	void displayForest(Cell* grid[21][21]);
	void displayInstructions(int Wind);
	void clear();

};

#endif