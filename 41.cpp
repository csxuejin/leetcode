class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        vector<bool> isShow(nums.size(), false);
        for(int i=0; i<nums.size(); i++){
            if(nums[i]>0 && nums[i]<=nums.size()){
                isShow[nums[i]-1] = true;
            }
        }
        for(int i=0; i<isShow.size(); i++){
            if(!isShow[i]){
                return i+1;
            }
        }
        return isShow.size()+1;
    }
};
