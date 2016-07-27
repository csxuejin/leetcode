class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount+1,-1);
        dp[0] = 0;
        for(int i=1; i<=amount; i++){
            for(int j=0; j<coins.size(); j++){
                if(i>=coins[j] && dp[i-coins[j]]!=-1)
                   dp[i] = dp[i]>0? min(dp[i],dp[i-coins[j]]+1):dp[i-coins[j]]+1;
            }
        }
        return dp[amount];
    }
};