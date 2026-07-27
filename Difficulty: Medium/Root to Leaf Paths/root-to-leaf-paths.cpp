/* Definition for Node
class Node {
  public:
    int data;
    Node* left;
    Node* right;
    Node(int val) {
        data = val;
        left = right = nullptr;
    }
}; */

class Solution {
  public:
    bool isleaf(Node* root){
        return root->left == nullptr && root->right == nullptr;
    }
    
    void path(Node* root, vector<vector<int>> &ans, vector<int> &temp){
        if(root == nullptr)
            return;

        temp.push_back(root->data);

        if(isleaf(root)){
            ans.push_back(temp);
        }
        else{
            path(root->left, ans, temp);
            path(root->right, ans, temp);
        }

        temp.pop_back();   // backtracking
    }
    
    vector<vector<int>> paths(Node* root) {
        // code here
        vector<vector<int>> ans;
        vector<int> temp;
        path(root,ans,temp);
        return ans;
    }
};