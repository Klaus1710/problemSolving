//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution
{
    public:
    //Function to delete middle element of a stack.
    void deleteMid(stack<int>&s, int sizeOfStack)
    {
        stack<int> temp;
        if(sizeOfStack%2==0)
        {
            while(temp.size()!=s.size())
            {
                int t = s.top();
                s.pop();
                temp.push(t);
            }
            s.pop();
            while(!temp.empty())
            {
                int t = temp.top();
                temp.pop();
                s.push(t);
            }
            return;
        }
        while(temp.size()<=s.size())
        {
            int t = s.top();
            s.pop();
            temp.push(t);
        }
        temp.pop();
        while(!temp.empty())
        {
            int t = temp.top();
            temp.pop();
            s.push(t);
        }
        return;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin>>t;
    
    while(t--)
    {
        int sizeOfStack;
        cin>>sizeOfStack;
        
        stack<int> myStack;
        
        for(int i=0;i<sizeOfStack;i++)
        {
            int x;
            cin>>x;
            myStack.push(x);    
        }

            Solution ob;
            ob.deleteMid(myStack,myStack.size());
            while(!myStack.empty())
            {
                cout<<myStack.top()<<" ";
                myStack.pop();
            }
        cout<<endl;
    }   
    return 0;
}

// } Driver Code Ends