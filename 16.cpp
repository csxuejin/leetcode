class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int result = nums[0] + nums[1] + nums[2];
        for(int i=0; i<nums.size(); i++){
            int l, r;
            l = i+1; 
            r = nums.size()-1;
            while(l<r){
                int tmp = nums[i] + nums[l] + nums[r];
                if(abs(tmp-target)<abs(result-target)){
                    result = tmp;
                }
                if(tmp > target){
                    r--;
                }else if(tmp < target){
                    l++;
                }else{
                    return tmp;
                }
            }
        }
        return result;
    }
};