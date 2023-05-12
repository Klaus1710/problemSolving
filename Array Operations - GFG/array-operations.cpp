//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int arrayOperations(int n, vector<int> &arr) {
        // code here
        bool Nonzero=false;
        int res=0;
        int zC=0;
        for(int i=0; i<n; i++)
        {
            if(arr[i] == 0) 
            {
                 if(Nonzero) res++;
                 Nonzero = false;
                 zC++;
            }
            else
            {
                Nonzero = true;
            }
        }
        if(zC==0) return -1;
        if(Nonzero) res++;
        return res;
        
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        
        int n;
        cin>>n;
        
        
        vector<int> arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        
        Solution obj;
        int res = obj.arrayOperations(n, arr);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends