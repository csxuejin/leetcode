class Solution {
private:
    vector<vector<int>> vec;
public:
    static bool cmp(string a, string b){
        return a.size() > b.size();
    }
    
    bool duplicate(vector<int>&a, vector<int>&b){
        for(int i=0; i<a.size(); i++){
            if(a[i]==1 && a[i]==b[i]) return true;
        }
        return false;
    }
    
    int maxProduct(vector<string>& words) {
        sort(words.begin(), words.end(), cmp);
        vec.assign(words.size(), vector<int>(26,0));
        for(int i=0; i<words.size(); i++){
            for(int j=0; j<words[i].size(); j++){
                vec[i][words[i][j]-'a'] = true;
            }
        }
        int ans = 0;
        for(int i=0; i<words.size(); i++){
            for(int j=i+1; j<words.size(); j++){
                if(words[i].size()*words[j].size() < ans) break;
                if(!duplicate(vec[i], vec[j])) ans = words[i].size() * words[j].size();
            }
        }
        return ans;
    }
};
