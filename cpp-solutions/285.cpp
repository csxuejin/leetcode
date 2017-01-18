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
    bool find, done;
    TreeNode *tar;
    TreeNode *ans;
    
public:
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        find = done = false;
        tar = p;
        ans = NULL;
        inorder(root);
        return ans;
    }
    
    void inorder(TreeNode* root){
        if(root->left){
            inorder(root->left);
        }
        if(find){
            if(!done){
                 done = true;
                 ans = root;
            }
            return;
        }
        if(root==tar){
            find = true;
        }        
        if(root->right){
            inorder(root->right);
        }
    }
};


