class Solution {
private:
    unordered_map<string, int> mm;
public:
    bool isPalindrome(string str){
        for(int i=0,j=str.size()-1; i<j; i++,j--){
            if(str[i]!=str[j]) return false;
        }
        return true;
    }

    vector<vector<int>> palindromePairs(vector<string>& words) {
        for(int i=0; i<words.size(); i++){
            string t = words[i];
            reverse(t.begin(), t.end());
            mm[t] = i;
        }
        vector<vector<int>> res;
        if(mm.find("")!=mm.end()){
            for(int i=0; i<words.size(); i++){
                if(i!=mm[""] && isPalindrome(words[i])){
                    res.push_back({mm[""], i});
                }
            }
        }
        
        for(int i=0; i<words.size(); i++){
            for(int j=0; j<words[i].size(); j++){
                string left = words[i].substr(0,j);
                string right = words[i].substr(j,words[i].size()-j);
                
                if(mm.find(left)!=mm.end() && isPalindrome(right) && mm[left]!=i){
                    res.push_back({i,mm[left]});
                }
                if(mm.find(right)!=mm.end() && isPalindrome(left) && mm[right]!=i){
                    res.push_back({mm[right], i});
                }
            }
        }
        return res;
    }
};