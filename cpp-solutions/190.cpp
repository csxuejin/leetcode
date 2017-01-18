class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t res = 0;
        vector<int> vec;
        while(n){
            int t = 1;
            t = t&n;
            vec.push_back(t);
            n = n>>1;
        }
        for(int i=0; i<vec.size(); i++){
            res = res<<1;
            res += vec[i];
        }
        res = res<<(32-vec.size());
        return res;
    }
};