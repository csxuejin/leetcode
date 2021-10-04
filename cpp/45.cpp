class Solution {
public:
    int jump(vector<int>& nums) {
        if(nums.size()<=1) return 0;
        int maxReach = nums[0];
        int curMaxReach = nums[0];
        int step = 1;
        for(int i=1; i<=min((int)nums.size(),maxReach); i++){
            curMaxReach = max(curMaxReach, i+nums[i]);
            if(i==nums.size()-1) break;
            if(i==maxReach){
                maxReach = curMaxReach;
                step++;
            }
        }
        return step;
    }
};

