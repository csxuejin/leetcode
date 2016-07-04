bool cmp(string a, string b){
    return a.length() < b.length();
}

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.size() == 0)   return "";
        sort(strs.begin(), strs.end(), cmp);
        int minLen = strs[0].length();
        int len = 0, j;
        for (int i=0; i<minLen; i++){
            char ch = strs[0][i];
            for (j=1; j<strs.size(); j++){
                if (strs[j][i] != ch){
                    return strs[0].substr(0,len);
                }
            }
            if (j==strs.size() && strs[j-1][i] == ch){
                len++;
            }
        }
        return strs[0].substr(0,len);
    }
};