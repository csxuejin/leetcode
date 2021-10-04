class Solution {
public:
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        int row = matrix.size(), col = matrix[0].size();
        int ans = INT_MIN;
        for(int l=0; l<col; l++){
            vector<int> sum(row,0);
            for(int r=l; r<col; r++){
                for(int i=0; i<row; i++){
                    sum[i] += matrix[i][r];
                }  
                
                set<int> ss;
                ss.insert(0); // this is important;
                int cum = 0;
                for(int i=0; i<sum.size(); i++){
                    cum += sum[i];
                    auto it = ss.lower_bound(cum-k);
                    if(it!=ss.end()){
                        ans = max(ans, cum-*it);
                    }
                    ss.insert(cum);
                }
            }
        }
        return ans;
    }
};
