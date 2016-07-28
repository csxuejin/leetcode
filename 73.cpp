class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        vector<int> row(matrix.size(),1);
        vector<int> col(matrix[0].size(),1);
        for(int i=0; i<matrix.size(); i++){
            for(int j=0; j<matrix[i].size(); j++){
                if(matrix[i][j]==0){
                    row[i]=0;
                    col[j]=0;
                }
            }
        }
        for(int i=0; i<matrix.size(); i++){
            if(row[i]==0){
                matrix[i].assign(matrix[i].size(),0);
                continue;
            }
            for(int j=0; j<matrix[i].size(); j++){
                if(col[j]==0){
                    matrix[i][j] = 0;
                }
            }
        }
    }
};