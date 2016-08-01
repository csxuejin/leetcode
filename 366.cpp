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
    vector<vector<int>> res;
public:
    vector<vector<int>> findLeaves(TreeNode* root) {
        getHeight(root);
        return res;
    }
    
    int getHeight(TreeNode* root){
        if(!root)   return 0;
        int leftHeight = getHeight(root->left);
        int rightHeight = getHeight(root->right);
        int maxHeight = max(leftHeight, rightHeight)+1;
        while(maxHeight>res.size()){
            res.push_back({});
        }
        res[maxHeight-1].push_back(root->val);
        return maxHeight;
    }
};