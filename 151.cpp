
// using the stringstream
class Solution {
public:
    void reverseWords(string &s) {
        istringstream is(s);
        string tmp;
        is >> s;
        while(is>>tmp) s  = tmp + " " + s;
        if(s[0] == ' ') s = "";
    }
};


