class Solution {
public: 
    string simplifyPath(string path) {
        stack<string> sta;
        stringstream ss;
        ss.str(path);
        string str;
        while(getline(ss,str,'/')){
            if(!str.empty()){
                if(str==".." && !sta.empty()){
                    sta.pop();                   
                }else if(str!="." && str!=".."){
                    sta.push(str);
                }
            }
        }
        string res="";
        while(!sta.empty()){
            res = "/" + sta.top() + res;
            sta.pop();
        }
        return res.empty()? "/" : res;
    }         
};