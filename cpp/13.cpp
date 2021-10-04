class Solution {
public:
    int romanToInt(string s) {
        map<char, int> mm = { { 'I' , 1 },
                           { 'V' , 5 },
                           { 'X' , 10 },
                           { 'L' , 50 },
                           { 'C' , 100 },
                           { 'D' , 500 },
                           { 'M' , 1000 } };
        int res = mm[s.back()];
        for(int i=s.size()-2; i>=0; i--){
            if(mm[s[i]] >= mm[s[i+1]]){
                res += mm[s[i]];
            }else{
                res -= mm[s[i]];
            }
        }
        return res;
    }
};