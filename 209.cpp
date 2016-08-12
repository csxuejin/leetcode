class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int start = 0, sum=0;
        int res = INT_MAX;
        int i = 0;
        while(i<nums.size()){
            while(sum<s && i<nums.size()) sum += nums[i++];
            if(sum>=s){
              while(sum>=s && start<i){
                sum -= nums[start++];
              }
              res = min(res, i-start+1);
            }
        }
        return res==INT_MAX? 0:res;
    }
};
