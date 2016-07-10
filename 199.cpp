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
    vector<int> rightSideView(TreeNode* root) {
        levelOrder(root,1);        
        vector<int> vec;
        for (int i=0; i<res.size(); i++){
            vec.push_back(res[i].back());
        }
        return vec;
    }
    
    void levelOrder(TreeNode *root, int level){
        if(!root) return;
        if(res.size()<level){
            res.push_back(vector<int>());
        }
        res[level-1].push_back(root->val);
        levelOrder(root->left, level+1);
        levelOrder(root->right, level+1);
    }
};