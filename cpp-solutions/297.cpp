/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(!root) return "";
        string str;
        serHelper(root, str);
        return str;
    }
    
    void serHelper(TreeNode* root, string &str){
        if(root){
            str += to_string(root->val) + " ";
            serHelper(root->left, str);
            serHelper(root->right, str);
        }else{
            str += "null ";
        }
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.empty())
            return NULL;
        istringstream in(data);
        return desHelper(in);
    }
    
    TreeNode* desHelper(istringstream& in){
        string str;
        in>>str;
        if(str=="null"){
            return NULL;
        }
        TreeNode *root = new TreeNode(stoi(str));
        root->left = desHelper(in);
        root->right = desHelper(in);
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));