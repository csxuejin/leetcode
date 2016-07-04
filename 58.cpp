
class Solution {
public:
    int lengthOfLastWord(string s) {
        int len = 0;
        bool firCh = false;
        for (int i=s.length()-1; i>=0; i--){
            if(s[i] == ' '){
                 if(!firCh){
                     continue;
                 }else{
                     break;
                 }
            }
            
            if (isalpha(s[i])){
                if (!firCh) firCh = true;
                len++;
            }
        }
        return len;
    }
};