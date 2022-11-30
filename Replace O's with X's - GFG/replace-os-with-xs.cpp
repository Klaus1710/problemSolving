//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    void dfs(vector<vector<int>>& vis, int row, int col, int n, int m, vector<vector<char>> mat, int orow[], int ocol[])
    {
        vis[row][col]=1;
        for(int i=0; i<4; i++)
        {
            int nrow=row+orow[i];
            int ncol=col+ocol[i];
            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && !vis[nrow][ncol] && mat[nrow][ncol]=='O')
            {
                dfs(vis, nrow, ncol, n, m, mat, orow, ocol);
            }
        }
    }
    vector<vector<char>> fill(int n, int m, vector<vector<char>> mat)
    {
        vector<vector<int>> vis(n, vector<int>(m,0));
        int orow[]={-1, 0, 1, 0};
        int ocol[]={0, 1, 0, -1};
        for(int i=0; i<m; i++)
        {
            if(!vis[0][i] && mat[0][i]=='O') dfs(vis, 0, i, n, m, mat, orow, ocol);
            if(!vis[n-1][i] && mat[n-1][i]=='O') dfs(vis, n-1, i, n, m, mat, orow, ocol);
        }
        for(int i=0; i<n; i++)
        {
            if(!vis[i][0] && mat[i][0]=='O') dfs(vis, i, 0, n, m, mat, orow, ocol);
            if(!vis[i][m-1] && mat[i][m-1]=='O') dfs(vis, i, m-1, n, m, mat, orow, ocol);
        }
        vector<vector<char>> ans(n, vector<char>(m, 'O'));
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(!vis[i][j]) ans[i][j]='X';
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        vector<vector<char>> mat(n, vector<char>(m, '.'));
        for(int i = 0;i < n;i++)
            for(int j=0; j<m; j++)
                cin>>mat[i][j];
        
        Solution ob;
        vector<vector<char>> ans = ob.fill(n, m, mat);
        for(int i = 0;i < n;i++) {
            for(int j = 0;j < m;j++) {
                cout<<ans[i][j]<<" ";
            }
            cout<<"\n";
        }
    }
    return 0;
}
// } Driver Code Ends