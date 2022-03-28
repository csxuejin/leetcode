class Solution {
public:
    int arrangeCoins(int n) {
        if (n<=1) 
            return n;
        long l, r;
        for(l=1, r=n; l<r;){
            long m = l + (r-l)/2;
            if( (1+m)*m/2 <= n){
                l = m + 1;
            }else{
                r = m;
            }
        }
        return l-1;
    }
};