class Solution {
private:
    vector<vector<int>> res;
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> vec;
        unordered_map<int, bool> hash;
        help(nums, hash, vec);
        return res;
    }
    
    void help(vector<int>&nums, unordered_map<int, bool> &hash, vector<int> &vec){
        if(vec.size()==nums.size()){
            res.push_back(vec);
            return;
        }
        for(int i=0; i<nums.size(); i++){
            if(hash.find(nums[i]) == hash.end()){
                vec.push_back(nums[i]);
                hash[nums[i]] = true;
                help(nums, hash, vec);
                vec.pop_back();
                hash.erase(nums[i]);
            }
        }
    }
};