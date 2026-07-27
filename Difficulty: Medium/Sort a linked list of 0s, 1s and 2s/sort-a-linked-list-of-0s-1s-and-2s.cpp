/* Node is defined as
  class Node {
  public:
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = nullptr;
    }
};
*/
class Solution {
  public:
    Node* segregate(Node* head) {
        // code here
        Node* dummy0 = new Node(0);
        Node* dummy1 = new Node(0);
        Node* dummy2 = new Node(0);
        Node* temp0 = dummy0;
        Node* temp1 = dummy1;
        Node* temp2 = dummy2;
        Node* temp = head;
        while(temp){
            if(temp->data==0){
                temp0->next = temp;
                temp0 = temp0->next;
            }
            if(temp->data==1){
                temp1->next = temp;
                temp1 = temp1->next;
            }
            if(temp->data==2){
                temp2->next = temp;
                temp2 = temp2->next;
            }
            temp = temp->next;
        }
        
        temp0->next = dummy1->next;
        if(dummy1->next==nullptr)temp0->next = dummy2->next;
        temp1->next = dummy2->next;
        if(dummy2->next == nullptr)temp1->next = nullptr;
        temp2->next = nullptr;
        
        head = dummy0->next;
        delete dummy0;
        delete dummy1;
        delete dummy2;
        
        return head;
    }
};