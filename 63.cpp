class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int row = obstacleGrid.size();
        if(row == 0) 
            return 0;
        int col = obstacleGrid[0].size();
        vector<vector<int>> dp(row, vector<int>(col,0));
        if(obstacleGrid[0][0])  
            return 0;
        dp[0][0] = 1;
        for(int i=1; i<col; i++){
            dp[0][i] = obstacleGrid[0][i]==1? 0:dp[0][i-1];
        }
        for(int i=1; i<row; i++){
            dp[i][0] = obstacleGrid[i][0]==1? 0:dp[i-1][0];
        }
        for(int i=1; i<row; i++){
            for(int j=1; j<obstacleGrid[i].size(); j++){
                dp[i][j] = obstacleGrid[i][j]==1? 0:dp[i-1][j]+dp[i][j-1];
            }
        }
        return dp[row-1][col-1];
    }
};