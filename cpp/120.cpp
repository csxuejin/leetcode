class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        if(triangle.empty()) return 0;
        if(triangle.size()==1) return triangle[0][0];
        int row = triangle.size();
        vector<vector<int>> dp(row);
        dp[0].push_back(triangle[0][0]);
        
        for(int i=1; i<row; i++){
            dp[i].push_back(dp[i-1][0] + triangle[i][0]);
            for(int j=1; j<triangle[i].size()-1; j++){
                dp[i].push_back( min(dp[i-1][j-1], dp[i-1][j]) + triangle[i][j]);
            }
            dp[i].push_back(dp[i-1].back() + triangle[i].back());
        }
        int res = INT_MAX;
        for(int i=0; i<dp[row-1].size(); i++){
            res = min(res, dp[row-1][i]);
        }
        return res;
    }
};