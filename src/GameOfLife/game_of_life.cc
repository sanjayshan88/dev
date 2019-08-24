#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

/* function to get the number of active neighbors
 */
int getNumNeighbors(vector<string> &grid, int row, int col, 
					int maxRows, int maxCols)
{
	int numNeighbors = 0;
	for (int i=row-1; i<row+2; i++)
	{
		if (i < 0 || i >= maxRows) continue;
		for (int j=col-1; j<col+2; j++)
		{
			if (j < 0 || j >= maxCols) continue;
			if (i == row && j == col) continue;

			if (grid[i][j] == 'X')
			{
				numNeighbors++;
			}
		}
	}
	// cout << "row: " << row << " col: " << col << " numNeighbors: " << numNeighbors << endl;
	return numNeighbors;
}

/* function to print a grid
 */
void printGrid(vector<string> &grid, int rows)
{

	for (int i=0; i<rows; i++)
	{
		cout << grid[i] << endl;
	}
}

int main()
{
	string fName;
	ifstream input;
	string line;

	cout << "Welcome to the Game of Life," << endl;
	cout << "a simulation of the lifecycle of a bacteria colony." << endl;
	cout << "Cells (X) live and die by the following rules:" << endl;
	cout << "- A cell with 1 or fewer neighbors dies." << endl;
	cout << "- Locations with 2 neighbors remain stable." << endl;
	cout << "- Locations with 3 neighbors will create life." << endl;
	cout << "- A cell with 4 or more neighbors dies." << endl;

	do 
	{
		cout << endl << "Grid input file name? ";
		cin >> fName;
		input.open(fName);
	} while (input.fail());

	// get rows
	int rows = 0;
	if (getline(input, line))
	{
		rows = stoi(line);
	}
	
	// get columns
	int cols = 0;
	if (getline(input, line))
	{
		cols = stoi(line);
	}
	vector<string> grid;

	int rowNum = 0;
	while(getline(input, line))
	{
		if (rowNum >= rows)
		{
			break;
		}

		grid.push_back(line);
		rowNum++;
	}
	printGrid(grid, rows);

	char input_char;
	while (1)
	{
		cout << "a)nimate, t)ick, q)uit? ";
		cin >> input_char;

		if (input_char == 'a' || input_char == 'A')
		{
			// TODO
			cout << "This option is not yet supported" << endl;
			continue;
		}
		else if (input_char == 't' || input_char == 'T')
		{
			
			vector<string> nextGenGrid;
			for (int i=0; i<rows; i++)
			{
				nextGenGrid.push_back("");
				for (int j=0; j<cols; j++)
				{
					int numNeighbors = getNumNeighbors(grid, i, j, rows, cols);
					if (numNeighbors <= 1 || numNeighbors >= 4)
					{
						nextGenGrid[i] += "-";
					}
					if (numNeighbors == 2)
					{
						nextGenGrid[i] += grid[i][j];
					}
					if (numNeighbors == 3)
					{
						nextGenGrid[i] += 'X';
					}
				}
			}

			printGrid(nextGenGrid, rows);
			grid = nextGenGrid;
			continue;
		}
		else if (input_char == 'q' || input_char == 'Q')
		{
			cout << "Have a nice Life!" << endl;
			return 0;
		}
		else
		{
			cout << "Invalid choice; please try again." << endl;
			continue;
		}
	}

	return 0;
}
