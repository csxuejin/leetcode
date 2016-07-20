/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void connect(TreeLinkNode *root) {
        vector<vector<TreeLinkNode*>> vec;
        bfs(root, 1, vec);
        for(int i=0; i<vec.size(); i++){
            for(int j=0; j<vec[i].size(); j++){
                if(j==vec[i].size()-1){
                    vec[i][j]->next == NULL;
                }else{
                    vec[i][j]->next = vec[i][j+1];
                }
            }
        }
    }
    
    void bfs(TreeLinkNode *root, int level, vector<vector<TreeLinkNode*>> &vec){
        if(!root) 
            return;
        if(vec.size()<level){
            vec.push_back(vector<TreeLinkNode*>{});
        }
        vec[level-1].push_back(root);
        bfs(root->left, level+1, vec);
        bfs(root->right, level+1, vec);
    }
};