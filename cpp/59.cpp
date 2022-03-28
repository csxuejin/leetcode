class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> vec(n, vector<int>(n));
        if(n==0) return vec;
        if(n==1) {
            vec[0][0] = 1;
            return vec;
        }
        int left=0, right=n-1, high=0, low=n-1;
        int cur = 1;
        while(true){
            if(left>=right || high>=low) break;
            
            // from left to right
            for(int i=left; i<=right; i++){
                vec[high][i] = cur++;
            }
            
            // from high to low;
            for(int i=high+1; i<=low; i++){
                vec[i][right] = cur++;
            }
            
            // from right to left
            for(int i=right-1; i>=left; i--){
                vec[low][i] = cur++;
            }
            
            // from low to high
            for(int i=low-1; i>=high+1; i--){
                vec[i][left] = cur++;                
            }
            
            left++;
            right--;
            high++;
            low--;
        }
        if(left==right && high==low && cur==n*n){
            vec[high][left] = cur;
        }
        return vec;
    }
};