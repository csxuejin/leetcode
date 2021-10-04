class Solution {
private:
    int tar;
public:
    bool binarySearch(vector<int>& vec){
        int l=0;
        int r=vec.size();
        while(l<=r){
            int m = (l+r)/2;
            if(vec[m]<tar){
                l = m+1;
            }else if(vec[m]>tar){
                r = m-1;
            }else{
                return true;
            }
        }
        return false;
    }
    
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        tar = target;
        for(int i=0; i<matrix.size(); i++){
            if(target<matrix[i].front()) return false;
            if(matrix[i].front()<=tar && matrix[i].back()>=tar)
                if(binarySearch(matrix[i])) return true;
        }
        return false;
    }
};

/* O(m+n) 的复杂度
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix.front().size();
        int i=0, j=n-1;
        while(i<m && j>=0){
            int val = matrix[i][j];
            if(val>target){
                j--;
            }else if(val<target){
                i++;
            }else{
                return true;
            }
        }
        return false;
    }
};
*/

