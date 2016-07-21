class Solution {
public:
    int findMin(vector<int>& nums) {
        int l, r;
        l = 0;
        r = nums.size()-1;
        while(l<r){
            int mid = (l+r)/2;
            if(nums[l] < nums[r]){
                return nums[l];
            }
            if(nums[l] > nums[mid]){
                r = mid;
            }else{
                l = mid+1;
            }
        }
        return min(nums[l], nums[r]);
    }
};