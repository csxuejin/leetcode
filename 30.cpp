class Solution {
private:
    int wordLen;
public:
    bool helper(string s, unordered_map<string, int> hash){
        for(int i=0; i<s.size(); i+=wordLen){
            string t = s.substr(i,wordLen);
            if(hash.find(t)==hash.end()) return false;
            hash[t]--;
            if(hash[t]<0) return false;
            if(hash[t]==0) hash.erase(t);
        }
        return hash.empty();
    }

    vector<int> findSubstring(string s, vector<string>& words) {
         unordered_map<string, int> hash;
         wordLen = words[0].size();
         int len = wordLen * words.size();
         for(int i=0; i<words.size(); i++){
             hash[words[i]]++;
         }
         
         vector<int> vec;
         for(int i=0; i<s.size(); i++){
             if(s.size()-i<len) break;
             string t = s.substr(i,wordLen);
             if(hash.find(t)!=hash.end()){
                 if(helper(s.substr(i,len),  hash)) 
                    vec.push_back(i);
             }
         }
         
         return vec;
    }
};