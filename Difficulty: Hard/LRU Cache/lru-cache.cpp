//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// design the class in the most optimal way

class LRUCache {
public:
    class Node {
    public:
        int key;
        int val;
        Node* next;
        Node* prev;

        Node(int k, int v) {
            key = k;
            val = v;
            next = NULL;
            prev = NULL;
        }
    };

private:
    map<int, Node*> mp;
    Node* head;
    Node* tail;
    int c;

    void delete_Node(Node* d) {
        Node* prev = d->prev;
        Node* next = d->next;
        prev->next = next;
        next->prev = prev;
    }

    void add(Node* node) {
        Node* next = head->next;
        head->next = node;
        node->prev = head;
        node->next = next;
        next->prev = node;
    }

public:
    LRUCache(int capacity) {
        c = capacity;
        head = new Node(-1, -1);
        tail = new Node(-1, -1);
        head->next = tail;
        tail->prev = head;
    }

    // Function to return value corresponding to the key.
    int get(int key) {
        if (mp.find(key) != mp.end()) {
            Node* node = mp[key];
            int result = node->val;

            // Move the accessed node to the front (most recently used)
            delete_Node(node);
            add(node);

            return result;
        }
        return -1;
    }

    // Function for storing key-value pair.
    void put(int key, int value) {
        if (mp.find(key) != mp.end()) {
            // Key already exists; update its value and move it to the front
            Node* node = mp[key];
            delete_Node(node);
            mp.erase(key);
        } else if (mp.size() == c) {
            // Cache is full; remove the least recently used (LRU) node
            mp.erase(tail->prev->key);
            delete_Node(tail->prev);
        }

        // Add the new node to the front
        Node* newNode = new Node(key, value);
        add(newNode);
        mp[key] = newNode;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {

        int capacity;
        cin >> capacity;
        LRUCache *cache = new LRUCache(capacity);

        int queries;
        cin >> queries;
        while (queries--) {
            string q;
            cin >> q;
            if (q == "PUT") {
                int key;
                cin >> key;
                int value;
                cin >> value;
                cache->put(key, value);
            } else {
                int key;
                cin >> key;
                cout << cache->get(key) << " ";
            }
        }
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends