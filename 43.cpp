class Solution {
public:

    string addString(string str1, string str2){
        int len = max(str1.length(), str2.length()), last=0;
        string str = "";
        int i=str1.length()-1, j=str2.length()-1;
        for (; i>=0 || j>=0; i--,j--){
            int dig1 = (i>=0)? str1[i]-'0' : 0;
            int dig2 = (j>=0)? str2[j]-'0' : 0;
            str =  (char)((dig1+dig2+last)%10+'0') + str;
            last = (dig1+dig2+last)/10;
        }
        if(last != 0)  str = (char)(last + '0')+str;
        
        return str;
    }
    
    string multiply(string num1, string num2) {
        if(num1=="0" || num2=="0")  return "0";
        
        string res = "";
        for (int i=num1.length()-1; i>=0; i--){
            int last=0, dig1 = num1[i]-'0';
            string tmp = "";
            for (int j=num2.length()-1; j>=0; j--){
                int dig2 = num2[j]-'0';
                tmp = (char)((dig1*dig2 + last)%10 + '0')+tmp;
                last = (dig1*dig2+last)/10;
            }
            if (last != 0)
                tmp = (char)(last + '0') + tmp;
            
            for (int j=num1.length()-1; j>i; j--)
                tmp += "0";
            
            res = addString(res, tmp);
        }
        return res;
    }
};