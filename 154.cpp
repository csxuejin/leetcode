class Solution {
public:
    int findMin(vector<int>& nums) {
        if(nums.size()==1) return nums[0];
        int l=0, r=nums.size()-1;
        while(l<r){
            int m = (l+r)/2;
            if(nums[l]<nums[r]){
                return nums[l];
            }
            if(nums[l]>nums[m]){
                r = m;
            }else if(nums[l]<nums[m]){
                l = m+1;
            }else{
                l++;
            }
        }
        return nums[l];
    }
};