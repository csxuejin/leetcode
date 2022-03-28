class NumMatrix {
private:
    vector<vector<int>> dp;
public:
    NumMatrix(vector<vector<int>> &matrix) {
        if(matrix.empty()) return;
        int row = matrix.size();
        int col = matrix[0].size();
        dp.assign(row,vector<int>(col,0));
        dp[0][0] = matrix[0][0];
        for(int i=1; i<col; i++){
            dp[0][i] = dp[0][i-1]+matrix[0][i];
        }
        for(int i=1; i<row; i++){
            dp[i][0] = dp[i-1][0] + matrix[i][0];
        }
        for(int i=1; i<row; i++){
            for(int j=1; j<col; j++){
                dp[i][j] =matrix[i][j]+ dp[i-1][j] + dp[i][j-1] - dp[i-1][j-1];
            }
        }
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        int res =  dp[row2][col2];
        if(row1>0){
            res -= dp[row1-1][col2];
        }
        if(col1>0){
            res -= dp[row2][col1-1];
        }
        if(row1>0 && col1>0){
            res += dp[row1-1][col1-1];
        }
        return res;
    }
};


// Your NumMatrix object will be instantiated and called as such:
// NumMatrix numMatrix(matrix);
// numMatrix.sumRegion(0, 1, 2, 3);
// numMatrix.sumRegion(1, 2, 3, 4);