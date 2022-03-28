class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int cur = 0;
        for(int i=0; i<nums.size(); i++){
            if(cur<2 || nums[i]>nums[cur-2]){
                nums[cur++] = nums[i];
            }
        }
        return cur;
    }
};