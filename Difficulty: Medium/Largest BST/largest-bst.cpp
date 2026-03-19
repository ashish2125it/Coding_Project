/* Tree node structure  used in the program

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};*/

class Solution{
    public:
    class info{
public:
int maxi;
int mini;
bool isBST;
int size;
};
    
    int ans= 1;
info solve(Node* root)
{
    if(!root) 
    {
        info in ;
        in.maxi = INT_MIN;
        in.mini = INT_MAX;
        in.isBST = 1;
        in.size = 0;
        return in;
    }

    info left = solve(root->left);
    info right = solve(root->right);


    info temp ;
    if(left.isBST==true && right.isBST==true && left.maxi<root->data &&  right.mini > root->data )
    {
        
        temp.maxi = max(root->data,right.maxi);
        temp.mini = min(root->data,left.mini);
        temp.isBST = 1;
        temp.size = 1 + left.size + right.size ;
        ans = max(ans,temp.size);
       
    }
    else
    {
        temp.maxi = root->data;
        temp.mini = root->data;
        temp.isBST = 0;
        temp.size = 1;
      
    }
    return temp;
    
}
    int largestBst(Node *root)
    {
        if(!root) return 0;
    
        info temp = solve(root);
        return ans;
        
    
    
    
    
    
    
    
    
    }
};
