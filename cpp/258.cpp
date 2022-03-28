class Solution {
public:
    int addDigits(int num) {
        vector<int> vec;
        int t = 0;
        while(num){
            t += num%10;
            num /= 10;
        }
        return t<10? t:addDigits(t);
    }
};