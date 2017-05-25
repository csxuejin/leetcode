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
    int minDepth(TreeNode* root) {
        if (!root) return 0;
        result = INT_MAX; 
        dfs(root, 1);
        return result;
    }
    
    int dfs(TreeNode* root, int level){
         if(!root->left && !root->right){
            result = min(result, level);
            return;
         }

         if(root->left){
            dfs(root->left, level+1);
         }
         if(root->right){
            dfs(root->right, level+1);
         }
    }
};
