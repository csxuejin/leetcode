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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        helper(root, 1);
        for (int i=0; i<res.size(); i++){
            if(i%2!=0){
                reverse(res[i].begin(), res[i].end());
            }
        }
        return res;
    }
    
    void helper(TreeNode *root, int level){
        if(!root) return;
        if(res.size() < level)
            res.push_back(vector<int>());
        res[level-1].push_back(root->val);
        helper(root->left, level+1);
        helper(root->right, level+1);
    }
}; 


