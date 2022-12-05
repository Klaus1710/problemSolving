//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    bool check(int start, int color, vector<int>adj[], vector<int>& Vis)
    {
        Vis[start]=color;
        for(auto it : adj[start])
        {
            if(Vis[it]==-1)
            {
                Vis[it]=!Vis[start];
                if(!check(it, Vis[it], adj, Vis)) return false;
            }
            else if(Vis[it]==color) return false;
        }
        return true;
    }
	bool isBipartite(int V, vector<int>adj[]){
	    // Code here
	    vector<int> Vis(V, -1);
	    for(int i=0; i<V; i++)
	    {
	        if(Vis[i]== -1)
	        {
	            if(!check(i, 0, adj, Vis)) return false;
	        }
	    }
	    return true;
	}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		Solution obj;
		bool ans = obj.isBipartite(V, adj);    
		if(ans)cout << "1\n";
		else cout << "0\n";  
	}
	return 0;
}
// } Driver Code Ends