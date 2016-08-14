class Solution {
public:
    int maxSubArrayLen(vector<int>& nums, int k) {
        unordered_map<int,int> hash;
        int sum = 0, ans = 0;
        for(int i=0; i<nums.size(); i++){
            sum += nums[i];
            if(sum==k){
                ans = i+1;
            }else if(hash.find(sum-k)!=hash.end()){
                ans = max(ans, i-hash[sum-k]);
            }
            if(hash.find(sum)==hash.end()){
                hash[sum] = i;
            }
        }
        return ans;
    }
};