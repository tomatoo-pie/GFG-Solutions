/* Structure of a Tree Node
class Node {
public:
    int data;
    Node* left, *right;
    Node(int val) {
        data = val;
        left = right = nullptr;
    }
}; */

class Solution {
  public:
    bool isSumProperty(Node *root) {
        // code here
        if(root==nullptr)return true;
        
        if (root->left == nullptr && root->right == nullptr)
            return true;
        
        int left = 0 , right = 0;
        
        if(root->right) right = root->right->data;
        if(root->left) left = root->left->data;
        
        return (root->data == left+right && isSumProperty(root->left) && isSumProperty(root->right));
    }
};