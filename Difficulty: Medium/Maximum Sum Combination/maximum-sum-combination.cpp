class Solution {
  public:
    vector<int> topKSumPairs(vector<int>& a, vector<int>& b, int k) {
    vector<int>ans;
    int n = a.size();
    
    sort(a.begin(),a.end(),greater<int>());
    sort(b.begin(),b.end(),greater<int>());
    
     priority_queue<pair< int, pair<int,int> >>pq;
     pq.push({a[0] + b[0],{0,0}});
     
     map<pair<int,int>,bool>vis;
     
     vis[{0,0}] =  1;
     
     while(ans.size()<k)
     {
         auto it = pq.top();
         pq.pop();
         int sum = it.first;
         int i = it.second.first;
         int j = it.second.second;
         
         ans.push_back(sum);
         
         if(i+1<n && vis[{i+1,j}]!=true)
         {
             vis[{i+1,j}] = true;
             pq.push({a[i+1]+b[j],{i+1,j}});
         }
         
         if(j+1<n && vis[{i,j+1}]!=true)
         {
             vis[{i,j+1}] = true;
             pq.push({a[i]+b[j+1],{i,j+1}});
         }
     }
     
     
    
    
    return ans;
    
    }
};