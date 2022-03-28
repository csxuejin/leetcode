class Solution {
public:
    bool isPowerOfThree(int n) {
        if(n<=0) return false;
        int t = pow(3,(int)(log(INT_MAX)/log(3)));
        return t%n == 0;
    }
};