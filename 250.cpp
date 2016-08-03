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
private:
    int cnt;

public:
    int countUnivalSubtrees(TreeNode* root) {
        cnt = 0;
        help(root);
        return cnt;
    }
    
    bool help(TreeNode *root){
        if(!root) return true;
        auto leftSub = help(root->left);
        auto rightSub = help(root->right);
        if(leftSub && rightSub
           && (!root->left || root->left->val==root->val)
           && (!root->right || root->right->val==root->val)
        ){
            cnt++;
            return true;
        }
        return false;
    }
    
};