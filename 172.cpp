class Solution {
public:
    int trailingZeroes(int n) {
        int res = 0;
        for(long i=5; i<=n; i*=5){
            res += n/i;
        }
        return res;
    }
};