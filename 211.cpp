class TrieNode{
public:
    char ch;
    bool isEnd;
    vector<TrieNode*> sons;
    TrieNode() : ch(' '), isEnd(false){}
    TrieNode(char t) : ch(t), isEnd(false){}
    TrieNode* subNode(char t){
        for(auto it:sons){
            if(it->ch==t){
                return it;
            }
        }
        return NULL;
    }
};

class WordDictionary {
private:
    TrieNode* root;
public:
    WordDictionary(){
        root = new TrieNode();
    }

    // Adds a word into the data structure.
    void addWord(string word) {
        if(search(word)) return;
        TrieNode* cur = root;
        for(auto it:word){
            TrieNode* son = cur->subNode(it);
            if(!son){
                TrieNode* newNode = new TrieNode(it);
                cur->sons.push_back(newNode);
                cur = newNode;
            }else{
                cur = son;
            }
        }
        cur->isEnd = true;
    }

    // Returns if the word is in the data structure. A word could
    // contain the dot character '.' to represent any one letter.
    bool search(string word) {
        return helper(word, root);
    }
    
    bool helper(string word, TrieNode* cur){
        if(word.size()==0) return cur->isEnd;
        for(int i=0; i<word.size(); i++){
            char it = word[i];
            if(it=='.'){
                string tStr = i==word.size()-1? "":word.substr(i+1);
                for(auto son:cur->sons){
                    if(helper(tStr, son)) return true;
                }
                return false;
            }else{
                TrieNode* tSon = cur->subNode(it);
                if(!tSon){
                    return false;
                }else{
                    cur = tSon;
                }
            }
        }
        return cur->isEnd;
    }
};

// Your WordDictionary object will be instantiated and called as such:
// WordDictionary wordDictionary;
// wordDictionary.addWord("word");
// wordDictionary.search("pattern");