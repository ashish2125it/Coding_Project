//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int cnt = 0;
    void merge(vector<int>&arr,int low,int mid,int high)
{
  int start1 = low, start2 = mid+1;

  vector<int>temp;
  while(start1<=mid &&  start2<=high)
  {
      if(arr[start1]<= arr[start2])
      {
          temp.push_back(arr[start1++]);
        
      }
      else{
           cnt += (mid-start1+1);
           temp.push_back(arr[start2++]);
      }
      
  }

  while(start1<=mid)
  {
     temp.push_back(arr[start1]);
      start1++;
  }

   while(start2<=high)
  {
     temp.push_back(arr[start2]);
      start2++;
  }

  int k =0;
  for(int i=low;i<=high;i++)
  arr[i] = temp[k++];

  return;
}
void merge_sort(vector<int>&arr,int low,int high)
{
  if(low>=high) return ;

  int mid = (low+high)/2;
  merge_sort(arr,low,mid);
  merge_sort(arr,mid+1,high);
  merge(arr,low,mid,high);

}
    int inversionCount(vector<int> &arr) {
    int n = arr.size();
    int ans= 0;
    merge_sort(arr,0,n-1);
    return cnt;
    
    }
};

//{ Driver Code Starts.

int main() {

    int T;
    cin >> T;
    cin.ignore();
    while (T--) {
        int n;
        vector<int> a;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int num;
        while (ss >> num)
            a.push_back(num);
        Solution obj;
        cout << obj.inversionCount(a) << endl;
        cout << "~" << endl;
    }

    return 0;
}

// } Driver Code Ends