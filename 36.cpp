class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
      int row[9][9] = {0};
        int col[9][9] = {0};
        int sub[3][3][9] = {0};

        for(int i=0; i<9; i++){
            for(int j=0; j<9; j++){
                char ch = board[i][j];
                if(ch != '.'){
                    int num = ch - '1';
                    if(row[i][num]++) return false;
                    if(col[j][num]++) return false;
                    if(sub[i/3][j/3][num]++) return false;
                }
            }
        }
        return true;
    }
};