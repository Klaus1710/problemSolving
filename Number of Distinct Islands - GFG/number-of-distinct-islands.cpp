//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    void dfs(int row, int col, int brow, int bcol, int m, int n, vector<vector<int>>& grid, vector<vector<int>>& vis, vector<pair<int, int>>& temp)
    {
        if(row<0 || row>=m || col<0 || col>=n) return;
        if(grid[row][col]==0) return;
        if(vis[row][col]==1)  return;
        vis[row][col]=1;
        temp.push_back({row-brow, col-bcol});
        dfs(row+1, col, brow, bcol, m, n, grid, vis, temp);
        dfs(row-1, col, brow, bcol, m, n, grid, vis, temp);
        dfs(row, col+1, brow, bcol, m, n, grid, vis, temp);
        dfs(row, col-1, brow, bcol, m, n, grid, vis, temp);
    }
    int countDistinctIslands(vector<vector<int>>& grid) {
        set<vector<pair<int, int>>> hset;
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>> vis(m, vector<int>(n, 0));
        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(grid[i][j]==1 && vis[i][j]==0) 
                {
                    vector<pair<int, int>>temp;
                    dfs(i, j, i, j, m, n, grid, vis, temp);
                    hset.insert(temp);
                    temp.clear();
                }
            }
        }
        return hset.size();
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
        cout << obj.countDistinctIslands(grid) << endl;
    }
}
// } Driver Code Ends