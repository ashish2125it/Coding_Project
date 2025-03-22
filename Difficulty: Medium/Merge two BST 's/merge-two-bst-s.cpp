//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
#define MAX_HEIGHT 100000

// Tree Node
struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

// Function to Build Tree
Node* buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;)
        ip.push_back(str);

    // Create the root of the tree
    Node* root = new Node(stoi(ip[0]));

    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current node
            currNode->left = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


// } Driver Code Ends

/*
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/
class Solution {
  public:
    // Function to return a list of integers denoting the node
    // values of both the BST in a sorted order.
   void inorder(Node* root,vector<int>&in)
    {
        if(!root) return; 
        
        inorder(root->left,in);
        in.push_back(root->data);
        inorder(root->right,in);
    }
    
    vector<int> merge(vector<int>v1,vector<int>v2)
    {
        int n1 = v1.size();
        int n2 = v2.size();
        
        int i=0,j=0;
        vector<int>ans;
        
        while(i<n1 && j<n2)
        {
            if(v1[i]<=v2[j])
            {
                ans.push_back(v1[i++]);
            }
            else
            ans.push_back(v2[j++]);
            
        }
        
        while(i<n1)
        ans.push_back(v1[i++]);
        
        while(j<n2)
        ans.push_back(v2[j++]);
        
        return ans;
    }
    
    Node* inorderToBST(int start,int end,vector<int>&in)
    {
        if(start>end) return NULL;
        
        
        int mid=  (start  + end)/2;
        
        Node* root = new Node(in[mid]);
        root->left = inorderToBST(start,mid-1,in);
        root->right = inorderToBST(mid+1,end,in);
        
        return root;
    }
    
    
    vector<int> merge(Node *root1, Node *root2) {
    vector<int>in1,in2;
    inorder(root1,in1);
    inorder(root2,in2);
   vector<int> mergeArray =  merge(in1,in2);
   return mergeArray;
    
    }
};


//{ Driver Code Starts.
int main() {

    int t;
    string tc;
    getline(cin, tc);
    t = stoi(tc);
    while (t--) {
        string s;
        getline(cin, s);
        Node* root1 = buildTree(s);

        getline(cin, s);
        Node* root2 = buildTree(s);

        // getline(cin, s);
        Solution obj;
        vector<int> vec = obj.merge(root1, root2);
        for (int i = 0; i < vec.size(); i++)
            cout << vec[i] << " ";
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends