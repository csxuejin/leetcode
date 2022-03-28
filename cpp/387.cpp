class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char, pair<int, int>> hash;
        for(int i=0; i<s.size(); i++){
            hash[s[i]].first++;
            hash[s[i]].second = i;
        }
        int id = s.size();
        for(auto p : hash){
            if(p.second.first == 1)
                id = min(id, p.second.second);
        }
        return id==s.size()? -1:id;
    }
};