class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
       if(nums.empty())
            return 0;
       vector<int> vec;
       for(int i=0; i<nums.size(); i++){
           auto it = lower_bound(vec.begin(), vec.end(), nums[i]);
           if(it==vec.end()){
               vec.push_back(nums[i]);
           }else{
               *it = nums[i];
           }
       }
       return vec.size();
    }
};

/*
// DP: O(n*n);
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if(nums.empty()) 
            return 0;
        vector<int> LIS(nums.size(), 1);
        int res = 1;
        for(int i=0; i<nums.size(); i++){
            for(int j=0; j<i; j++){
                if(nums[i]>nums[j]){
                    LIS[i] = max(LIS[i], LIS[j]+1);
                }
            }
            res = max(res, LIS[i]);
        }
        return res;
    }
};
*/