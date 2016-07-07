class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        map<int, bool> mm;
        for (int i=0; i<nums.size(); i++){
            if (mm.count(nums[i]) != 0){
                return true;
            }
            mm[nums[i]] = true;
        }
        return false;
    }
};