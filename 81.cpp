class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int rotateNum = 0;
        for(int i=0; i<nums.size(); i++){
            if(nums[i]>nums[i+1]){
                break;
            }
            rotateNum++;
        }
        if(nums[0]<=target && target<=nums[rotateNum]){
            return binarySearch(nums, 0, rotateNum, target);
        }else if(target>=nums[rotateNum+1] && target<=nums.back()){
            return binarySearch(nums, rotateNum+1, nums.size()-1, target);
        }else{
            return false;
        }
    }
    
    bool binarySearch(vector<int>& nums, int l, int r, int& target){
        while(l<=r){
            int m = (l+r)/2;
            if(nums[m]<target){
                l = m+1;
            }else if(nums[m]>target){
                r = m-1;
            }else{
                return true;
            }
        }
        return false;
    }
};

