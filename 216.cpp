class Solution {
private:
    vector<vector<int>> res;
    vector<int> vec;
    int tar;
    int len;
public:
    vector<vector<int>> combinationSum3(int k, int n) {
         tar = n;
         len = k;
         for(int i=1; i<=9; i++){
             if(i>n) break;
             dfs(i, 0);
         }
         return res;
    }
    
    void dfs(int cur, int sum){
        vec.push_back(cur);
        sum += cur;
        if(vec.size() == len){
            if(sum==tar){
                res.push_back(vec);
            }
            vec.pop_back();
            return;
        }
        for(int i=cur+1; i<=9; i++){
            dfs(i, sum);
        }
        vec.pop_back();
    }
};