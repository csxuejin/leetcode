class Solution {
public:
    double myPow(double x, int n) {
        if (n==0) return 1;
        if (n==1) return x;
        if (n==-1) return 1/x;
        double t = myPow(x*x,n/2);
        if(n%2){
            return n<0? 1/x*t : x*t;
        }
        return t;
    }
};