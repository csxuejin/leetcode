class Solution {
public:
    int numSquares(int n) {
        vector<int> dp(n+1,0);
        for(int i=0; i<=n; i++){
            dp[i] = i;
            for(int j=0; j<=sqrt(i); j++){
                dp[i] = min(dp[i], dp[i-j*j]+1);
            }
        }
        return dp[n];
    }
};