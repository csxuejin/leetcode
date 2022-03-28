class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        if(nums.size()<3) return res;
        sort(nums.begin(), nums.end());
        
        for(int i=0; i<nums.size()-2; i++){
            if(i>0 && nums[i]==nums[i-1]) continue;
            int l = i+1;
            int r = nums.size()-1;
            while(l<r){
                int t = nums[i]+nums[l]+nums[r];
                if(t==0){
                    while(l+1<nums.size()-1 && nums[l]==nums[l+1]) l++;
                    while(r-1>l && nums[r]==nums[r-1]) r--;
                    res.push_back(vector<int>{nums[i], nums[l], nums[r]});
                    l++;
                    r--;
                }else if(t>0){
                    r--;
                }else{
                    l++;
                }
            }
        }
        return res;
    }
};
