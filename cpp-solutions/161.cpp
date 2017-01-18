class Solution {
public:
    bool isOneEditDistance(string s, string t) {
        bool flag = false;
        int m = s.size(); 
        int n = t.size();
        if(m>n) return isOneEditDistance(t,s);
        if(n-m>1) return false;
        for(int i=0; i<m; i++){
            if(s[i]!=t[i]){
                if(m==n){
                    s[i] = t[i];
                }else{
                    s.insert(i,1,t[i]);
                }
                flag = true;
                break;
            }
        }
        return (!flag && n-m==1) || (flag && s==t);
    }
};