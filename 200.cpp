class Solution {
private:
        int xx[4] = {0, 1, 0, -1};
        int yy[4] = {1, 0, -1, 0};
        int row, col;
public:
    int numIslands(vector<vector<char>>& grid) {
        int cnt = 0;
        row = grid.size();
        if(row==0) 
            return 0;
        col = grid[0].size();
        vector< vector<bool> > visit(row, vector<bool>(col,false));
        for(int i=0; i<grid.size(); i++){
            for(int j=0; j<grid[i].size(); j++){
                if(!visit[i][j] && grid[i][j]=='1'){
                    bfs(grid, visit, i, j);
                    cnt++;
                }
            }
        }
        return cnt;
    }
    
    void bfs(vector<vector<char>>&grid, vector<vector<bool>> &visit, int x, int y){
        visit[x][y] = true;
        for(int i=0; i<4; i++){
            int tx = x + xx[i];
            int ty = y + yy[i];
            if(tx>=0 && tx<row && ty>=0 && ty<col && !visit[tx][ty] && grid[tx][ty]=='1')
                bfs(grid, visit, tx, ty);
        }
    }
};
