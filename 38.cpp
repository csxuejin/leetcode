class Solution {
public:
    void helper(string *s){
        string str = *s;
        char t = str[0];
        int num = 0;
        *s = "";
        for (int i=0; i<str.size(); i++){
            if (str[i] == t){
                num ++;
            }
            if (str[i] != t ){
                *s +=  (num+'0');
                *s += t;
                t = str[i];
                num = 1;
            }
            
            if (i == str.size() -1 ){
                *s += (num+'0');
                *s += t;
                break;
            }
        }
    }
    
    string countAndSay(int n) {
        if (n==1) return "1";
        string str = "1";
        for (int i=0; i<n-1; i++){
            helper(&str);
        }
        return str;
    }
};