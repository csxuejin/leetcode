class Solution {
public:
    int numDecodings(string s) {
        if(s.empty() || s[0]=='0') return 0;
        if(s.size()==1)
            return 1;
        vector<int> dp(s.size()+1, 0);
        dp[0] = 1; dp[1] = 1;
        for(int i=2; i<=s.size(); i++){
            if(isValid(s[i-2]) && isValid(s[i-2], s[i-1])){
                dp[i] = dp[i-2] + dp[i-1];
            }
            if(isValid(s[i-1]) && !isValid(s[i-2], s[i-1])){
                dp[i] = dp[i-1];
            }
            if(!isValid(s[i-1]) && isValid(s[i-2], s[i-1])){
                dp[i] = dp[i-2];
            }
            if(!isValid(s[i-1]) && !isValid(s[i-2], s[i-1])){
                return 0;
            }
        }
        return dp.back();
    }
    
    bool isValid(char a){
        return a>='1' && a<='9';
    }
    
    bool isValid(char a, char b){
        return a=='1' || a=='2'&&b<='6';
    }
};