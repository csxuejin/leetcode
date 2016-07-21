class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        int n = nums.size();
        for(int i=0; i<n; i++){
            if(i>0 && nums[i]==nums[i-1]) continue;
            int l,r;
            l = i+1;
            r = nums.size()-1;
            while(l<r){
                int tmp = nums[i] + nums[l] + nums[r];
                if(tmp == 0){
                    while(l+1<n && nums[l]==nums[l+1]){
                        l++;
                    }
                    while(r-1>=0 && nums[r]==nums[r-1]){
                        r--;
                    }
                    res.push_back(vector<int>{nums[i], nums[l], nums[r]});
                    l++;
                    r--;
                }else if(tmp>0){
                    r--;
                }else{
                    l++;
                }
            }
        }
        return res;
    }
};