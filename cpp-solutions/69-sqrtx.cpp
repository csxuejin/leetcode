class Solution {
public:
    int mySqrt(int x) {
        int l=1, r=x, ans=0;
        while(l<=r){
            int m = (l+r)/2;
            if(m<=x/m){
                l = m+1;
                ans = m;
            }else{
                r = m-1;
            }
        }
        return ans;
    }
};