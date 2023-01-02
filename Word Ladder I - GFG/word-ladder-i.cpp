//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    bool fn_cmp(string a, string b)
    {
        int c=0;
        int i=0, j=0;
        while(i<a.size() && j<b.size())
        {
            if(a[i]!=b[j]) c++;
            i++;
            j++;
        }
        if(c==1) return true;
        else return false;
    }
    int bfs(string endWord, vector<vector<int>>& graph, vector<string>& wordList, vector<int>& Vis, queue<pair<int, int>>& q)
    {
        while(!q.empty())
        {
            int id=q.front().first;
            int curCount=q.front().second;
            q.pop();
            if(wordList[id]==endWord) return curCount+1;
            for(auto it: graph[id])
            {
                if(Vis[it]==0)
                {
                    Vis[it]=1;
                    q.push({it, curCount+1});
                }
            }
        }
        return 1e7;
    }
    int wordLadderLength(string beginWord, string endWord, vector<string>& wordList)
    {
        int n=wordList.size();
        vector<vector<int>> graph(n);
        for(int i=0; i<n; i++)
        {
            for(int j=i+1; j<n; j++)
            {
                if(fn_cmp(wordList[i], wordList[j]))
                {
                    graph[i].push_back(j);
                    graph[j].push_back(i);
                }
            }
        }
        int MinS=1e7;
        for(int i=0; i<n; i++)
        {
            if(fn_cmp(beginWord, wordList[i]))
            {
                vector<int> Vis(n, 0);
                queue<pair<int, int>>q;
                q.push({i, 1});
                Vis[i]=1;
                MinS=min(MinS, bfs(endWord, graph, wordList, Vis, q));
            }
        }
        if(MinS>=1e7) return 0;
        return MinS;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<string>wordList(n);
		for(int i = 0; i < n; i++)cin >> wordList[i];
		string startWord, targetWord;
		cin >> startWord >> targetWord;
		Solution obj;
		int ans = obj.wordLadderLength(startWord, targetWord, wordList);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends