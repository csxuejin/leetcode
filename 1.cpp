class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> mm;
        for (int i=0; i<nums.size(); i++){
            if( mm.find(target-nums[i]) != mm.end() ){
                return vector<int>{mm[target-nums[i]], i};
            }
            mm[nums[i]] = i;
        }
        return vector<int>{};
    }
};