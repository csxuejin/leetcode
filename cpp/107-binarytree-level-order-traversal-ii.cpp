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
    vector< vector<int> > res;
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        helper(root, 1);
        reverse(res.begin(), res.end());
        return res;
    }
    
    void helper(TreeNode* root, int level){
        if (root==NULL) return;
        if(res.size() < level){
            res.push_back(vector<int>());
        }
        res[level-1].push_back(root->val);
        helper(root->left, level+1);
        helper(root->right, level+1);
    }
};