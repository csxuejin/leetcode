class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if(nums.size() == 0) 
            return 0;
        int maxSum = INT_MIN, curSum = 0;
        for (int i=0; i<nums.size(); i++){
            if(curSum <= 0){
                curSum = nums[i];
            }else{
                curSum += nums[i];
            }
            if(curSum > maxSum)
                maxSum = curSum;
        }
        return maxSum;
    }
};