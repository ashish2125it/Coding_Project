//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// Definition of the Node class
class Node {
  public:
    int data;
    Node *left;
    Node *right;

    Node(int x) {
        data = x;
        left = NULL;
        right = NULL;
    }
};

// Function to print the tree in postorder traversal
void printPostOrder(Node *root) {
    if (root == NULL)
        return;
    printPostOrder(root->left);
    printPostOrder(root->right);
    cout << root->data << " ";
}


// } Driver Code Ends


/*Complete the code here.
Node is as follows:
struct Node
{
  int data;
  Node* left;
  Node* right;
};
*/
class Solution {
public:
    // Function to create mapping from node value to its index in inorder traversal
    void CreateMapping(vector<int> &in, map<int, int> &NodeToIndex, int n) {
        for (int i = 0; i < n; i++) {
            NodeToIndex[in[i]] = i;
        }
    }

    // Recursive function to construct the binary tree
    Node* solve(vector<int> &in, vector<int> &pre, int &PreOrderIndex, int InorderStart, int InorderEnd, int n, map<int, int> &NodeToIndex) {
        if (PreOrderIndex >= n || InorderStart > InorderEnd) {
            return NULL;
        }

        int element = pre[PreOrderIndex++]; // Root node from preorder
        Node* root = new Node(element);
        
        int pos = NodeToIndex[element]; // Find position of root in inorder
        
        // Recursively construct left and right subtrees
        root->left = solve(in, pre, PreOrderIndex, InorderStart, pos - 1, n, NodeToIndex);
        root->right = solve(in, pre, PreOrderIndex, pos + 1, InorderEnd, n, NodeToIndex);

        return root;
    }

    // Function to build the tree from inorder and preorder traversals
    Node* buildTree(vector<int> in, vector<int> pre) {
        int PreOrderIndex = 0;
        int n = in.size();
        map<int, int> NodeToIndex;
        
        // Create mapping of node values to indices in inorder traversal
        CreateMapping(in, NodeToIndex, n);

        // Build and return the root of the tree
        return solve(in, pre, PreOrderIndex, 0, n - 1, n, NodeToIndex);
    }
};


//{ Driver Code Starts.

// Main function where the test cases are handled
int main() {
    int t;
    cin >> t;
    cin.ignore();

    while (t--) {
        vector<int> inorder, preorder;

        // Input the inorder traversal
        string input;
        getline(cin, input);
        stringstream ss1(input);
        int num;
        while (ss1 >> num)
            inorder.push_back(num);

        // Input the preorder traversal
        getline(cin, input);
        stringstream ss2(input);
        while (ss2 >> num)
            preorder.push_back(num);

        // Create Solution object and build the tree
        Solution obj;
        Node *root = obj.buildTree(inorder, preorder);

        // Print the postorder traversal of the constructed tree
        printPostOrder(root);
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends