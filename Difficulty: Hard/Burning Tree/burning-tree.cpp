/*
class Node {
  public:
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
    Node* find_node(Node* root,int target,unordered_map<Node*,Node*>&mp)
    {
        if(!root) return NULL;
        if(root->data==target) return root;
        
        
        Node* left=NULL;
        Node* right = NULL;
        if(root->left)
        {
             mp[root->left] = root;
             left = find_node(root->left,target,mp);
        }
        
        if(root->right)
        {
             mp[root->right] = root;
            right = find_node(root->right,target,mp);
        }
       
        
        if(left) return left;
        
        if(right) return right;
        
        return NULL;
    }
    int minTime(Node* root, int target) {
    if(!root) return 0;
   
    
    unordered_map<Node*,Node*>mp;
    mp[root] = NULL;
    Node* node = find_node(root,target,mp);
    queue<pair<Node*,int >> q;
    q.push({node,0});
    unordered_map<Node*,bool>vis;
    vis[node] = 1;
    int ans=  0;
    while(q.size())
    {
        Node* front = q.front().first;
        int t = q.front().second;
        ans=  max(ans,t);
        q.pop();
        
        if(front->left && vis.find(front->left)==vis.end())
        {
          q.push({front->left,t+1});
          vis[front->left] = 1;
        }
        
          if(front->right && vis.find(front->right)==vis.end())
        {
             q.push({front->right,t+1});
             vis[front->right] = 1;
        }
        
        if(mp[front]!=NULL && vis.find(mp[front])==vis.end())
        {
             q.push({mp[front],t+1});
             vis[mp[front]] = 1;
        }
        
    }
    
    return ans;
    
        
    }
};