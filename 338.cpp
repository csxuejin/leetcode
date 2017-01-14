//awesome method
class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> dp(num+1,0);
        for(int i=1; i<=num; i++){
            dp[i] = dp[i&(i-1)] + 1;
        }
        return dp;
    }
};


/*
class Solution {
public:
    int helper(int num){
        int res = 0;
        while(num){
            num = num&(num-1);
            res++;
        }
        return res;
    }
    vector<int> countBits(int num) {
        vector<int> vec;
        for (int i=0; i<=num; i++){
            vec.push_back(helper(i));
        }
        return vec;
    }
};
*/