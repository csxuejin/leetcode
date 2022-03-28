class Solution {
public:
    int calculate(string s) {
        stack<int> num, ope;
        int res=0, sign=1, t=0;
        for(auto c : s){
            if(isdigit(c)){
                t = t*10 + c - '0';
            }else{
                res += sign*t;
                t = 0;
                switch (c){
                   case '+':
                     sign = 1;
                     break;
                   case '-':
                     sign = -1;
                     break;
                   case '(':
                     num.push(res);
                     ope.push(sign);
                     res = 0;
                     sign = 1;
                     break;
                   case ')':
                     if(!ope.empty()){
                         res = ope.top()*res + num.top();
                         num.pop();
                         ope.pop();
                     }
                }
            }
        }
        res += sign*t;
        return res;
    }
};
