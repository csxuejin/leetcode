class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.empty()) 
            return 0;
        if(nums.size()==1)
            return nums[0];
        return max(helper(nums,0,nums.size()-2), helper(nums,1, nums.size()-1));
    }
    
    int helper(vector<int>&nums, int start, int end){
        int lastRob=0, lastNotRob=0;
        for(int i=start; i<=end; i++){
            int tmp = lastRob;
            lastRob = max(lastRob, lastNotRob + nums[i]);
            lastNotRob = tmp;
        }
        return max(lastRob, lastNotRob);
    }
};