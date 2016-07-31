class Solution {
public:
    bool canPermutePalindrome(string s) {
        map<char, int> mm;
        for(int i=0; i<s.size(); i++){
            mm[s[i]]++;
        }
        int odd = 0;
        for(auto it=mm.begin(); it!=mm.end(); it++){
            if(it->second % 2 != 0){
                odd++;
            }
        }
        return odd==1 || odd==0;
    }
};