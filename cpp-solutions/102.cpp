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
    vector<vector<int> > res;
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        bfs(root, 1);
        return res;
    }
    
    void bfs(TreeNode* root, int level){
        if(!root) return;
        if(res.size() < level){
            res.push_back(vector<int>());
        }
        res[level-1].push_back(root->val);
        bfs(root->left, level+1);
        bfs(root->right, level+1);
    }
};