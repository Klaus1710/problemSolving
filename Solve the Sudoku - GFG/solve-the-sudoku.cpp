//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
// UNASSIGNED is used for empty cells in sudoku grid 
#define UNASSIGNED 0  

// N is used for the size of Sudoku grid.  
// Size will be NxN  
#define N 9  


// } Driver Code Ends
class Solution 
{
    public:
    //Function to find a solved Sudoku. 
    bool isValid(vector<vector<int>>& board, int row, int col, int key)
    {
        for(int i=0; i<9; i++)
        {
            if(board[row][i]==key) return false;
            if(board[i][col]==key) return false;
            if(board[3*(row/3)+(i/3)][3*(col/3)+(i%3)]==key) return false;
        }
        return true;
    }
    bool solve(vector<vector<int>>& board)
    {
        for(int i=0; i<9; i++)
        {
            for(int j=0; j<9; j++)
            {
                if(board[i][j]==0)
                {
                    for(int k=1; k<=9; k++)
                    {
                        if(isValid(board, i, j, k))
                        {
                            board[i][j]=k;
                            if(solve(board)) return true;
                            else board[i][j]=0;
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }
    bool SolveSudoku(int grid[N][N])  
    { 
        vector<vector<int>> board(9, vector<int>(9));
        for(int i=0; i<9; i++)
        {
            for(int j=0; j<9; j++)
            {
                board[i][j]=grid[i][j];
            }
        }
        bool flag= solve(board);
        printb(board);
        return flag;
    }
    void printb(vector<vector<int>>& board)
    {
        for(int i=0; i<9; i++)
            for(int j=0; j<9; j++)
                cout<<board[i][j]<<" ";
    }
    //Function to print grids of the Sudoku.
    void printGrid (int grid[N][N]) 
    {
        // for(int i=0; i<N; i++)
        //     for(int j=0; j<N; j++)
        //         cout<<grid[i][j]<<" ";
    }
};

//{ Driver Code Starts.

int main() {
	int t;
	cin>>t;
	while(t--)
	{
		int grid[N][N];
		
		for(int i=0;i<9;i++)
		    for(int j=0;j<9;j++)
		        cin>>grid[i][j];
		        
		Solution ob;
		
		if (ob.SolveSudoku(grid) == true)  
            ob.printGrid(grid);  
        else
            cout << "No solution exists";  
        
        cout<<endl;
	}
	
	return 0;
}
// } Driver Code Ends