class Solution {
public:
    int shortestDistance(vector<string>& words, string word1, string word2) {
        map<string, vector<int> > mm;
        for(int i=0; i<words.size(); i++){
            mm[words[i]].push_back(i);
        }
        int res = INT_MAX;
        for(int i=0;  i<mm[word1].size(); i++){
            for(int j=0; j<mm[word2].size(); j++){
                res = min(res, abs( mm[word1][i]-mm[word2][j]));
            }
        }
        return res;
        
    }
};