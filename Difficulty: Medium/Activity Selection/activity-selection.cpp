//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
  static bool comp(pair<int,int>a,pair<int,int>b)
  {
     return a.second < b.second;
  }
    int activitySelection(vector<int> &start, vector<int> &finish) {
    int n = start.size();
    vector<pair<int,int>>v;
    for(int i=0;i<n;i++)
    {
        v.push_back({start[i],finish[i]});
    }
    
    sort(v.begin(),v.end(),comp);
    int end = v[0].second;
    int ans=1;
    int i=1;
    while(i<n)
    {
        if(v[i].first > end)
        {
            ans++;
            end = v[i].second;
        }
        i++;
    }
    return ans;
    
        
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string input;
        getline(cin, input);
        stringstream ss(input);
        vector<int> start;
        int num;
        while (ss >> num)
            start.push_back(num);
        getline(cin, input);
        ss.clear();
        vector<int> finish;
        ss.str(input);
        while (ss >> num)
            finish.push_back(num);

        Solution obj;
        cout << obj.activitySelection(start, finish) << endl;
        cout << "~\n";
    }
    return 0;
}
// } Driver Code Ends