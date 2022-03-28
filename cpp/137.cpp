class Solution {
public:
    int singleNumber(vector<int>& nums) {
        vector<int> bits(32,0);
        for(int i=0; i<nums.size(); i++){
            for(int j=31; j>=0; j--){
                bits[j] += nums[i]&1;
                nums[i] >>= 1;
                if(!nums[i]) break;
            }
        }
        int res = 0;
        for(int i=31; i>=0; i--){
            int t = bits[i]%3;
            if(t) {
                res += 1 << (31-i);
            }
        }
        return res;
    }
};
