//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node* next;
    struct Node* bottom;

    Node(int x) {
        data = x;
        next = NULL;
        bottom = NULL;
    }
};

void printList(Node* head) {
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->bottom;
    }
    printf("\n");
}

Node* createLinkedList(vector<Node*>& v) {
    Node* head = new Node(0);
    Node* temp = head;
    int n = v.size();
    for (int i = 0; i < n; i++) {
        temp->next = v[i];
        temp = temp->next;
    }
    return head->next;
}


// } Driver Code Ends

/* Node structure  used in the program

struct Node{
    int data;
    struct Node * next;
    struct Node * bottom;

    Node(int x){
        data = x;
        next = NULL;
        bottom = NULL;
    }

};
*/

class Solution {
  public:
    // Function which returns the  root of the flattened linked list.
   Node* merge(Node* left, Node* right) {
        if (!left) return right;
        if (!right) return left;

        Node* temp = new Node(0); // Dummy node
        Node* ans = temp;

        while (left && right) {
            if (left->data < right->data) {
                temp->bottom = left;
                left = left->bottom;
            } else {
                temp->bottom = right;
                right = right->bottom;
            }
            temp = temp->bottom;
        }

        if (left) temp->bottom = left;
        if (right) temp->bottom = right;

        return ans->bottom; // Return merged list
    }

    // Function to flatten the linked list
    Node *flatten(Node *root) {
        if (!root || !root->next) return root;

        // Recursively flatten the rest of the list
        root->next = flatten(root->next);

        // Merge current list with the flattened next list
        root = merge(root, root->next);

        return root;
    }
};



//{ Driver Code Starts.

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
                temp->bottom = newNode;
                temp = temp->bottom;
            }
            v[i] = head->bottom;
        }

        Solution ob;
        Node* list = createLinkedList(v);
        Node* head = ob.flatten(list);
        printList(head);
        cout << "~" << endl;
    }

    return 0;
}

// } Driver Code Ends