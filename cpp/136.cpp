class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int t = nums[0];
        for (int i=1; i<nums.size(); i++){
            t = t^nums[i];
        }
        return t;
    }
};