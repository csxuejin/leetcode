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
    int sumNumbers(TreeNode* root) {
        return helper(root, 0);
    }
    
    int helper(TreeNode *root, int sum){
        if(!root){
            return 0;
        }
        sum = sum*10 + root->val;
        if(!root->left && !root->right){
            return sum;
        }
        return helper(root->left, sum) + helper(root->right, sum);
    }
};