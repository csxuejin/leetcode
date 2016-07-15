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
