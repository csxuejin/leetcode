class Solution {
public:
    vector<string> num{"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    vector<string> res;
    vector<string> letterCombinations(string digits) {
        if (digits.length()>0)
            helper("", digits);
        return res;
    }
    
    void helper(string tmp, string dig){
        if (dig.length() == 0){
            res.push_back(tmp);
            return;
        }
        string str = num[dig[0]-'0'];
        string subStr = dig.substr(1);
        for (int i=0; i<str.length(); i++){
            helper(tmp + str[i], subStr);
        }
    }
};
