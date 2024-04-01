// Maze.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include "BFS.h"

using namespace std;

// Maze mau
/*
//COLUM   0  1  2  3  4  5  6  7  8  9   ROW
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },//0
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },//1
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },//2
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },//3
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },//4
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },//5
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },//6
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },//7
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },//8
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 } //9

//COLUM  0  1  2  3  4  5  6  7  8  9   ROW
		{ 0, 1, 1, 1, 1, 1, 0, 0, 0, 0 },//0
		{ 0, 1, 0, 0, 0, 0, 0, 0, 1, 1 },//1
		{ 0, 1, 0, 0, 0, 1, 1, 1, 1, 0 },//2
		{ 0, 1, 0, 0, 0, 1, 0, 0, 0, 0 },//3
		{ 0, 1, 0, 0, 0, 1, 0, 0, 0, 0 },//4
		{ 1, 1, 0, 1, 1, 1, 1, 1, 0, 0 },//5
		{ 0, 1, 0, 0, 0, 1, 1, 1, 0, 0 },//6
		{ 0, 1, 1, 1, 1, 1, 1, 1, 0, 0 },//7
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },//8
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 } //9

//COLUM  0  1  2  3  4  5  6  7  8  9  ROW
	   { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },//0
	   { 0, 1, 0, 0, 1, 1, 1, 1, 1, 1 },//1
	   { 0, 1, 0, 0, 1, 0, 0, 0, 0, 1 },//2
	   { 0, 1, 1, 1, 1, 0, 1, 1, 0, 1 },//3
	   { 1, 0, 0, 0, 0, 0, 1, 1, 1, 1 },//4
	   { 1, 0, 0, 1, 0, 1, 1, 0, 0, 1 },//5
	   { 1, 1, 1, 1, 0, 0, 1, 1, 0, 1 },//6
	   { 0, 1, 0, 1, 0, 1, 1, 0, 1, 1 },//7
	   { 0, 1, 0, 0, 0, 0, 0, 0, 0, 1 },//8
	   { 0, 1, 1, 1, 1, 1, 1, 1, 1, 1 } //9
*/





int main()
{
	
	vector<vector<bool>> Maze	
	{
		 //COLUM  0  1  2  3  4  5  6  7  8  9   ROW
				{ 0, 1, 1, 1, 1, 1, 0, 0, 0, 0 },//0
				{ 0, 1, 0, 0, 0, 0, 0, 0, 1, 1 },//1
				{ 0, 1, 0, 0, 0, 1, 1, 1, 1, 0 },//2
				{ 0, 1, 0, 0, 0, 1, 0, 0, 0, 0 },//3
				{ 0, 1, 0, 0, 0, 1, 0, 0, 0, 0 },//4
				{ 1, 1, 0, 1, 1, 1, 1, 1, 0, 0 },//5
				{ 0, 1, 0, 0, 0, 1, 1, 1, 0, 0 },//6
				{ 0, 1, 1, 1, 1, 1, 1, 1, 0, 0 },//7
				{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },//8
				{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 } //9
	};

	// cord ___ ( ROW , COLUM )
	cord start(0,1);
	cord end(7, 7);

	BFS path(Maze);

	if (path.Search(start, end))
	{
		cout << "Co the di toi\n";
	}
	else
	{
		cout << "khong the di toi\n";
	}

	

	return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
