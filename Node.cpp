#include "Node.h"

Node::Node(cord POS)
	:pos{ POS }
{
}

Node::~Node()
{
}

void Node::print_cord() const
{
	std::cout << "R: " << pos.r << " C: " << pos.c << std::endl;;
}

cord Node::get_cord() const
{
	return pos;
}


