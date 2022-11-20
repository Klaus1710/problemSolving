//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int solve(int ind, int n, int A[], vector<int>& dp)
    {
        if(dp[ind]!=-1) return dp[ind];
        if(ind==n-1) return dp[ind]=1;
        for(int i=ind+1; i<=min(ind+A[ind], n-1); i++)
        {
            if(solve(i, n, A, dp)) return dp[ind]=1;
        }
        return dp[ind]=0;
    }
    int canReach(int A[], int n) {
        vector<int> dp(n, -1);
        return solve(0, n, A, dp);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin>>N;
        
        int A[N];
        
        for(int i=0; i<N; i++)
            cin>>A[i];

        Solution ob;
        cout << ob.canReach(A,N) << endl;
    }
    return 0;
}
// } Driver Code Ends