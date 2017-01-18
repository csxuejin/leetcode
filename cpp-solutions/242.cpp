class Solution {
public:
    bool isAnagram(string s, string t) {
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        return s == t;
    }
};

/*
// method 2:
class Solution {
public:
    bool isAnagram(string s, string t) {
        map<char, int> mm;
        if(s.size() != s.size())
            return false;
        for (int i=0; i<s.size(); i++){
            mm[s[i]]++;
        }
        for (int i=0; i<t.size(); i++){
            mm[t[i]]--;
        }
        for (auto p : mm){
            if(p.second!=0)
                return false;
        }
        return true;
    }
};

*/