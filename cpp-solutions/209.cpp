class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int start = 0, sum=0;
        int res = INT_MAX;
        int i = 0;
        for(int i=0; i<nums.size(); i++){
            sum += nums[i];
            while(sum>=s){
                res = min(res, i-start+1);
                sum -= nums[start++];
            }
        }    
        return res==INT_MAX? 0:res;
    }
};
