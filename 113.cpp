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
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        helper(vector<int>(), root, sum);
        return res;
    }
    
    void helper(vector<int> vec, TreeNode* root, int sum){
        if(!root) return;
        sum -= root->val;
        vec.push_back(root->val);
        if(sum == 0 && !root->left && !root->right){
            res.push_back(vec);
            return;
        }
        helper(vec, root->left, sum);
        helper(vec, root->right, sum);
    }

};