class Solution {
private:
    vector<string> res;
public:
    void insert(int lower, int upper){
        res.push_back(lower==upper? to_string(lower) : to_string(lower)+"->"+to_string(upper));
    }

    vector<string> findMissingRanges(vector<int>& nums, int lower, int upper) {
        if(nums.empty()) {
            insert(lower, upper);
            return res;
        }
            
        for(int i=0; i<nums.size(); i++){
            if(lower<nums[i]){
                insert(lower, nums[i]-1);
                lower = nums[i]+1;
            }else if(lower==nums[i]){
                lower++;
            }
        }
        
        if(lower<=upper)
            insert(lower, upper);
        
        return res;
    }
};
