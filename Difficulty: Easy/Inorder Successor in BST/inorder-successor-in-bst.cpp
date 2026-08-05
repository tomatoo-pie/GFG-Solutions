/*
Definition for Node
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};
*/

class Solution {
  public:
    int inOrderSuccessor(Node *root, Node *k) {
        // code here
        Node* successor = nullptr;
        
        while(root!=nullptr){
            if(k->data >= root->data){
                root = root->right;
            }else{
                successor = root;
                root = root->left;
            }
        }
        
        if(successor)return successor->data;
        return -1;
    }
};