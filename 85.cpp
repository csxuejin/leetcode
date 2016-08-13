class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if(matrix.empty()) return 0;
        int row = matrix.size();
        int col = matrix[0].size();
        vector<int> left(col,0);
        vector<int> right(col, col);
        vector<int> height(col,0);
        int ans = 0;
        for(int i=0; i<row; i++){
            for(int j=0; j<col; j++){
                height[j] = matrix[i][j]=='1'? height[j]+1:0;
            }
            
            int curLeft=0;
            for(int j=0; j<col; j++){
                if(matrix[i][j]=='1'){
                    left[j] = max(curLeft, left[j]);
                }else{
                    left[j]=0;
                    curLeft = j+1;
                }
            }
            
            int curRight=col;
            for(int j=col-1; j>=0; j--){
                if(matrix[i][j]=='1'){
                    right[j] = min(right[j], curRight);
                }else{
                    right[j] = col;
                    curRight = j;
                }
            }
            
            for(int j=0; j<col; j++)
                ans = max(ans, height[j]*(right[j]-left[j]));
            
        }
        return ans;
    }
};