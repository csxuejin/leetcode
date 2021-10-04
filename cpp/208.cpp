class TrieNode {
public:
    char ch;
    bool isEnd;
    vector<TrieNode*> sons;
    // Initialize your data structure here.
    TrieNode():ch(' '), isEnd(false) {}
    TrieNode(char t):ch(t), isEnd(false){}
    TrieNode* subNode(char t){
        if(!sons.empty()){
            for(auto it:sons){
                if(it->ch == t){
                    return it;
                }
            }
        }
        return NULL;
    }
};

class Trie {
public:
    Trie() {
        root = new TrieNode();
    }

    // Inserts a word into the trie.
    void insert(string word) {
        if(search(word)) return;
        TrieNode* cur = root;
        for(auto ch:word){
            TrieNode* tSon = cur->subNode(ch);
            if(!tSon){
               TrieNode* newNode = new TrieNode(ch);
               cur->sons.push_back(newNode);
               cur = newNode;
            }else{
                cur = tSon;
            }
        }
        cur->isEnd = true;
    }

    // Returns if the word is in the trie.
    bool search(string word) {
        TrieNode* cur = root;
        for(auto ch:word){
            cur = cur->subNode(ch);
            if(!cur) return false;
        }
        return cur->isEnd;
    }

    // Returns if there is any word in the trie
    // that starts with the given prefix.
    bool startsWith(string prefix) {
        TrieNode* cur = root;
        for(auto ch:prefix){
            cur = cur->subNode(ch);
            if(!cur) return false;
        }
        return true;
    }

private:
    TrieNode* root;
};

// Your Trie object will be instantiated and called as such:
// Trie trie;
// trie.insert("somestring");
// trie.search("key");