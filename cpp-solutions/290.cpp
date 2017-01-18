class Solution {
public:
    bool wordPattern(string pattern, string str) {
        istringstream is(str);
        map<string, char> s2p;
        map<char, string> p2s;
        string tmp;
        int i=0;
        while(is>>tmp){
            char ch = pattern[i];
            if(s2p.count(tmp)==0 && p2s.count(ch)==0){
                s2p[tmp] = ch;
                p2s[ch] = tmp;
            }else{
                if(s2p[tmp]!=ch || p2s[ch] != tmp){
                    return false;
                }
            }
            i++;
        }
        return i==pattern.size();
    }
};