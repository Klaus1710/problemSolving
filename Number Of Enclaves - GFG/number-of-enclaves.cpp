//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    void dfs(int row, int col, int m, int n, vector<vector<int>> &grid, vector<vector<int>> &vis)
    {
        if(row<0 || row>=m || col<0 || col>=n) return;
        if(grid[row][col]==0) return;
        if(vis[row][col]==1) return;
        vis[row][col]=1;
        dfs(row+1, col, m, n, grid, vis);
        dfs(row-1, col, m, n, grid, vis);
        dfs(row, col+1, m, n, grid, vis);
        dfs(row, col-1, m, n, grid, vis);
    }
    int numberOfEnclaves(vector<vector<int>> &grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>> vis(m, vector<int>(n, 0));
        for(int i=0; i<m; i++)
        {
            if(grid[i][0]==1) dfs(i, 0, m, n, grid, vis);
            if(grid[i][n-1]==1) dfs(i, n-1, m, n, grid, vis);
        }
        for(int i=0; i<n; i++)
        {
            if(grid[0][i]==1) dfs(0, i, m, n, grid, vis);
            if(grid[m-1][i]==1) dfs(m-1, i, m, n, grid, vis);
        }
        int count=0;
        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(grid[i][j]==1 && vis[i][j]==0) count++;
            }
        }
        return count;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        cout << obj.numberOfEnclaves(grid) << endl;
    }
}
// } Driver Code Ends