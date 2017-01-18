class Solution {
public:
    vector<vector<int>> multiply(vector<vector<int>>& A, vector<vector<int>>& B) {
        int row = A.size();
        int col = B[0].size();
        vector<vector<int>> res(row, vector<int>(col,0));
        for(int i=0; i<row; i++){
            for(int j=0; j<A[0].size(); j++){
                if(A[i][j]){
                    for(int t = 0; t<col; t++){
                        if(B[j][t]){
                            res[i][t] += A[i][j] * B[j][t];
                        }
                    }
                }
            }
        }
        return res;
    }
};