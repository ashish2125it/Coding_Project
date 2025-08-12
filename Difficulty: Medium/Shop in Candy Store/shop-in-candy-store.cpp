class Solution {
  public:
    vector<int> minMaxCandy(vector<int>& prices, int k) {
     int j = prices.size();
     int n = j;
     int i=0;
     vector<int>ans;
     sort(prices.begin(),prices.end());
     int mini=0,maxi =0;
     while(i<j)
     {
         mini += prices[i];
         int cnt=0;
         while(cnt<k)
         {
             cnt++;
             j--;
         }
         i++;
     }
     
     i= prices.size()-1,j = -1;
     
     while(i>j)
     {
         maxi += prices[i];
         int cnt=0;
         while(cnt<k)
         {
             j++;
             cnt++;
         }
         
         i--;
     }
     
     ans.push_back(mini);
     ans.push_back(maxi);
     return ans;
        
    }
};