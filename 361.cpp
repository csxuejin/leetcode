class Solution {
public:
    int maxKilledEnemies(vector<vector<char>>& grid) {
        int row = grid.size();
        if(!row) return 0;
        int col = row? grid[0].size():0;
        int result = 0, rowHit = 0;
        vector<int> colHit(col);
        for(int i=0; i<row; i++){
            for(int j=0; j<col; j++){
                if(j==0 || grid[i][j-1]=='W'){
                    rowHit = 0;
                    for(int t=j; t<col&&grid[i][t]!='W'; t++){
                        rowHit += grid[i][t]=='E';
                    }    
                }
                
                if(i==0 || grid[i-1][j]=='W'){
                    colHit[j]=0;
                    for(int t=i; t<row && grid[t][j]!='W'; t++){
                        colHit[j] += grid[t][j] == 'E';
                    }
                }
                
                if(grid[i][j]=='0'){
                    result = max(result, rowHit + colHit[j]);
                }
            }
        }
        return result;
    }
};
