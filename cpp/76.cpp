class Solution {
public:
    string minWindow(string s, string t) {
        if(s.empty() || t.empty()) return "";
        int required = t.size();
        int left = 0, start = 0, i = 0, ans = INT_MAX;
        unordered_map<char, int> hash;
        for(auto it:t){
            hash[it]++;
        }
       
        while(i<=s.size() && start<s.size()){
            if(required){
                if(i==s.size()) break;
                hash[s[i]]--;
                if(hash[s[i]]>=0) required--;
                i++;
            }else{
                if(i-start<ans){
                    ans = i-start;
                    left = start;
                }
                hash[s[start]]++;
                if(hash[s[start]]>0) required++;
                start++;
            }
        }
        return ans == INT_MAX? "":s.substr(left,ans);
    }
};