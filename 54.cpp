class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        int row = matrix.size();
        if(row==0) return res;
        if(row==1) return matrix[0];
        int col = matrix[0].size();
        int top=0, low=row-1, left=0, right=col-1;
        int cnt = row*col;
        
        while(res.size() <cnt){
            // from left to right
            for(int i=left; i<=right; i++){
                res.push_back(matrix[top][i]);
            }
            if(res.size()==cnt) break;
            top++;
            
            // from top to low
            for(int i=top; i<=low; i++){
                res.push_back(matrix[i][right]);
            }
            if(res.size()==cnt) break;
            right--;
            
            // from right to left
            for(int i=right; i>=left; i--){
                res.push_back(matrix[low][i]);
            }
            if(res.size()==cnt) break;
            low--;
            
            // from low to top
            for(int i=low; i>=top; i--){
                res.push_back(matrix[i][left]);
            }
            left++;
        }
        return res;
    }
};

