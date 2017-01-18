class Solution {
public:
    int threeSumSmaller(vector<int>& nums, int target) {
        if(nums.size()<3) return 0;
        sort(nums.begin(), nums.end());
        int cnt = 0;
        for(int i=0; i<nums.size()-2; i++){
            if(nums[i] + nums[i+1] + nums[i+2] >= target){
                return cnt;
            }
            for(int j=i+1; j<nums.size()-1; j++){
                int k = nums.size()-1; 
                while(j<k && nums[i]+nums[j]+nums[k]>=target) k--;
                cnt += k-j;
            }
        }
        return cnt;
    }
};