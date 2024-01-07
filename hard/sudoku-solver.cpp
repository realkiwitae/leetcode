#include <vector>

using namespace std;

/*
    leetcode 37 sudoku-solver
    https://leetcode.com/problems/sudoku-solver

    Write a program to solve a Sudoku puzzle by filling the empty cells.
    Backtracking

    Time complexity: O(9^m) m is the number of empty cells
    Space complexity: O(1)
*/

class Solution {
public:

    bool solve(int x, int y, vector<int>& rows, vector<int>& cols, vector<int>& boxes,vector<vector<char>>& board){
        if(x == 9){
            return true;
        }
        int nx=x,ny=y;
        board[nx][ny] = 'X';
        while(board[nx][ny] != '.'){
            ny++;
            if(ny == 9){
                nx++;
                ny = 0;
                if(nx==9)break;
            }
        }    
        board[x][y] = '.';
        for(int i = 1; i <= 9;i++){
            if(rows[x]& (1<<i))continue;
            if(cols[y]& (1<<i))continue;
            if(boxes[x/3*3+y/3] & (1<<i))continue;
            board[x][y] = '0'+i;
            rows[x] |= 1<<i;
            cols[y] |= 1 << i;
            boxes[x/3*3+y/3] |= 1<<i;
            if(solve(nx,ny,rows,cols,boxes,board)){
                return true;
            }
            board[x][y] = '.';
            rows[x] &= ~(1 << i);
            cols[y] &= ~(1 << i);
            boxes[x/3*3+y/3] &= ~(1 << i);
        }
        return false;
    }


    void solveSudoku(vector<vector<char>>& board) {
        vector<int> rows(9,0);
        vector<int> cols(9,0);
        vector<int> boxes(9,0);
        int sx = -1, sy = -1;
        for(int i = 0; i <9; i++){
            for(int j = 0; j < 9;j++){
                if(board[i][j]=='.'){
                    if(sx ==-1){sx=i,sy=j;}
                    continue;
                }
                rows[i] |= 1<< (board[i][j]-'0');
                cols[j] |= 1<< (board[i][j]-'0');
                boxes[i/3*3 + j/3] |= 1 << (board[i][j]-'0');
            }
        }

        solve(sx,sy,rows,cols,boxes,board);
    }
};