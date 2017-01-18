class Solution {
private:
    vector<vector<int>> res;
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<bool> used(nums.size(), false);
        vector<int> vec;
        help(nums, used, vec);
        return res;
    }
    
    void help(vector<int>& nums, vector<bool>& used, vector<int>&vec ){
        if(vec.size()==nums.size()){
            res.push_back(vec);
            return;
        }
        unordered_map<int, bool> mm;
        for(int i=0; i<nums.size(); i++){
            if(!used[i] && mm.find(nums[i])==mm.end()){
                mm[nums[i]] = true;
                vec.push_back(nums[i]);
                used[i] = true;
                help(nums, used, vec);
                used[i] = false;
                vec.pop_back();
            }
        }
    }
};