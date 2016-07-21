class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        if(nums.empty() || target<nums[0]) return 0;
        if(target>nums.back()) return nums.size();
        for(int i=1; i<nums.size(); i++){
           if(target > nums[i-1] && target < nums[i] || target == nums[i]){
               return i;
           }
        }
        return 0;
    }
};