#include <bits/stdc++.h> 


bool issafe(int row, int col, vector<vector<int>>& board, int val)
{
    for(int i=0;i<board.size();i++)
    {
        //row check
        if(board[row][i]==val)
        {
            return false;
        }

        //col check
        if(board[i][col]==val)
        {
            return false;
        }

        // cheacking in 3X3

        if(board[3*(row/3)+i/3][3*(col/3)+i%3]==val)
        {
            return false;
        }
    }
    return true;
}

bool solve(vector<vector<int>>& board)
{
    for(int row=0;row<9;row++)
    {
        for(int col=0;col<9;col++)
        {
            if(board[row][col]==0)
            {
                for(int val=1;val<=9;val++)
                {
                    if(issafe(row, col, board,val))
                    {
                        board[row][col]=val;
                        //recursive call
                        bool solvepossible = solve(board);
                        if(solvepossible)
                        {
                            return true;
                        }
                        else
                        {
                            board[row][col]=0;
                        }
                    }
                }
                 return false;
            }
        }
       
    }
    return true;
}
void solveSudoku(vector<vector<int>>& sudoku)
{
	solve(sudoku);
}
