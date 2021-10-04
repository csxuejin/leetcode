class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res;
        unordered_map<string, int> hash;
        for(int i=0; i<strs.size(); i++){
            string str = strs[i];
            sort(strs[i].begin(), strs[i].end());
            if(hash.find(strs[i]) != hash.end()){
                res[hash[strs[i]]].push_back(str);
            }else{
                res.push_back(vector<string>{str});
                hash[strs[i]] = res.size()-1;
            }
        }
        return res;
    }
};

