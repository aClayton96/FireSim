#pragma once
#ifndef FOREST_H
#define FOREST_H

#include "Cell.h" 
#include <iostream>

using namespace std;

class Forest
{

public:
	//forestMap array
	Cell* forestMap[21][21];
	void InitializeMap();
};
#endif // !FOREST_H
