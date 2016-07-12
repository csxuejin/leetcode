class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res;
        if(numRows == 0)  return res;
        res.push_back(vector<int>{1});
        for(int i=1; i<numRows; i++){
            vector<int> vec{1};
            for(int j=1; j<i; j++){
                vec.push_back(res[i-1][j-1] + res[i-1][j]);
            }
            vec.push_back(1);
            res.push_back(vec);
        }
        return res;
    }
};