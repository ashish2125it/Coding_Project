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
   if(!head || head->next==NULL ) return head;
   
   int zero=0,one=0,two =0;
   Node* temp = head;
   while(temp)
   {
       if(temp->data==0)
       zero++;
       else if(temp->data==1) 
       one++;
       else
       two++;
       
       temp = temp->next;
   }
   
   Node* dummy = new Node(-1);
   Node* t = dummy;
   
//   -1 -> 0   0 
//     t    t    z
   
   while(zero)
   {
       Node* z = new Node(0);
       t->next = z;
       t = z;
       zero--;
   }
   
   while(one)
   {
       Node* z = new Node(1);
       t->next = z;
       t = z;
       one--;
   }
   
   while(two)
   {
       Node* z = new Node(2);
       t->next = z;
       t = z;
       two--;
   }
   
   return dummy->next;
   
   
   
   
        
    }
};