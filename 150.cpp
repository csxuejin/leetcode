class Solution {
private:
    int cal(stack<int>& sta, string str){
        int a = sta.top();
        sta.pop();
        int b = sta.top();
        sta.pop();
        if(str=="+") return b+a;
        if(str=="-") return b-a;
        if(str=="*") return b*a;
        return b/a;
    }
    
public:
    int evalRPN(vector<string>& tokens) {
        if(tokens.empty()) return 0;
        if(tokens.size()==1){
            if(tokens[0]!="+" && tokens[0]!="-" && tokens[0]!="*" && tokens[0]!="/"){
                return atoi(tokens[0].c_str());
            }
            return 0;
        }
        stack<int> sta;
        int res = 0;
        for(int i=0; i<tokens.size(); i++){
            string str = tokens[i];
            if(str=="+" || str=="-" || str=="*" || str=="/"){
                res = cal(sta, str);
                sta.push(res);
            }else{
                sta.push(atoi(str.c_str()));
            }
        }
        return res;
    }
};

