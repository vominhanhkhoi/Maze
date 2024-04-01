#include "BFS.h"


BFS::BFS(std::vector<std::vector<bool>> &maze)
{
	//khoi tao gia tri bound
	colum = static_cast<int>(maze.at(0).size());
	row = static_cast<int>(maze.size());

	//lay dia chi Maze ngoai main
	Maze = {&maze};

	//khoi tao ma tran danh dau da di qua(visited)
	visited = new std::vector<std::vector<bool>>{ maze };
	for (auto& R : *visited)
	{
		for (int i = 0; i < colum; i++)
		{
			R.at(i) = false;
		}
	}
	
	//khoi tao queue cho BFS
	Q = new std::queue<Node>{};

}

BFS::~BFS()
{
	//delete Maze; // pointer chi toi maze trong main, xoa = crash (something something heap pointer);

	//fixed
	Maze = nullptr;
	delete Maze;
	delete visited;
	delete Q;

}

bool BFS::is_inbound(const cord &pos) const
{
	if (pos.r >= 0 && pos.r < row &&
		pos.c >= 0 && pos.c < colum)
	{
		return true;
	}
	else
	{
	 return 0;
	}
}
 
//function ho tro search, push cac canh xung quanh Node hien tai vao queue + danh dau visited
void BFS::get_cach(std::queue<Node>& Q, Node& current, std::vector<std::vector<bool>> &visited)
{

	int X[] = { -1, 0, 0, 1 };
	int Y[] = { 0, -1, 1, 0 };

	for (int i = 0; i < 4; i++)
	{
		Node cach{cord{current.pos.r + X[i],current.pos.c + Y[i]}};

		//   kiem tra khong ngoai bien  ||    kiem tra co the di qua          ||   kiem tra da di qua chua
		if (is_inbound(cach.get_cord()) && (*Maze).at(cach.pos.r).at(cach.pos.c) && !visited.at(cach.pos.r).at(cach.pos.c))
		{
			visited.at(cach.pos.r).at(cach.pos.c) = true;
			Q.push(cach);
		}
	}
}

bool BFS::Search(const cord &start,const cord &end)
{
	//kiem tra start va end hop le
	if (!is_inbound(start) || !is_inbound(end)
		|| !(*Maze).at(start.r).at(start.c)
		|| !(*Maze).at(end.r).at(end.c)
		)
	{
		std::cout << "start hoac end khong hop le!\n";
		return false;
	}

	



	//khoi tao diem xuat phat 
	Node source{ start };
	(*visited).at(source.pos.r).at(source.pos.c) = true;
	(*Q).push(source);

	//thuat toan BFS

	while (!(*Q).empty())
	{

		Node current = (*Q).front();
		(*Q).pop();

		if (current.pos.r == end.r && current.pos.c == end.c)
		{
			std::cout << "Real map\n";
			print_maze(Maze, start, end);
			
			return 1;
		}

		get_cach((*Q), current, (*visited)); //push cac canh xung quanh Node hien tai vao queue + danh dau visited
		
		print_maze(visited, start, end);
	}
	
	std::cout << "final map\n";
	print_maze(Maze, start, end);
	return false;
}

void BFS::print_maze(const std::vector<std::vector<bool>> *m,const cord &start,const cord &end) const
{
	std::cout << "==============================\n";
	std::cout << " 0  1  2  3  4  5  6  7  8  9\n";
	for (int i=0;i<row;i++)
	{
		for (int j = 0; j < colum; j++)
		{
			if ((*m).at(i).at(j) == true)
			{
				if(i == start.r && j == start.c)
				{
					std::cout << " S ";
				}
				else if (i == end.r && j == end.c)
				{
					std::cout << " E ";
				}
				else
				{
					std::cout << " * ";
				}
			}
			else
			{
				std::cout << "   ";
			}
		}
		std::cout << i << "\n";
	}
	std::cout << "==============================\n";
	

}
