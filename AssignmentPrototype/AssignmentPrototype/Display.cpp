#include <Windows.h>
#include "Display.h"

//Output the grid to the screen.
void Display::displayForest(Cell* grid[21][21])
{
	HWND window = GetConsoleWindow();
	if (window != NULL)
	{
		MoveWindow(window, 0, 0, 800, 600, true); //Resize the window to a bigger size.
	}
	HANDLE hstdin = GetStdHandle(STD_INPUT_HANDLE);
	HANDLE hstdout = GetStdHandle(STD_OUTPUT_HANDLE);

	for (int y = 0; y < 21; y++)
	{
		for (int x = 0; x < 21; x++)
		{
			switch (grid[x][y]->icon())
			{
			case '^':
				SetConsoleTextAttribute(hstdout, 10); //Trees are green
				break;

			case 'X':
				SetConsoleTextAttribute(hstdout, 12); //Fires are red
				break;

			case '.':
				SetConsoleTextAttribute(hstdout, 15); //Borders are white
				break;
			case '~':
				SetConsoleTextAttribute(hstdout, 11); //Rivers are cyan
				break;
			}
			cout << grid[x][y]->icon();
		}
		cout << endl;
	}
}
void Display::displayInstructions(int Wind)
{
	cout << "Wind direction: "; //Let the user know which direction the wind is.
	switch (Wind)
	{
		case 0:
		cout << "No wind" << endl;
		break;

		case 1:
			cout << "North" << endl;
		break;

		case 2:
			cout << "South" << endl;
		break;

		case 3:
			cout << "West" << endl;
		break;

		case 4:
			cout << "East" << endl;
		break;	
	}

	cout << endl << "> Press Enter for time increment" << endl << "> Press x to start another fire" << endl << "> Press any other alphanumeric key to exit>" << endl;
}

void Display::clear() //Anti flicker console clear method
{
	COORD position;
	position.X = 0;
	position.Y = 0;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), position);
}
