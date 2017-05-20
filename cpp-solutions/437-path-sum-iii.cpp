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
    int pathSum(TreeNode* root, int sum) {
        if(!root){
            return 0;
        }
        return sumHelper(0, sum, root) + pathSum(root->left, sum) + pathSum(root->right, sum);
    }
    
    int sumHelper(int curVal, int sum, TreeNode*root){
        if(!root){
            return 0;
        }
        curVal += root->val;
        return (curVal==sum) + sumHelper(curVal, sum, root->left) + sumHelper(curVal, sum, root->right);
    }
};

