class Solution {
private:
    int xx[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
    int yy[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
public:
    void gameOfLife(vector<vector<int>>& board) {
       vector<vector<int>> vec = board;
       for(int x=0; x<board.size(); x++){
           for(int y=0; y<board[x].size(); y++){
               int dead = 0, live = 0;
               for(int t=0; t<8; t++){
                   int tx = x+xx[t];
                   int ty = y+yy[t];
                   if(tx<0 || tx>=board.size() || ty<0 || ty>=board[x].size()) continue;
                   if(board[tx][ty]==1){
                       live++;
                   }else{
                       dead++;
                   }
               }
               if(board[x][y]==1){
                   if(live<2 || live>3) vec[x][y] = 0;
               }else{
                   if(live==3) vec[x][y] = 1;
               }
           }
       }
       board = vec;
    }
};