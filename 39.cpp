class Solution {
private:
    vector<vector<int>> res;
    vector<int> vec;
    int tar;
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        tar = target;
        helper(candidates, 0, 0);
        return res;
    }
    
    void helper(vector<int>& can, int s, int pos){
        for(int i=pos; i<can.size(); i++){
            int sum = s + can[i];
            if(sum == tar){
                vec.push_back(can[i]);
                res.push_back(vec);
                vec.pop_back();
                return;
            }else if(sum>tar){
                return;
            }else{
                vec.push_back(can[i]);
                helper(can, sum, i);
                vec.pop_back();
            }
        }
    }
};
