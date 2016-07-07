class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        if(nums.empty())  return 0;
        int lastNot=nums.size()-1;
        while(nums[lastNot]==val && lastNot>=0)  lastNot--;
        
        for (int i=0; i<nums.size() && i<lastNot ; i++){
            if(nums[i] == val){
                swap(nums[i], nums[lastNot--]);
                while(nums[lastNot] == val && lastNot>=0){
                    lastNot--;
                }
            }
        }
        return lastNot+1;
    }
};