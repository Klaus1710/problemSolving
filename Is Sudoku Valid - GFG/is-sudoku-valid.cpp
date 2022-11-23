//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    bool isSafe(vector<vector<int>>mat , int row, int col)
    {
        for(int i=0;i<mat.size();i++)
        {
            if(i!=col && mat[row][i]==mat[row][col])
            {
                return false;
            }
            if(i!=row && mat[i][col]==mat[row][col])
            {
                return false;
            }
            if(row!=(row/3)*3+(i/3) && col!=(col/3)*3+(i%3) && mat[(row/3)*3+(i/3)][(col/3)*3+(i%3)]==mat[row][col])
            {
                return false;
            }
        }
        return true;
    }
    int isValid(vector<vector<int>> mat){
        for(int i=0; i<9; i++)
        {
            for(int j=0; j<9; j++)
            {
                if(mat[i][j]!=0)
                {
                    if(!isSafe(mat, i, j))
                    {
                        return 0;
                    }
                }
            }
        }
        return 1;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        vector<vector<int>> mat(9, vector<int>(9, 0));
        for(int i = 0;i < 81;i++)
            cin>>mat[i/9][i%9];
        
        Solution ob;
        cout<<ob.isValid(mat)<<"\n";
    }
    return 0;
}
// } Driver Code Ends