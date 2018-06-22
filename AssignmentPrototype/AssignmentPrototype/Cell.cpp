#include "Cell.h"
#include <iostream>

using namespace std;

Cell::Cell(int in_x, int in_y, char in_icon)
{
	m_x = in_x;
	m_y = in_y;
	m_icon = in_icon;
}

void Tree::Burn() //Set the onFire state to true and change the icon to fire
{
		m_onFire = true; 
		icon('X');
}
void Tree::Die() //Take 1 from life, or if it has no life, set it to dead and an empty icon.
{
	if ((m_onFire == true) && (m_dead != true))
	{
		m_life = m_life - 1;
		if (m_life <= 0)
		{
			m_dead = true;
			m_onFire = false;
			icon(' ');
		}
	}
}
