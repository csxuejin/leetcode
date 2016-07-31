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
    int closestValue(TreeNode* root, double target) {
        if(!root)
            return 0;
        if(root->val == target || !root->left && !root->right){
            return root->val;
        }
        // find the left subtree;
        if(root->val > target && root->left){
            if(abs(target-root->val)<abs(target-closestValue(root->left, target))){
                return root->val;
            }else{
                return closestValue(root->left, target);
            }
        }
        // find the right subtree;
        if(abs(target-root->val) < abs(target-closestValue(root->right, target))){
            return root->val;
        }
        return closestValue(root->right, target);
    }
};