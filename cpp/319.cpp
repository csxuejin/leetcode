class Solution {
public:
    int bulbSwitch(int n) {
        int res = 0;
        // The number of one number's factor is odd if and only if it is a perfect square!
        for(int i=1; i*i<=n; i++){
            res++;
        }
        return res;
    }
};