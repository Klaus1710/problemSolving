//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int arrayOperations(int n, vector<int> &arr) {
        // code here
        //flag variable to be turned on when a Nonzero element is encountered
        bool Nonzero=false;
        //total no of subarrays
        int res=0;
        //total no of zeroes
        int zC=0;
        for(int i=0; i<n; i++)
        {
            if(arr[i] == 0) 
            {
                 if(Nonzero) res++;
                 //if a 0 is encounterd after encountering a Nonzero element increase no of subarrays
                 
                 Nonzero = false;
                 
                 zC++;//count no of total no of zeroes in the array
            }
            else
            {
                Nonzero = true;
                //flag turned on encountering a nonzero element
            }
        }
        if(zC==0) return -1;//if no of 0s is 0 return -1
        
        //if last subarray is left without encountering a 0 count it too
        if(Nonzero) res++;
        
        //return the result
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