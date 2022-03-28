class Solution {
public:
    bool isPowerOfFour(int num) {
        if(num<=0) return false;
        return (num&(num-1))==0 && (num-1)%3==0;
    }
};

