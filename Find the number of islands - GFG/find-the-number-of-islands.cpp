//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to find the number of islands.
    void dfs(int i, int j, int m, int n, vector<vector<char>>& grid, vector<vector<int>>& vis)
    {
        if(i<0 || j<0 || i>=m || j>=n) return;
        if(grid[i][j]=='0') return;
        if(vis[i][j]) return;
        vis[i][j]=1;
        dfs(i+1,j,m,n,grid,vis);
        dfs(i+1,j+1,m,n,grid,vis);
        dfs(i,j+1,m,n,grid,vis);
        dfs(i-1,j+1,m,n,grid,vis);
        dfs(i-1,j,m,n,grid,vis);
        dfs(i-1,j-1,m,n,grid,vis);
        dfs(i,j-1,m,n,grid,vis);
        dfs(i+1,j-1,m,n,grid,vis);
    }
    int numIslands(vector<vector<char>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        int count=0;
        vector<vector<int>>vis(m, vector<int>(n,0));
        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(grid[i][j]=='1' && !vis[i][j])
                {
                    // cout<<i<<" "<<j<<endl;
                    count++;
                    dfs(i, j, m, n, grid, vis);
                }
            }
        }
        return count;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> grid(n, vector<char>(m, '#'));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        int ans = obj.numIslands(grid);
        cout << ans << '\n';
    }
    return 0;
}
// } Driver Code Ends