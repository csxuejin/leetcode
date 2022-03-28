
class Solution {
public:
    int strStr(string haystack, string needle) {
        int len = needle.size();
        if (len == 0){
            return 0;
        }
        char firCh = needle[0];
        for (int i=0; i<haystack.size(); i++){
            if(haystack.size()-i+1 < len) break;
            char ch = haystack[i];
            if (ch == firCh){
                string str = haystack.substr(i,len);
                if (str == needle){
                    return i;
                }
            }
        }
        return -1;
    }
};