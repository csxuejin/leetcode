class Solution {
private:
    vector<vector<int>> res;
    vector<int> vec;
    int tar;

public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        tar = target;
        helper(candidates, 0, 0);
        return res;
    }
    
    void helper(vector<int>&can, int pos, int sum){
        for(int i=pos; i<can.size(); i++){
            if(i>pos && can[i-1]==can[i]) 
                continue;  //过滤掉重复的方案
            int s = sum + can[i];
            if(s==tar){
                vec.push_back(can[i]);
                res.push_back(vec);
                vec.pop_back();
                return;
            }else if(s>tar){
                return;
            }else{
                vec.push_back(can[i]);
                helper(can, i+1, s);
                vec.pop_back();
            }
        }
    }
};