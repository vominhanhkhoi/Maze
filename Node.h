#pragma once
#include <iostream>

struct cord
{
	//R = row = hang
	//C = colum = cot
	int r,c;
	

	cord(int R, int C) :r{ R }, c{ C }
	{
	};
};

class Node
{
public:
	cord pos;
	
	//consturctor,destructor
	Node(cord POS);
	virtual ~Node();
	//methods
	void print_cord() const;
	cord get_cord() const;


};

