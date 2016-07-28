class Solution {
public:
    void sortColors(vector<int>& nums) {
        int low, mid, high;
        low = 0;
        mid = 0; 
        high = nums.size()-1;
        while(mid <= high){
            if(nums[mid]==1){
                mid++;
            }else if(nums[mid]==0){
                swap(nums[mid], nums[low]);
                mid++;
                low++;
            }else{
                swap(nums[mid], nums[high]);
                high--;
            }
        }
    }
};