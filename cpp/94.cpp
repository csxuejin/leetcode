/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> vec;
        helper(vec, root);
        return vec;
    }
    
    void helper(vector<int>&vec, TreeNode *root){
        if(!root) return;
        helper(vec, root->left);
        vec.push_back(root->val);
        helper(vec, root->right);
    }
};