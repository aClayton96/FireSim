#pragma once
#ifndef CELL_H
#define CELL_H

class Cell
{
private: 
	int m_x; //The X and Y coordinate of the cell in our "grid"
	int m_y;
	char m_icon; //The icon of the cell
public: 
	
	int x(){ return m_x; }; //Getters 
	int y(){ return m_y; };
	char icon() { return m_icon; };

	void x(int x) { m_x = x; }; //Setters

	void y(int y) { m_y = y; };

	void icon(char icon) { m_icon = icon; };

	Cell(int x, int y, char icon); //Default constructor

};

class Border:public Cell //Border cell
{
private:
public:
	Border(int x, int y, char icon) : Cell(x, y, icon) {};
};

class Tree:public Cell //Tree cell
{
private:
	int m_life = 3; //The "life" of the tree
	bool m_onFire = false; 
	bool m_dead = false;
public:
	int life() { return m_life; }; //Getters
	bool onFire() { return m_onFire; };
	bool dead() { return m_dead; };

	//No need for setters as attributes are not modified outside the class

	Tree(int x, int y, char icon) : Cell(x, y, icon) {};
	void Burn();
	void Die();
};

class River:public Cell
{
private:
public:
	River(int x, int y, char icon) : Cell(x, y, icon) {};
};
#endif