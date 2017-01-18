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
    vector<int> vec;
public:
    int kthSmallest(TreeNode* root, int k) {
        if(!root) return 0;
        inOrder(root, k);
        return vec.back();
    }
    
    void inOrder(TreeNode *root, int k){
         if(root->left){
             inOrder(root->left, k);
         }
         if(vec.size()==k) return;
         
         vec.push_back(root->val);
         if(vec.size()==k) return;
         
         if(root->right){
             inOrder(root->right, k);
         }
    }
};
