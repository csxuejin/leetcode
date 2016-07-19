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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return helper(preorder, 0, inorder, 0, preorder.size());
    }
    
    TreeNode* helper(vector<int>& preorder, int pos1, vector<int>& inorder, int pos2, int len){
        if(preorder.size() == 0)
            return NULL;
        if(preorder.size() == 1) 
            return new TreeNode(preorder[pos1]);
        TreeNode *root = new TreeNode(preorder[pos1]);
        cout<<"pos1="<<pos1<<endl;
        int leftLen = 0;
        for(int i=pos2; i<inorder.size(); i++){
            if(inorder[i] == root->val) 
                break;
            leftLen++;
        }
        if(leftLen>0)
            root->left = helper(preorder, pos1+1, inorder, pos2, leftLen);
        int rightLen = len-leftLen-1;
        if(rightLen> 0)
            root->right = helper(preorder, pos1+1+leftLen, inorder, pos2+leftLen+1, rightLen);
        return root;
    }
};

