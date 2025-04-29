//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

/* Link list Node */
class Node {
  public:
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = nullptr;
    }
};

void printList(Node* node) {
    while (node != NULL) {
        cout << node->data << " ";
        node = node->next;
    }
    cout << "\n";
}

void freeList(struct Node* head) {
    struct Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        delete temp;
    }
}


// } Driver Code Ends

/*  Node is defined as
  struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};*/
class Solution {
  public:
    Node* segregate(Node* head) {
    if(!head) return head;
    
    Node* zero = new Node(-1);
    Node* zero_head = zero;
    Node* one = new Node(-1);
    Node* one_head = one;
    Node* two = new Node(-1);
    Node* two_head = two;
    
    Node* temp = head;
    while(temp)
    {
        if(temp->data==0)
        {
           Node* t = new Node(0);
           zero->next= t;
           zero = zero->next;
        }
        else if(temp->data==1)
        {
             Node* t = new Node(1);
             one->next= t;
             one = one->next;
        }
        else
        {
             Node* t = new Node(2);
             two->next= t;
             two = two->next;
        }
        temp = temp->next;
    }
    
     if(one_head->next)
     zero->next = one_head->next;
     else
     {
      if(two_head->next)     
     zero->next = two_head->next;
     }
     
     if(two_head->next)
     one->next = two_head->next;
     
     return zero_head->next;
     
    }
};



//{ Driver Code Starts.

// Driver program to test above functions
int main() {
    int t, k;
    cin >> t;
    cin.ignore(); // Ignore the newline character after t

    while (t--) {
        string input;
        getline(cin, input); // Read the entire line for the array elements

        stringstream ss(input);
        Node *head = nullptr, *tail = nullptr;
        int x;

        if (ss >> x) {
            head = new Node(x);
            tail = head;

            while (ss >> x) {
                tail->next = new Node(x);
                tail = tail->next;
            }

            // Link the last node to the head if k is 1 to make it circular
            if (k == 1) {
                tail->next = head;
            }
        }

        Solution ob;
        Node* newHead = ob.segregate(head);
        printList(newHead);
        cout << "~" << endl;
    }

    return 0;
}
// } Driver Code Ends