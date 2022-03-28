class Solution {
public:
    int getSum(int a, int b) {
         return b==0? a:getSum(a^b, (a&b)<<1); //be careful about the terminating condition;
    }
};

/*
class Solution {
public:
    int getSum(int a, int b) {
        int sum = a;
        while(b!=0){
            sum = (a^b); // ths sum without carry
            b = (a&b)<<1; // the carry
            a = sum;
        }
        return sum;
    }
};
*/