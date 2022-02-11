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
    int result;
public:
    int findTilt(TreeNode* root) {
        if(!root){
            return 0;
        }

        postOrder(root);
        return result;
    }
    
    int postOrder(TreeNode* root){
        if(!root){
            return 0;
        }
        int leftSum = postOrder(root->left);
        int rightSum = postOrder(root->right);
        result += abs(leftSum - rightSum);
        return root->val + leftSum + rightSum;
    }
};
