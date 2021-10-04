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
    int countNodes(TreeNode* root) {
        if(!root) return 0;
        TreeNode *l = root->left;
        int leftLevel = 1;
        while(l){
            l = l->left;
            leftLevel++;
        }
        TreeNode *r = root->right;
        int rightLevel = 1;
        while(r){
            r = r->right;
            rightLevel++;
        }
        if(leftLevel == rightLevel){
            return pow(2,leftLevel)-1;
        }
        return 1+countNodes(root->left)+countNodes(root->right);
    }
};