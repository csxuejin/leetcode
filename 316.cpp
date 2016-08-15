class Solution {
public:
    string removeDuplicateLetters(string s) {
        unordered_map<char, int> mm;
        unordered_map<char, bool> used;
        for(int i=0; i<s.size(); i++){
            mm[s[i]]++;
        }
        
        stack<char> sta;
        for(int i=0; i<s.size(); i++){
            if(used[s[i]]) {
                mm[s[i]]--;
                continue;
            }
            while(!sta.empty() && sta.top()>s[i] && mm[sta.top()]>0){
                used[sta.top()] = false;
                sta.pop();
            }
            sta.push(s[i]);
            used[s[i]] = true;
            mm[s[i]]--;
        }
        
        string res = "";
        while(!sta.empty()){
            res = sta.top() + res;
            sta.pop();
        }
        return res;
    }
};
