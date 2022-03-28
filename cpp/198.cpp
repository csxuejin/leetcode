class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.size() == 0) return 0;
        if (nums.size() == 1) return nums[0];
        int rob=0, notRob=0;
        for (int i=0; i<nums.size(); i++){
            int curRob = notRob + nums[i];
            notRob = max(notRob, rob);
            rob = curRob;
        }
        return max(rob, notRob);
    }
};
