#include <iostream>
#include <vector>

using namespace std;

/*
Given a 2d grid map of '1's (land) and '0's (water), count the number of islands. An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.

Example 1:

Input: grid = [
  ["1","1","1","1","0"],
  ["1","1","0","1","0"],
  ["1","1","0","0","0"],
  ["0","0","0","0","0"]
]
Output: 1

Example 2:

Input: grid = [
  ["1","1","0","0","0"],
  ["1","1","0","0","0"],
  ["0","0","1","0","0"],
  ["0","0","0","1","1"]
]
Output: 3
*/

void dfs(vector<vector<char>>& grid, int i, int j)
{
    if (i < 0 || i >= grid.size() || j < 0 || j >= grid[i].size() || grid[i][j] == '0') {
        return;
    }
    grid[i][j] = '0';
        
    dfs(grid, i-1, j);
    dfs(grid, i+1, j);
    dfs(grid, i, j-1);
    dfs(grid, i, j+1);
}
    
int numIslands(vector<vector<char>>& grid)
{
    if (grid.size() == 0) {
        return 0;
    }
    int m = grid.size();
    int n = grid[0].size();
    int result = 0;
        
    for (int i=0; i<m; i++) {
        for (int j=0; j<n; j++) {
            if (grid[i][j] == '1') {
                dfs(grid, i, j);
                result++;
            }
        }
    }
        
    return result;
}

int main()
{
    return 0;
}