class Solution {
public:
    int myAtoi(string str) {
        int i=0;
        while (str[i] ==  ' ') i++;
        bool flag = false;
        if(str[i] == '-'){
            flag = true;
            i++;
        }else if (str[i] == '+'){
            i++;
        }
        
        long ret = 0;
        for (; i<str.size(); i++){
            if (!isdigit(str[i])){
                break;
            }
            ret = ret*10 + (str[i]-'0');
            if (flag && ret >= 2147483648){
                return INT_MIN;
            }
            if (!flag && ret >= 2147483647)
                return INT_MAX;
            }
        }
        if (flag) return -1*ret;
        return ret;
    }
};
