class TrieNode{
public:
    bool isEnd;
    vector<TrieNode*> sons;
    TrieNode():isEnd(false), sons(vector<TrieNode*>(26, NULL)){};
};

class Trie{
private:
    TrieNode* root;
public:
    TrieNode* getRoot(){return root;}
    Trie(vector<string>& words){
        root = new TrieNode();
        for(auto it:words)
            addWord(it);
    }

    void addWord(string& word){
        TrieNode* cur = root;
        for(int i=0; i<word.size(); i++){
            int index = word[i]-'a';
            if(!cur->sons[index])
                cur->sons[index] = new TrieNode();
            cur = cur->sons[index];
        }
        cur->isEnd = true;
    }
};

class Solution {
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        Trie* trie = new Trie(words);
        TrieNode* root = trie->getRoot();

        for(int i=0; i<board.size(); i++)
            for(int j=0; j<board[i].size(); j++)
                findWords(board, i, j, root, "");

        vector<string> res;
        for(auto it:resSet)
            res.push_back(it);
        return res;
    }

private:
    set<string> resSet;
    void findWords(vector<vector<char>>& board, int x, int y, TrieNode* root, string word){
        if(x<0||x>=board.size() || y<0||y>=board[0].size() || board[x][y]==' ') return;

        int index = board[x][y]-'a';
        if(root->sons[index]){
            char ch = board[x][y];
            word += board[x][y];
            board[x][y] = ' ';
            root=root->sons[index];
            if(root->isEnd) resSet.insert(word);

            findWords(board, x+1, y, root, word);
            findWords(board, x-1, y, root, word);
            findWords(board, x, y-1, root, word);
            findWords(board, x, y+1, root, word);
            board[x][y] = ch;
        }
    }

};

