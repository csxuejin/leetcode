class Solution {
public:
    int minDistance(string word1, string word2) {
        if(word1.empty()) return word2.size();
        if(word2.empty()) return word1.size();
        vector<vector<int>> dp(word2.size()+1, vector<int>(word1.size()+1));
        dp[0][0] = 0;
        for(int i=0; i<word1.size(); i++){
            dp[0][i+1] = i+1;
        }
        for(int i=0; i<word2.size(); i++){
            dp[i+1][0] = i+1;
        }
        for(int i=1; i<dp.size(); i++){
            for(int j=1; j<dp[i].size(); j++){
                int t = word1[j-1]==word2[i-1]?0:1;
                dp[i][j] = min(dp[i-1][j-1]+t, min(dp[i-1][j], dp[i][j-1])+1);
            }
        }
        return dp.back().back();
    }
};
