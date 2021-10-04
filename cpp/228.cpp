class Solution {
public:
    void merge(int& first, int& last, vector<string>& res){
        if(first != last)
            res.push_back(to_string(first)+"->"+to_string(last));
        else
            res.push_back(to_string(first));
    }

    vector<string> summaryRanges(vector<int>& nums) {
        if(nums.empty()) return vector<string>{};
        if(nums.size() == 1) return vector<string>{to_string(nums[0])};
                
        vector<string> res;
        int first = nums[0], last = nums[0];
        for (int i=1; i<nums.size(); i++){
            if(nums[i] != last + 1){
                merge(first, last, res);
                first = last = nums[i];
            }else{
                last = nums[i];
            }
        }
        merge(first, last, res);
        return res;
    }
};

