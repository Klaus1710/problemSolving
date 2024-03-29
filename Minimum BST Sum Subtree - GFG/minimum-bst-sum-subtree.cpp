//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }

    Node *buildTree(string s) {
        if (s.length() == 0 || s[0] == 'N') return NULL;

        // Create the root of the tree
        vector<string> str;
        istringstream iss(s);
        for (string s; iss >> s;) str.push_back(s);
        Node *root = new Node(stoi(str[0]));

        // Push the root to the queue
        queue<Node*> q;
        q.push(root);

        // Starting from the second element
        int i = 1;
        while (q.size() > 0 && i < str.size()) {

            // Get and remove the front of the queue
            Node *currNode = q.front();
            q.pop();

            // Get the current node's value from the string
            string currVal = str[i];

            // If the left child is not null
            if (currVal != "N") {

                // Create the left child for the current node
                currNode->left = new Node(stoi(currVal));
                // Push it to the queue
                q.push(currNode->left);
            }

            // For the right child
            i++;
            if (i >= str.size()) break;

            currVal = str[i];

            // If the right child is not null
            if (currVal != "N") {

                // Create the right child for the current node
                currNode->right = new Node(stoi(currVal));

                // Push it to the queue
                q.push(currNode->right);
            }
            i++;
        }

        return root;
    }

    void inorder(Node *root) {
        if (root == NULL) return;
        inorder(root->left);
        cout<<root->data<<" ";
        inorder(root->right);
    }
};


// } Driver Code Ends
//User function Template for C++

class Solution {
public:
    //func1 to calculate running sum
    //func2 to check if any running sum matches target
    //func3 to check matched if matched subtree is binary or not
    //func4 to find length of min bst
    unordered_map<Node* , int> mpp;
    int mini=INT_MAX;
    int dfsSum(Node* root)
    {
        if(root==NULL) return 0;
        int l=dfsSum(root->left);
        int r=dfsSum(root->right);
        int subTreeSum=l+r+(root->data);
        mpp[root]=subTreeSum;
        return subTreeSum;
    }
    void inorder(Node* root, vector<int>& Inorder)
    {
        if(root==NULL)
        {
            return;
        }
        inorder(root->left, Inorder);
        Inorder.push_back(root->data);
        inorder(root->right, Inorder);
    }
    bool checkBST(Node* root) 
    {
        vector<int> Inorder;
        inorder(root, Inorder);
        for(int i=0; i<Inorder.size()-1; i++)
        {
            if(Inorder[i]>=Inorder[i+1]) return false;
        }
        return true;
    }
    int findLen(Node* root)
    {
        if(root==NULL) return 0;
        return 1+findLen(root->left)+findLen(root->right);
    }
    void checkSum(Node* root, int target)
    {
        if(root==NULL) return;
        if(mpp[root]==target) 
        {
            if(checkBST(root)) mini=min(mini, findLen(root));
        }
        checkSum(root->left, target);
        checkSum(root->right, target);
    }
    int minSubtreeSumBST(int target, Node *root) {
        // code here
        dfsSum(root);
        checkSum(root, target);
        if(mini==INT_MAX) return -1;
        return mini;
    }
};

//{ Driver Code Starts.


int main(){
    
    int t;
    cin>>t;
    while(t--){
        int target;
        cin>>target;
        string str;
        getline(cin,str);
        getline(cin,str);
        Node node(0);
        Node *root = node.buildTree(str);
        Solution ob;
        int res = ob.minSubtreeSumBST(target, root);
        cout<<res<<endl;
    }
    return 0;
}
// } Driver Code Ends