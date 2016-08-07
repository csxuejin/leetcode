class Solution {
private:
    string tar;
    vector<vector<bool>> used;
    int xx[4] = {0,1,0,-1};
    int yy[4] = {-1,0,1,0};
    int row, col;
public:
    bool exist(vector<vector<char>>& board, string word) {
        tar = word;
        row = board.size();
        col = board[0].size();
        used.resize(row, vector<bool>(col, false));
        string str = "";
        for(int i=0; i<row; i++){
            for(int j=0; j<col; j++){
                if(board[i][j]==word[0] && !used[i][j]){
                    if(dfs(board, str, i, j, 0)){
                        return true;
                    }
                    used.clear();
                    used.resize(row, vector<bool>(col, false));
                }
            }
        }
        return false;
    }
    
    bool dfs(vector<vector<char>>& board, string& str, int x, int y, int pos){
        used[x][y] = true;
        str += board[x][y];
        if(str==tar){
            return true;
        }
        for(int i=0; i<4; i++){
            int tx = x + xx[i];
            int ty = y + yy[i];
            if( tx>=0 && tx<row && ty>=0 && ty<col && !used[tx][ty] && board[tx][ty]==tar[pos+1]){
                if(dfs(board, str, tx, ty, pos+1)){
                    return true;
                }
            }
        }
        str = str.substr(0,str.size()-1);
        used[x][y] = false;
        return false;
    }
};


