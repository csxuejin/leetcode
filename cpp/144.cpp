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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> vec;
        helper(root, vec);
        return vec;
    }
    
    void helper(TreeNode *root, vector<int> &vec){
        if(!root) return;
        vec.push_back(root->val);
        helper(root->left, vec);
        helper(root->right, vec);
    }
};
