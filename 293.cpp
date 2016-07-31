class Solution {
public:
    vector<string> generatePossibleNextMoves(string s) {
        vector<string> vec;
        if(s.empty())
            return vec;
        for(int i=0; i<s.size()-1; i++){
            if(s[i]=='+' && s[i+1]=='+'){
                s[i] = '-';
                s[i+1] = '-';
                vec.push_back(s);
                s[i] = '+';
                s[i+1] = '+';
            }
        }
        return vec;
    }
};

