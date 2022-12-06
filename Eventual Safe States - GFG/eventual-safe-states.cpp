//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
// vus and pathVis and check
class Solution {
  public:
    bool dfscheck(int node, vector<int> adj[], vector<int> &Vis, vector<int> &pathVis, vector<int> &check)
    {
        Vis[node]=1;
        pathVis[node]=1;
        check[node]=0;
        for(auto it : adj[node])
        {
            if(!Vis[it])
            {
                if(dfscheck(it, adj, Vis, pathVis, check)==true)
                {
                    check[node]=0;
                    return true;
                }
            }
            else if(pathVis[it])
            {
                check[node]=0;
                return true;
            }
        }
        check[node]=1;
        pathVis[node]=0;
        return false;
    }
    vector<int> eventualSafeNodes(int V, vector<int> adj[]) {
        vector<int> ans;
        vector<int> Vis(V, 0);
        vector<int> pathVis(V, 0);
        vector<int> check(V, 0);
        for(int i=0; i<V; i++)
        {
            if(!Vis[i]) dfscheck(i, adj, Vis, pathVis, check);
        }
        for(int i=0; i<V; i++)
        {
            if(check[i]==1) ans.push_back(i);
        }
        return ans;
        
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {

        int V, E;
        cin >> V >> E;
        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        vector<int> safeNodes = obj.eventualSafeNodes(V, adj);
        for (auto i : safeNodes) {
            cout << i << " ";
        }
        cout << endl;
    }
}

// } Driver Code Ends