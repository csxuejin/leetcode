class Solution {
public:
    bool isPalindrome(string s) {
        string str = "";
        for (int i=0; i<s.size(); i++){
            if(isalnum(s[i])){
                if (isalpha(s[i])){
                   s[i] = tolower(s[i]);
                }
                str += s[i];
            }
        }
        string tmp = str;
        reverse(str.begin(), str.end());
        return tmp == str;
    }
};