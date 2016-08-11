class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<int,int> hash;
        for(int i=0; i<ransomNote.size(); i++){
            hash[ransomNote[i]]++;
        }
        for(int i=0; i<magazine.size(); i++){
            if(hash.find(magazine[i]) != hash.end()){
                hash[magazine[i]]--;
            }
        }
        for(auto it:hash){
            if(it.second>0) return false;
        }
        return true;
    }
};