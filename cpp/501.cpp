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
    vector<int> res;
    int curVal;
    int curCount = 0;
    int maxCount = 0;
    vector<int> modes;
    
    vector<int> findMode(TreeNode* root) {
        inorder(root);
        return modes;
    }
    
    void handleValue(int val){
        if(curVal != val){
            curVal = val;
            curCount = 0;
        }
        curCount++;
        if(curCount > maxCount){
            modes.clear();
            modes.push_back(curVal);
            maxCount = curCount;
        }else if(curCount == maxCount) {
            modes.push_back(curVal);
        }
        return;
    }
    
    void inorder(TreeNode* root){
        if(!root){
            return;
        }
        inorder(root->left);
        handleValue(root->val);
        inorder(root->right);
        return;
    }
};
