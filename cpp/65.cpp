class Solution {
public:
    bool isNumber(string s) {
        int i=0;
        while(s[i]==' ') i++;
        if(s[i]=='+' || s[i]=='-') i++;
        int j=s.size()-1;
        while(s[j]==' ') j--;
        
        int num = 0, eNum = 0;
        for(; i<=j; i++){
            if(isdigit(s[i])) {
                num++;
            }else if(s[i]=='.'){
                eNum++;
            }else{
                break;
            }
        }
        
        if(num<1 || eNum>1)
            return false;
            
        if(i<=j && s[i]=='e'){
            i++;
            num = 0;
            if(s[i]=='+' || s[i]=='-') i++;
            while(i<=j && isdigit(s[i])){
                num++;
                i++;
            }
            if(num<1) return false;
        }
        return i==j+1;
    }
};

