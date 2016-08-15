class Solution {
public:
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        unordered_map<char, int> hash;
        int j=-1;
        int ans = 0;
        for(int i=0; i<s.size(); i++){
            hash[s[i]]++;
            while(hash.size()>k){
                hash[s[++j]]--;
                if(hash[s[j]]==0)
                    hash.erase(s[j]);
            }
            ans = max(ans, i-j);
        }
        return ans;
    }
};



