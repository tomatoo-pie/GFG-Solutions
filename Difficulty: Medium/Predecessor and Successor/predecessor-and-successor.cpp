/* Structure of a Binary Search Tree node
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int x) {
        data = x;
        left = nullptr;
        right = nullptr;
    }
}; */

class Solution {
  public:
    vector<Node*> findPreSuc(Node* root, int key) {
        // code here
        Node* p = nullptr;
        
        Node* s = nullptr;
        
        Node* temp = root;
        
        while(temp){
            if(key >= temp->data){
                temp = temp->right;
            }
            else{
                s = temp;
                temp = temp->left;
            }
        }
        
        while(root){
            if(key > root->data){
                p = root;
                root = root->right;
            }
            else{
                root = root->left;
            }
        }
        
        return {p,s};
    }
};