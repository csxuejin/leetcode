class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l=0, r=nums.size()-1;
        if(target<nums[l] && target>nums[r]) return -1;
        while(l<r){
            int m = (l+r)/2;
            if(nums[m]<=nums[r]){
                if(nums[m]<target && target<=nums[r]){
                    l = m+1;
                }else{
                    r = m;
                }
            }else{
                if(nums[l]<=target && target<=nums[m]){
                    r = m;
                }else{
                    l = m+1;
                }
            }
        }
        if(nums[l]==target) return l;
        return -1;
    }
};