class Solution {
public:
    bool isPerfectSquare(int num) {
        int l = 1, r = num;
        while(l<=r){
            int m = (l+r)/2;
            if(num%m==0 && m==num/m){
                return true;
            }else if(m<=num/m){
                l = m+1;
            }else{
                r = m-1;
            }
        }
        return false;
    }
};