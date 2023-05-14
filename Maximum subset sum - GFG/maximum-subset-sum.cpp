//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


class IntArray
{
public:
    template <class T>
    static void input(vector<T> &A,int n)
    {
        for (int i = 0; i < n; i++)
        {
            scanf("%d ",&A[i]);
        }
    }

    template <class T>
    static void print(vector<T> &A)
    {
        for (int i = 0; i < A.size(); i++)
        {
            cout << A[i] << " ";
        }
        cout << endl;
    }
};


// } Driver Code Ends
class Solution {

  public:
    long long solve(int ind, int N, vector<int>& A, vector<long long>& dp)
    {
        //base case
        if(ind>=N) return 0;
        
        //dp base case
        if(dp[ind] != -1) return dp[ind];
        
        //recursive cases
        
        //l
        long long l = A[ind] + solve(ind+1, N, A, dp);
        
        //r
        long long r = 0;
        if(ind<N-1) r = A[ind+1] + solve(ind+2, N, A, dp);
        
        return dp[ind] = max(l, r);
        
    } 
    long long findMaxSubsetSum(int N, vector<int> &A) 
    {
        // code here
        vector<long long> dp(N, -1);
        return solve(0, N, A, dp);
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        
        int N;
        scanf("%d",&N);
        
        
        vector<int> A(N);
        IntArray::input(A,N);
        
        Solution obj;
        long long res = obj.findMaxSubsetSum(N, A);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends