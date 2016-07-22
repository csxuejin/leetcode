class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        if(nums.empty() || nums.size()==1)
            return nums;
        vector<int> left(nums.size(),0);
        vector<int> right(nums.size(),0);
        for(int i=0; i<nums.size(); i++){
            if(i==0){
                left[i] = nums[i];
            }else{
                left[i] = left[i-1] * nums[i];
            }
        }
        
        for(int i=nums.size()-1; i>=0; i--){
            if(i==nums.size()-1){
                right[i] = nums[i];
            }else{
                right[i] = right[i+1]*nums[i];
            }
        }
        
        vector<int> res(nums.size(),0);
        for(int i=0; i<nums.size(); i++){
            if(i==0){
                res[i] = right[i+1];
            }else if(i==nums.size()-1){
                res[i] = left[i-1];
            }else{
                res[i] = left[i-1] * right[i+1];
            }
        }
        return res;
    }
};