class Solution {
private:
    vector<vector<int>> res;
    vector<int> vec;
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        dfs(nums, 0);
        return res;
    }
    
    void dfs(vector<int> &nums, int cur){
        if(cur==nums.size()){
            res.push_back(vec);
            return;
        }
        vec.push_back(nums[cur]);
        dfs(nums, cur+1);
        vec.pop_back();
        dfs(nums, cur+1);
    }
};