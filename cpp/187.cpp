class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        unordered_map<string, int> hash;
        vector<string> res;
        for(int i=9; i<s.size(); i++){
            string str = s.substr(i-9, 10);
            hash[str]++;
        }
        for(auto it:hash){
            if(it.second>1){
                res.push_back(it.first);
            }
        }
        return res;
    }
};