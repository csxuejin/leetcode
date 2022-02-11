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
    int res = 0;
    
    int dfs(TreeNode* root){
        if(!root){
            return 0;
        }
        int leftMaxLen = dfs(root->left);
        int rightMaxLen = dfs(root->right);
        res = max(res, leftMaxLen + rightMaxLen);
        return max(leftMaxLen, rightMaxLen) + 1;
    }
    

    int diameterOfBinaryTree(TreeNode* root) {
        dfs(root);
        return res;
    }
};