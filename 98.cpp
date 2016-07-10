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
    bool isValidBST(TreeNode* root) {
        return valid(root, NULL, NULL);
    }
    
    bool valid(TreeNode *root, TreeNode *minNode, TreeNode *maxNode){
        if(!root) return true;
        if(minNode && root->val <= minNode->val ||maxNode && root->val >= maxNode->val ) return false;
        return valid(root->left, minNode, root) && valid(root->right, root, maxNode);
    }
};