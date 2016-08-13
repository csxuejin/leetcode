class Solution {
private: 
    int xx[4] = {0, 1, 0, -1};
    int yy[4] = {-1, 0, 1, 0};
    int row, col;
    int left, right, top, bottom;
public:
    void bfs(int x, int y, vector<vector<bool>>& visited, vector<vector<char>>& image){
        left = min(left, y);
        right = max(right, y);
        top = min(top, x);
        bottom = max(bottom, x);
        
        visited[x][y] = true;
        for(int i=0; i<4; i++){
            int tx = x+xx[i];
            int ty = y+yy[i];
            if(tx>=0 && tx<row && ty>=0 && ty<col && !visited[tx][ty] && image[tx][ty]=='1'){
                bfs(tx, ty, visited, image);
            }
        }
    }

    int minArea(vector<vector<char>>& image, int x, int y) {
        row = image.size();
        col = image[0].size();
        left=col-1, right=0, top=row-1, bottom=0;
        vector<vector<bool>> visited(row, vector<bool>(col, false));
        bfs(x, y, visited, image);
        return (right-left+1)*(bottom-top+1);
    }
};


