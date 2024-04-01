#pragma once
#include <vector>
#include <queue>
#include "Node.h"

class BFS
{
private:
	//ptr maze
	std::vector<std::vector<bool>> *Maze {nullptr};
	int row, colum;

	//ma tran xem da di qua
	std::vector<std::vector<bool>>* visited{ nullptr };

	//queue dung cho BFS
	std::queue<Node> *Q{nullptr};

public:
	//khoi tao maze, destructor
	BFS(std::vector<std::vector<bool>> &maze);
	virtual ~BFS();
	//methods
	bool is_inbound(const cord &pos) const;
	void get_cach(std::queue<Node>& Q, Node& current, std::vector<std::vector<bool>>& visited);
	bool Search(const cord &start, const cord &end);
	void print_maze(const std::vector<std::vector<bool>> *m, const cord &start, const cord &end) const;
};

