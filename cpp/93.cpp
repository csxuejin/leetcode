class Solution {
public:
    vector<string> result;
    string solution;
    
    vector<string> restoreIpAddresses(string s) {
        backtracking(s, 0, 0);
        return result;
    }
    
private:
    void backtracking(string s, int start, int part){
        if(start == s.size() && part == 4){
            result.push_back(solution);
            return;
        }
        
        for(int i = start; i < s.size(); i++){
            if(part < 4 && i-start < 3 && validIP(s.substr(start, i-start+1))){
                solution += s.substr(start, i-start+1);
                part++;
                if(part < 4) solution += ".";

                backtracking(s, i+1, part);
                
                if(part < 4) solution.pop_back();
                part--;
                for(int j = 0; j < i-start+1; j++) solution.pop_back();
            }
        }
    }
    
    bool validIP(string s){
        int ip = stoll(s);
        
        if(s[0] == '0' && s.size()>1) return false;
        else if(ip >= 0 && ip <= 255) return true;
        
        return false;
    }
};
