//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
	int Max=0;
	int solve(int n, int N, int arr[], vector<int>& dp)
	{
	    //base case
	    if(n==0) return 0;
	    if(dp[n]!=-1) return dp[n];
	    
	    //recursion
	    int tMax=0;
	    for(int i=0; i<n; i++)
	    {
	        int sum = arr[i]+solve(i, N, arr, dp);
	        if((n==N || (n<N && arr[i]<arr[n])) && tMax<sum) tMax = sum;
	    }
	    Max = max(Max, tMax);
	    return dp[n] = tMax;
	}
	int maxSumIS(int arr[], int n)  
	{  
	    // Your code goes here
	    vector<int>dp(n+1, -1);
	    solve(n, n, arr, dp);
	    return  Max;
	}  
};

//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int a[n];

        for(int i = 0; i < n; i++)
        	cin >> a[i];

      

	    Solution ob;
	    cout << ob.maxSumIS(a, n) << "\n";
	     
    }
    return 0;
}


// } Driver Code Ends