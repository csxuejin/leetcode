class Solution {
public:
    int findNotZero(int start, vector<int>& nums){
        while(start<nums.size() && nums[start]==0) 
            start++;
        return start==nums.size()? -1:start;
    }

    void moveZeroes(vector<int>& nums) {
        int zero=-1, notZero=-1;
        for(int i=0; i<nums.size(); i++){
            if(nums[i]==0){
                notZero = notZero==-1? findNotZero(i+1, nums) : findNotZero(notZero, nums);
                if(notZero==-1) break;
                swap(nums[i], nums[notZero]);
            }
        }
    }
};
