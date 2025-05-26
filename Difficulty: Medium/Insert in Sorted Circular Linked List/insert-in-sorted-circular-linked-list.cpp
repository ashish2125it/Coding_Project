/* structure for a node
class Node {
 public:
  int data;
  Node *next;

  Node(int x){
      data = x;
      next = NULL;
  }
}; */

class Solution {
  public:
    Node* sortedInsert(Node* head, int data) {
   Node* data_node = new Node(data);

        // Case 1: Empty list
        if (!head) {
            data_node->next = data_node;
            return data_node;
        }

        Node* curr = head;

        // Case 2: Insert before head (new smallest element)
        if (head->data >= data) {
            while (curr->next != head) {
                curr = curr->next;
            }
            curr->next = data_node;
            data_node->next = head;
            return data_node;  // new head
        }

        // Case 3: Insert in the middle or end
        while (curr->next != head && curr->next->data < data) {
            curr = curr->next;
        }

        data_node->next = curr->next;
        curr->next = data_node;

        return head;
        
    }
};