#include <iostream>
#include <vector>
#include <queue>

using namespace std;

/*
Given a matrix consists of 0 and 1, find the distance of the nearest 0 for each cell.

The distance between two adjacent cells is 1.

 

Example 1:

Input:
[[0,0,0],
 [0,1,0],
 [0,0,0]]

Output:
[[0,0,0],
 [0,1,0],
 [0,0,0]]
Example 2:

Input:
[[0,0,0],
 [0,1,0],
 [1,1,1]]

Output:
[[0,0,0],
 [0,1,0],
 [1,2,1]]
 

Note:

The number of elements of the given matrix will not exceed 10,000.
There are at least one 0 in the given matrix.
The cells are adjacent in only four directions: up, down, left and right.
*/

static bool isOutOfBounds(vector<vector<int>>& matrix, int x, int y)
{
    return (x < 0 || x >= matrix.size() || y < 0 || y >= matrix[x].size());
}

vector<vector<int>> updateMatrix(vector<vector<int>>& matrix)
{
    if (matrix.size() == 0) {
        return matrix;
    }
    int m = matrix.size();
    int n = matrix[0].size();

    vector<vector<int>> result(m, vector<int>(n, -1));
    typedef pair<int,int> pi;
    queue<pi> q;
    for (int i=0; i<m; i++) {
        for (int j=0; j<n; j++) {
            if (matrix[i][j] == 0) {
                result[i][j] = 0;
                q.push(make_pair(i, j));
            }
        }
    }

    while (!q.empty()) {
        auto front = q.front();
        q.pop();

        int dx[] = {-1, 1, 0, 0};
        int dy[] = {0, 0, -1, 1};

        for (int i=0; i<4; i++) {
            int x = front.first + dx[i];
            int y = front.second + dy[i];

            if (isOutOfBounds(matrix, x, y)) continue;

            auto neighbor = make_pair(x, y);
            if (result[x][y] == -1) {
                result[x][y] = 1 + result[front.first][front.second];
                q.push(neighbor);
            }
        }
    }
    return result;
}

int main()
{
    return 0;
}