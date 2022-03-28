class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int l, r;
        l=0;
        r = nums.size()-1;
        while(l<r-1){ // pay attention to this bound
            int mid = (l+r)/2;
            if(nums[mid]>nums[mid-1] && nums[mid]>nums[mid+1]){
                return mid;
            }else if(nums[mid]<nums[mid-1]){
                r = mid-1;
            }else{
                l = mid+1;
            }
        }
        return nums[l]>nums[r]? l:r;
    }
};