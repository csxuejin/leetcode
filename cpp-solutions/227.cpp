class Solution {
public:
    int calculate(string s) {
        int res=0, tmp = 0, num;
        char ope = '+';
        stack<int> sta;
        for (int i=0; i<s.size(); i++){
            if (isdigit(s[i])){
                tmp = tmp*10 + s[i] - '0';
            }
            if (!isdigit(s[i]) && !isspace(s[i]) || i==s.size()-1){
                switch (ope){
                    case '+':
                        sta.push(tmp);
                        break;
                    case '-':
                        sta.push(-tmp);
                        break;
                    case '*':
                        num = sta.top() * tmp;
                        sta.pop();
                        sta.push(num);
                        break;
                    case '/':
                        num = sta.top() / tmp;
                        sta.pop();
                        sta.push(num);
                        break;
                }
                ope = s[i];
                tmp = 0;
            }
        }
        
        while(!sta.empty()){
            res += sta.top();
            sta.pop();
        }
        return res;
    }
};
