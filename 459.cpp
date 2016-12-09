class Solution {
public:
    bool help(string &str, string &init, int time){
        string tmp = str;
        for(int i=1; i<time; i++){
            str += tmp;
        }
        return str==init;
    }

    bool repeatedSubstringPattern(string str) {
        int len = str.size();
        bool even = str.size()%2==0;
        for(int i=1; i<len; i++){
            if(len%i==0){
                string sstr = str.substr(0,i);
                if(help(sstr, str, len/i)){
                    return true;
                }
            }
        }
        return false;
    }
};