class Solution {
public:
    int reverse(int x) {
        long long  s = 0;
        while(x){
            s = s*10 + x%10;
            x /= 10;
        }
        return s<INT_MIN || s>INT_MAX? 0:s;
    }
};