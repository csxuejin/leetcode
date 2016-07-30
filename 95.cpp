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
    vector<TreeNode*> generateTrees(int n) {
        if(n==0) return vector<TreeNode*>(0);
        return generateSubtrees(1,n);
    }
    
    vector<TreeNode*> generateSubtrees(int from, int to){
        if(from>to) return vector<TreeNode*>(1,NULL);
        if(from == to)  
            return vector<TreeNode*>(1,new TreeNode(from));
        vector<TreeNode*> res;
        for(int i=from; i<=to; i++){
            vector<TreeNode*> leftTree = generateSubtrees(from, i-1);
            vector<TreeNode*> rightTree = generateSubtrees(i+1, to);
            for(int j=0; j<leftTree.size(); j++){
                for(int k=0; k<rightTree.size(); k++){
                    TreeNode *root = new TreeNode(i);
                    root->left = leftTree[j];
                    root->right = rightTree[k];
                    res.push_back(root);
                }
            }
        }
        return res;
    }
};
