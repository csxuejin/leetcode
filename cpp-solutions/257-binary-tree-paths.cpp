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
    vector<string> res;
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        helper(root, "");
        return res;
    }
    
    void helper(TreeNode* root, string path){
        if(!root) 
            return;
        path = path==""? to_string(root->val) : path+"->"+to_string(root->val);
        if(!root->left && !root->right){
            res.push_back(path);
        }
       
        helper(root->left, path);
        helper(root->right, path);
    }
};
