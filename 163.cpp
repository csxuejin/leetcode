class Solution {
public:
    vector<string> findMissingRanges(vector<int>& nums, int lower, int upper) {
        if(nums.empty()) {
            if(lower==upper){
                return vector<string>{to_string(lower)};
            }else{
                return vector<string>{to_string(lower)+"->"+to_string(upper)};
            }
        }
            
        vector<pair<int,int>> vec;
        for(int i=0; i<nums.size(); i++){
            if(lower<nums[i]){
                vec.push_back({lower, nums[i]-1});
                lower = nums[i]+1;
            }else if(lower==nums[i]){
                lower++;
            }
        }
        
        if(lower<=upper){
            vec.push_back({lower, upper});
        }
        
        vector<string> res;
        for(auto it:vec){
            if(it.first==it.second){
                res.push_back(to_string(it.first));
            }else{
                res.push_back(to_string(it.first)+"->"+to_string(it.second));
            }
        }
        
        return res;
    }
};