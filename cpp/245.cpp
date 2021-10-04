class Solution {
private:
    unordered_map<string, vector<int>> wordMap;
public:
    void wordDistance(vector<string>& words) {
        for(int i=0;i<words.size();i++)
            wordMap[words[i]].push_back(i);
    }
    
    int shortestWordDistance(vector<string>& words, string word1, string word2) {
        wordDistance(words);
        int i=0, j=0, dist=INT_MAX;
        if(word1==word2){
            for(i=0,j=1; i<wordMap[word1].size() && j<wordMap[word2].size(); i++,j++){
                dist = min(dist, abs(wordMap[word1][i]-wordMap[word2][j]));
            }
        }else{
            while(i < wordMap[word1].size() && j <wordMap[word2].size()) { 
                dist = min(dist, abs(wordMap[word1][i] - wordMap[word2][j]));
                wordMap[word1][i]<wordMap[word2][j]?i++:j++;
            }
        }
        return dist;
    }
};
