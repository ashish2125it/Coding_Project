//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int findUnique(vector<int> &arr) {
    int n = arr.size();
    int x =0;
    for(auto it:arr)
    x =x^it;
    return x;
        
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution ob;
        int ans = ob.findUnique(arr);
        cout << ans << endl;
    }
    return 0;
}

// } Driver Code Ends