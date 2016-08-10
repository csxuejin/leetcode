class Solution {
private:
    vector<int> res;
    int len;
    unordered_map<int, bool> hash;
    void help(int num){
        res.push_back(num);
        hash[num] = true;
        for(int i=0; i<len; i++){
            int t = num^(1<<i);
            if(hash.find(t) == hash.end()){
                help(t);
                return;
            }
        }
    }
public:
    vector<int> grayCode(int n) {
        len = n;
        help(0);
        return res;
    }
};