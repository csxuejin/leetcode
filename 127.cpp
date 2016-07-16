class Solution {
private:
    void addNextWord(string &word, unordered_set<string>& wordList, queue<string>&visit){
        wordList.erase(word);
        for(int p=0; p<word.size(); p++){
            char ch = word[p];
            for(int i=0; i<26; i++){
                word[p] = 'a' + i;
                if(wordList.find(word)!=wordList.end()){
                    visit.push(word);
                    wordList.erase(word);
                }
            }
            word[p] = ch;
        }
    }
public:
    int ladderLength(string beginWord, string endWord, unordered_set<string>& wordList) {
        if(beginWord == endWord) return 0;
        wordList.insert(endWord);
        queue<string> visit;
        addNextWord(beginWord, wordList, visit);
        int step = 2;
        while(!visit.empty()){
            int num = visit.size();
            for(int i=0; i<num; i++){
                string word = visit.front();
                if(word==endWord){
                    return step;
                }
                visit.pop();
                addNextWord(word, wordList, visit);
            }
            step++;
        }
        return 0;
    }
};

