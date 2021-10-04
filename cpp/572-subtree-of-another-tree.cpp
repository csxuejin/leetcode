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
    bool isSubtree(TreeNode* s, TreeNode* t) {
        return isSame(s, t) || (s && isSubtree(s->left, t)) || (s && isSubtree(s->right, t)) ;
    }
    
    bool isSame(TreeNode* a, TreeNode*b){
        if (!a && !b){
            return true;
        }
        
        if( (!a&&b) || (a&&!b) || (a->val!=b->val) ){
            return false;
        }
        return isSame(a->left, b->left) && isSame(a->right, b->right);
    }
};