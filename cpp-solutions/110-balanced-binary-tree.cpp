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
    bool isBalanced(TreeNode* root) {
        if(!root) return true;
        if(abs(getHeight(root->left,1) - getHeight(root->right,1) ) > 1){
            return false;
        }
        return isBalanced(root->left) && isBalanced(root->right);
    }
    
    int getHeight(TreeNode* root, int dep){
        if(!root){
            return dep;
        }
        if(!root->left && !root->right){
            return dep+1;
        }
        return max(getHeight(root->left, dep+1), getHeight(root->right, dep+1));
    }
};





