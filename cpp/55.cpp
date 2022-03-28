class Solution {
public:
    bool canJump(vector<int>& nums) {
        int res = 1;
        for(int i=0; i<nums.size(); i++){
            if(i==nums.size()-1) return true;
            res--;
            if(nums[i]>res || res==0){
                res = nums[i];
            }
            if(res<=0){
                return false;
            }
        }
        return false;
    }
};