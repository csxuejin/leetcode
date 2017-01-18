class Solution {
private:
    set<vector<int>> ss;
    vector<int> vec;
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        dfs(nums,0);
        vector<vector<int>> res;
        for(auto it=ss.begin(); it!=ss.end(); it++){
            res.push_back(*it);
        }
        return res;
    }
    
    void dfs(vector<int>&nums, int cur){
        if(cur==nums.size()){
            ss.insert(vec);
            return;
        }
        dfs(nums, cur+1);
        vec.push_back(nums[cur]);
        dfs(nums, cur+1);
        vec.pop_back();
    }
};