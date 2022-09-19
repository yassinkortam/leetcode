/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
private: //avoiding messy c++ vector returns
    vector <int> values;
    void inorder(TreeNode* root); 
public:
    vector<int> inorderTraversal(TreeNode* root);
};

void Solution::inorder(TreeNode* root){
    //base case: root->val is null, return
    //return the traversal of left and right values
    if (root != nullptr){
        inorderTraversal(root->left);
        values.push_back(root->val);
        inorderTraversal(root->right); 
    }
}

vector<int> Solution::inorderTraversal(TreeNode* root){
    inorder(root);
    return values;
}
