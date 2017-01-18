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
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> res;
        helper(res, "", root);
        return res;
    }
    
    void helper(vector<string> &res, string path, TreeNode* root){
        if(root == NULL) 
            return;
        path = path==""? to_string(root->val) : path+"->"+to_string(root->val);
        if(root->left == NULL && root->right == NULL){
            res.push_back(path);
        }
       
        helper(res, path, root->left);
        helper(res, path, root->right);
    }
};