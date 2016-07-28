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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if(inorder.empty())
            return NULL;
        return build(inorder, postorder, 0, postorder.size()-1, 0, inorder.size()-1);
    }
    
    TreeNode* build(vector<int>& inorder, vector<int>& postorder, int pStart, int pEnd, int iStart, int iEnd){
        TreeNode *root = new TreeNode(postorder[pEnd]);
        int i;
        for(i=iStart; i<=iEnd; i++){
            if(inorder[i]==postorder[pEnd]){
                break;
            }
        }
        int leftLen = i-iStart;
        int rightLen = iEnd-i;
        if(leftLen>0){
            root->left = build(inorder, postorder, pStart, pStart+leftLen-1, iStart, i-1);
        }
        if(rightLen>0){
            root->right = build(inorder, postorder, pStart+leftLen, pEnd-1, i+1, iEnd);
        }
        return root;
    }
};

