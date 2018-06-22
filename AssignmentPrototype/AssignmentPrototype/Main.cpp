#include <iostream>
#include <cstdlib>
#include <string>
#include <fstream>
#include "Display.h"
#include "Forest.h"
#include "FireManager.h"

using namespace std;

int main(void)
{
		
		Forest f; //Create a new forest
		
		FireManager fi; //Create a new fire
		
		f.InitializeMap(); //Start up the map
		
		fi.FireStarter(f.forestMap); //Pass the map to the firestarting function
		
		fi.FireSpreader(f.forestMap); //Pass the map to the firespreading function
}