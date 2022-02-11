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
    vector< vector<int> > res;
public:
    int findBottomLeftValue(TreeNode* root) {
        if(!root){
            return 0;
        }
        levelOrder(root, 1);
        return res.back().front();
    }
    
    void levelOrder(TreeNode* root, int level){
        if(!root){
            return;
        }
        if(res.size() < level){
            res.push_back(vector<int>{});
        }
        res[level-1].push_back(root->val);
        levelOrder(root->left, level+1);
        levelOrder(root->right, level+1);
    }
};