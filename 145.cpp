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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> vec;
        if(!root)
            return vec;
        helper(vec, root);
        return vec;
    }
    
    void helper(vector<int>&vec, TreeNode*root){
        if(root->left){
            helper(vec, root->left);
        }
        if(root->right){
            helper(vec, root->right);
        }
        vec.push_back(root->val);
    }
};