class Solution {
public:
    int lengthOfLongestSubstringTwoDistinct(string s) {
        unordered_map<char,int> hash;
        int ans = 0, start = 0;
        for(int i=0; i<s.size(); i++){
            hash[s[i]]++;
            while(hash.size()>2){
                hash[s[start]]--;
                if(hash[s[start]]==0){
                    hash.erase(s[start]);
                }
                start++;
            }
            ans = max(ans, i-start+1);
        }
        return ans;
    }
};