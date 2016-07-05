class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.length()<2) 
           return s.length();
        map<char, int> mm;
        int maxLen = 0, len = 0;
        for (int i=0; i<s.length(); i++){
            if(mm.find(s[i]) == mm.end() || mm[s[i]]<i-len){
                len ++;
            }else{
                len = i - mm[s[i]];
            }
            mm[s[i]] = i;
            if(len>maxLen)
                maxLen = len;
        }
        return maxLen;
    }
};

 
