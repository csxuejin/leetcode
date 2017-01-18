class Solution {
public:
    bool binarySearch(vector<int> &vec, int tar){
        int l = 0;
        int r = vec.size()-1;
        if(tar<vec[0] || tar>vec.back())
            return false;
        while(l<r){
            int m = (l+r)/2;
            if(vec[m] == tar){
                return true;
            }else if(vec[m]>tar){
                r = m-1;
            }else{
                l = m+1;
            }
        }
        return vec[l]==tar || vec[r]==tar;
    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        for(int i=0; i<matrix.size(); i++){
            if(target<matrix[i][0]){
                return false;
            }
            if(target>matrix[i].back()){
                continue;
            }
            if(binarySearch(matrix[i],target)) return true;
        }
        return false;
    }
};