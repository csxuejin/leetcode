// use "Greedy" can solve this problem in o(N) time
class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        if(nums.size()<2) return nums.size();
        int ans = 1;
        int i = 1;
        while(nums[i]==nums[i-1] && i<nums.size()) i++;
        bool increase = nums[i]>nums[i-1];
        for(; i<nums.size(); i++){
            if(increase){
                while(i+1<nums.size() && nums[i+1]>=nums[i]) i++;
            }else{
                while(i+1<nums.size() && nums[i+1]<=nums[i]) i++;
            }
            ans++;
            increase = increase? false:true;
        }
        return ans;
    }
};