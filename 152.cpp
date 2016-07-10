class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        int curMax = nums[0], curMin = nums[0], maxPro = nums[0];
        for (int i=1; i<nums.size(); i++){
            int tmp = curMax * nums[i];
            curMax = max(nums[i], max(curMax*nums[i], curMin*nums[i]));
            curMin = min(nums[i], min(tmp, curMin*nums[i]));
            maxPro = max(maxPro, curMax);
        }
        return maxPro;
    }
};

