class Solution {
public:
    int hammingDistance(int x, int y) {
        int s = x^y;
        int res = 0;
        while(s){
            s &= s-1;
            res++;
        }
        return res;
    }
};
