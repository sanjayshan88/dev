#include <iostream>
#include <vector>

using namespace std;

/*
Given a 2D board containing 'X' and 'O' (the letter O), capture all regions surrounded by 'X'.

A region is captured by flipping all 'O's into 'X's in that surrounded region.

Example:

X X X X
X O O X
X X O X
X O X X
After running your function, the board should be:

X X X X
X X X X
X X X X
X O X X
Explanation:

Surrounded regions shouldn’t be on the border, which means that any 'O' on the border of the board are not flipped to 'X'. Any 'O' that is not on the border and it is not connected to an 'O' on the border will be flipped to 'X'. Two cells are connected if they are adjacent cells connected horizontally or vertically.
*/

void dfs(vector<vector<char>>& board, int i, int j)
{
    if (i < 0 || i >= board.size() || j < 0 || j >= board[i].size() || board[i][j] == 'X' || board[i][j] == '*') {
        return;
    }
    board[i][j] = '*';
        
    dfs(board, i-1, j);
    dfs(board, i+1, j);
    dfs(board, i, j-1);
    dfs(board, i, j+1);
}
    
void solve(vector<vector<char>>& board)
{
    if (board.size() == 0) {
        return;
    }
    int m = board.size();
    int n = board[0].size();

    /* Look for 'O' in the border rows and mark all
       reachable/connected O's with a *
     */
    // border rows
    for (int i=0; i<m; i++) {
        for (int j=0; j<n; j++) {
            if (i == 0 || i == m-1) {
                if (board[i][j] == 'O') {
                    dfs(board, i, j);
                }
            }
        }
    }
        
    /* Look for 'O' in the border columns and mark all
       reachable/connected O's with a *
     */
    // border columns
    for (int i=0; i<m; i++) {
        for (int j=0; j<n; j++) {
            if (j == 0 || j == n-1) {
                if (board[i][j] == 'O') {
                    dfs(board, i, j);
                }
            }
        }
    }

    /* Replace all 'O' with 'X' and 
       '*' back with 'O'
     */
    for (int i=0; i<m; i++) {
        for (int j=0; j<n; j++) {
            if (board[i][j] == 'O') {
                board[i][j] = 'X';
            } else if (board[i][j] == '*') {
                board[i][j] = 'O';
            }
        }
    }
}
    
int main()
{
    return 0;
}
