class Solution {
public:
    vector<vector<string>> findLadders(string start, string end, unordered_set<string> &dict) {
        vector<vector<string> > ladders;
        vector<string> ladder;
        ladder.push_back(start);
        unordered_set<string> startWords, endWords;
        startWords.insert(start);
        endWords.insert(end);
        unordered_map<string, vector<string> > children;
        bool flip = true;
        if (searchLadders(startWords, endWords, dict, children, flip))
            genLadders(start, end, children, ladder, ladders);
        return ladders;
    }
private:
    bool searchLadders(unordered_set<string>& startWords, unordered_set<string>& endWords, 
                 unordered_set<string>& dict, unordered_map<string, vector<string> >& children, bool flip) {
        flip = !flip;
        if (startWords.empty()) return false;
        if (startWords.size() > endWords.size())
            return searchLadders(endWords, startWords, dict, children, flip);
        
        for (string word : startWords) 
             dict.erase(word);
        for (string word : endWords) 
             dict.erase(word);

        unordered_set<string> intermediate;
        bool done = false;
        for (string word : startWords) {
            int n = word.length();
            string temp = word;
            for (int p = 0; p < n; p++) {
                char letter = word[p];
                for (int i = 0; i < 26; i++) {
                    word[p] = 'a' + i;
                    if (endWords.find(word) != endWords.end()) {
                        done = true;
                        flip ? children[word].push_back(temp) : children[temp].push_back(word);
                    }else if (!done && dict.find(word) != dict.end()) {
                        intermediate.insert(word);
                        flip ? children[word].push_back(temp) : children[temp].push_back(word);
                    }
                }   
                word[p] = letter;
            }
        }
        return done || searchLadders(endWords, intermediate, dict, children, flip);
    }

    void genLadders(string& start, string& end, unordered_map<string, vector<string> >& children, 
                    vector<string>& ladder, vector<vector<string> >& ladders) {
        if (start == end) {
            ladders.push_back(ladder);
            return;
        }
        for (string child : children[start]) {
            ladder.push_back(child);
            genLadders(child, end, children, ladder, ladders);
            ladder.pop_back();
        }
    }
};

