class Solution {
public:
    int divide(int dividend, int divisor) {
        if (!divisor || (dividend == INT_MIN && divisor == -1))
            return INT_MAX;
        long long div = labs(dividend);
        long long dso = labs(divisor);
        int sign = (dividend<0) ^ (divisor<0)? -1:1;
        int res = 0;
        while(div>=dso){
            int cnt = 1;
            long long tmp = dso;
            while(div>=(tmp<<1)){
                cnt <<= 1;
                tmp <<= 1;
            }
            div -= tmp;
            res += cnt;
        }
        return res*sign;
    }
};