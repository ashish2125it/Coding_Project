//{ Driver Code Starts
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

/* Linked list Node */
struct Node {
    int data;
    struct Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

Node* buildList() {
    vector<int> arr;
    string input;
    getline(cin, input);
    stringstream ss(input);
    int number;
    while (ss >> number) {
        arr.push_back(number);
    }
    if (arr.empty()) {
        return NULL;
    }
    int val = arr[0];
    int size = arr.size();

    Node* head = new Node(val);
    Node* tail = head;

    for (int i = 1; i < size; i++) {
        val = arr[i];
        tail->next = new Node(val);
        tail = tail->next;
    }

    return head;
}

void printList(Node* n) {
    while (n) {
        cout << n->data << " ";
        n = n->next;
    }
    cout << endl;
}


// } Driver Code Ends
/* node for linked list:

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/

class Solution {
  public:
  Node* reverse(Node* head)
  {
      Node* curr = head;
      Node* next = NULL;
      Node* prev = NULL;
      
      while(curr)
      {
          next = curr->next;
          curr->next = prev;
          prev = curr;
          curr = next;
      }
      return prev;
  }
    Node* addTwoLists(Node* num1, Node* num2) {
      if(num1==NULL ) return num2;
      if(num2==NULL) return num1;
      
      Node* n1= num1;
      while(n1 && n1->data==0)
      n1 = n1->next;
      
       Node* n2= num2;
      while(n2 && n2->data==0)
      n2 = n2->next;
      
      n1 = reverse(n1);
      n2 = reverse(n2);
      
      Node* ans = new Node(-1);
      Node* dummy = ans;
      
      int carry = 0;
      while(n1 && n2)
      {
          int sum = n1->data + n2->data + carry;
          carry = (sum)/10;
          int last_digit = sum%10;
          Node* t = new Node(last_digit);
          dummy->next = t;
          dummy = dummy->next;
          
          n1 = n1->next;
          n2 = n2->next;
      }
      
       while(n1 )
      {
          int sum = n1->data +  carry;
          carry = (sum)/10;
          int last_digit = sum%10;
          Node* t = new Node(last_digit);
          dummy->next = t;
          dummy = dummy->next;
          
          n1 = n1->next;
       //   n2 = n2->next;
      }
      
       while( n2)
      {
          int sum =  n2->data + carry;
          carry = (sum)/10;
          int last_digit = sum%10;
          Node* t = new Node(last_digit);
          dummy->next = t;
          dummy = dummy->next;
          
         // n1 = n1->next;
          n2 = n2->next;
      }
      
      while(carry)
      {
         int sum = carry;
          carry = (sum)/10;
          int last_digit = sum%10;
          Node* t = new Node(last_digit);
          dummy->next = t;
          dummy = dummy->next;
          
      }
      
      ans= reverse(ans->next);
      return ans;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // To ignore the newline character after the integer input

    while (t--) {
        Node* num1 = buildList();
        Node* num2 = buildList();
        Solution ob;
        Node* res = ob.addTwoLists(num1, num2);
        printList(res);
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends