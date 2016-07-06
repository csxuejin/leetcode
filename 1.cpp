class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> mm;
        vector<int> vec;
        for (int i=0; i<nums.size(); i++){
            if( mm.find(target-nums[i]) != mm.end() ){
                vec.push_back(mm[target-nums[i]]);
                vec.push_back(i);
                return vec;
            }
            mm[nums[i]] = i;
        }
        return vec;
    }
};