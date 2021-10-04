class Solution {
public:
    string longestPalindrome(string s) {
        string str;
        for(int i=0; i<s.size(); i++){
            str = str+"!"+s[i];
        }
        str += "!";
        int step = 0, from, to;
        for(int i=1; i<str.size(); i++){
            int t = 0;
            int l=i-1; 
            int r = i+1;
            while(l>=0 && r<str.size() && str[l]==str[r]){
                t++;
                l--;
                r++;
            }
            if(t>step){
                step = t;
                from = l+1;
                to = r-1;
            }
        }
        string res;
        for(int i=from; i<=to; i++){
            if(str[i]!='!'){
                res += str[i];
            }
        }
        return res;
    }
};