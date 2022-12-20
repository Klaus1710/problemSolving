//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    int dfs(int src, int dest, vector<vector<int>>& graph, int MinC, int count, vector<int>& Vis)
    {
        if(src==dest) return count;
        Vis[src]=1;
        for(int i=0; i<graph[src].size(); i++)
        {
            if(Vis[graph[src][i]]==0)
            {
                MinC=min(MinC, dfs(graph[src][i], dest, graph, MinC, count+1, Vis));
            }
        }
        Vis[src]=0;
        return MinC;
    }
    vector<int> shortestPath(vector<vector<int>>& edges, int N,int M, int src){
        // adjacency list
        vector<vector<int>> graph(N);
        for(int i=0; i<M; i++)
        {
            graph[edges[i][1]].push_back(edges[i][0]);
            graph[edges[i][0]].push_back(edges[i][1]);
        }
        // code here
        //count the edges
        //min no of edges
        vector<int>v;
        for(int i=0; i<N; i++)
        {
            if(i==src)
            {
                v.push_back(0);
                continue;
            }
            vector<int> Vis(N, 0);
            int MinC=1e7;
            int count=0;
            int ans=dfs(src, i, graph, MinC, count, Vis);
            if(ans>=1e7) v.push_back(-1);
            else v.push_back(ans);
        }
        return v;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m; cin >> n >> m;
        vector<vector<int>> edges;

        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for(int j=0; j<2; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }

        int src; cin >> src;

        Solution obj;

        vector<int> res = obj.shortestPath(edges, n, m, src);

        for (auto x : res){
            cout<<x<<" ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends