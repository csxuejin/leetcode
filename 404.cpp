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
    int sumOfLeftLeaves(TreeNode* root) {
        if(!root) return 0;
        return help(root->left, true) + help(root->right, false);
    }
    
    int help(TreeNode* root, bool isLeft){
        if(!root) return 0;
        if(root && isLeft && !root->left && !root->right){
            return root->val;
        }
        return help(root->left, true) + help(root->right, false);
    }
};

