//{ Driver Code Starts
// C++ program to merge k sorted arrays of size n each
#include <bits/stdc++.h>
using namespace std;

// A Linked List node
struct Node {
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

/* Function to print nodes in a given linked list */
void printList(Node* node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    cout << endl;
}


// } Driver Code Ends
/*Linked list Node structure

struct Node
{
    int data;
    Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }

};
*/

class Solution {
  public:
  struct Compare {
    bool operator()(Node* a, Node* b) {
        return a->data > b->data; // Min-heap based on value
    }
};

Node* mergeKLists(vector<Node*>& arr) {
    int n = arr.size();
    if (n == 0) return NULL;

    priority_queue<Node*, vector<Node*>, Compare> q;

    // Push the head of each list into the priority queue
    for (int i = 0; i < n; i++) {
        if (arr[i] != NULL) {
            q.push(arr[i]);
        }
    }

    Node* dummy = new Node(-1); 
    Node* tail = dummy; 

    while (!q.empty()) {
        Node* frontNode = q.top();
        q.pop();

        tail->next = frontNode;
        tail = tail->next;

        if (frontNode->next) {
            q.push(frontNode->next);
        }
    }

    return dummy->next; 
}
};


//{ Driver Code Starts.

// Driver program to test the above functions
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        int n;
        cin >> n;
        cin.ignore();

        vector<Node*> v(n);

        for (int i = 0; i < n; i++) {
            string line;
            getline(cin, line);
            stringstream ss(line);

            Node* head = new Node(0);
            Node* temp = head;
            int x;
            while (ss >> x) {
                Node* newNode = new Node(x);
                temp->next = newNode;
                temp = temp->next;
            }
            v[i] = head->next;
        }

        Solution ob;
        Node* head = ob.mergeKLists(v);
        printList(head);
    }

    return 0;
}

// } Driver Code Ends