class Solution {
public:
    bool helper(char a, char b){
        return (a=='('&&b==')') || (a=='['&&b==']') || (a=='{'&&b=='}');
    }
    bool isValid(string s) {
        vector<char> vec;
        
        for (int i=0; i<s.size(); i++){
            char t = s[i];
            if(t=='(' || t=='[' || t=='{'){
                vec.push_back(t);
            }else{
                if(vec.size()==0) return false;
                if (helper(vec.back(), t)){
                    vec.pop_back();
                }else{
                    vec.push_back(t);
                }
            }
        }
        return vec.empty();
    }
};