/* Structure of linked list Node
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
    Node* Reverse(Node* head){
        Node* prev = nullptr;
        Node* curr = head;
        
        while(curr){
            Node* nxt = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nxt;
        }
        
        head = prev;
        return head;
    }
    
    Node* addOne(Node* head) {
        // code here
        head = Reverse(head);
        
        Node* temp = head;
        Node* last = nullptr;

        while(temp && (temp->data + 1) % 10 == 0) {
            temp->data = 0;
            last = temp;
            temp = temp->next;
        }

        if(temp == nullptr) {
            last->next = new Node(1);
        }
        else {
            temp->data += 1;
        }

        head = Reverse(head);
        
        return head;
    }
};