//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    vector<pair<int,int>>st;
    Solution() {
            
    }

    // Add an element to the top of Stack
    void push(int x) { 
       if(st.empty())
       st.push_back({x,x});
       else
       {
       int mini =  min(x,st[st.size()-1].second);
       st.push_back({x,mini});
       }
    }

    // Remove the top element from the Stack
    void pop() {
        if(!st.empty())
        st.pop_back();
        
    }

    // Returns top element of the Stack
    int peek() {
       if(st.empty())
       return -1;
       return st[st.size()-1].first;
    }

    // Finds minimum element of Stack
    int getMin() {
        if(st.empty()) return -1;
        
        return st[st.size()-1].second;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int q;
        cin >> q;

        Solution ob;

        while (q--) {
            int qt;
            cin >> qt;

            if (qt == 1) {
                // push
                int att;
                cin >> att;
                ob.push(att);
            } else if (qt == 2) {
                // pop
                ob.pop();
            } else if (qt == 3) {
                // peek
                cout << ob.peek() << " ";
            } else if (qt == 4) {
                // getMin
                cout << ob.getMin() << " ";
            }
        }
        cout << endl;
        cout << "~" << endl;
    }

    return 0;
}

// } Driver Code Ends