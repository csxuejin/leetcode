class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> res;
        if(nums.size()== 0){
            return res;
        }
        if(nums.size() == 1){
            res.push_back(to_string(nums[0]));
            return res;
        }
        int first = nums[0], last = nums[0];
        for (int i=1; i<nums.size(); i++){
            if(nums[i] != last + 1){
                if(first != last)
                    res.push_back(to_string(first)+"->"+to_string(last));
                else
                    res.push_back(to_string(first));
                first = last = nums[i];
            }else{
                last = nums[i];
            }
        }
        if(first != last){
            res.push_back(to_string(first) + "->" + to_string(last));
        }else{
            res.push_back(to_string(first));
        }
        return res;
    }
};