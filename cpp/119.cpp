class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<vector<int>> vec;
        vec.push_back(vector<int>{1});
        for(int i=1; i<=rowIndex; i++){
            vector<int> tmp{1};
            for(int j=1; j<i; j++){
                tmp.push_back(vec[i-1][j-1] + vec[i-1][j]);
            }
            tmp.push_back(1);
            vec.push_back(tmp);
        }
        return vec[rowIndex];
    }
};