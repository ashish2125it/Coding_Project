/*
struct Node
{
    int data;
    Node* left;
    Node* right;
};
*/
class Solution {
  public:
    // Function to return a list of nodes visible from the top view
    // from left to right in Binary Tree.
    vector<int> topView(Node *root) {
    vector<int>ans;
    if(!root) return ans;
    map<int,int>mp; // Hd -> Node
    
    queue<pair<int,Node*>> q; // { HD,Node}
    q.push({0,root});
    
    while(!q.empty())
    {
        auto it = q.front();
        Node* node = q.front().second;
        int hd = q.front().first;
        q.pop();
        
        if(mp.find(hd)==mp.end())
        mp[hd] = node->data;
        
        if(node->left)
         q.push({hd-1,node->left});
         
           if(node->right)
         q.push({hd+1,node->right});
        
    }
    
    for(auto it:mp)
    {
        ans.push_back(it.second);
    }
    return ans;
    
    
    }
};

