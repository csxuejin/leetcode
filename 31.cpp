class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        if(nums.empty()) return;
        int i;
        for(i=nums.size()-2; i>=0; i--){
            if(nums[i] < nums[i+1]){
                break;
            }
        }
        reverse(nums.begin()+i+1, nums.end());
        if(i == -1)
            return;
        auto it = upper_bound(nums.begin()+i+1, nums.end(), nums[i]);
        swap(nums[i], *it);
    }
};