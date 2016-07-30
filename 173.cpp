/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class BSTIterator {
private:
    stack<TreeNode*> sta;
public:
    void findLeft(TreeNode *root){
        while(root){
            sta.push(root);
            root = root->left;
        }
    }

    BSTIterator(TreeNode *root) {
        findLeft(root);
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        return !sta.empty();
    }

    /** @return the next smallest number */
    int next() {
        TreeNode *t = sta.top();
        sta.pop();
        if(t->right){
            findLeft(t->right);
        }
        return t->val;
    }
};

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */