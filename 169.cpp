class Solution {
public:
    int majorityElement(vector<int>& nums) {
        map<int, int> mm;
        int res;
        for (int i=0; i<nums.size(); i++){
            if(++mm[nums[i]] > nums.size()/2){
                res = nums[i];
                break;
            }
        }
        return res;
    }
};

