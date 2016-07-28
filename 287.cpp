class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int l = 0;
        int r = nums.size()-1;
        while(l<r){
            int m = (l+r)/2;
            if(nums[m]<m+1){
                r = m;
            }else if(nums[m]==m+1){
                l = m+1;
            }else{
                l = m;
            }
            if(nums[l]==nums[l+1]){
                return nums[l];
            }
            if(nums[r]==nums[r-1]){
                return nums[r];
            }
        }
        return 0;
        
    }
};