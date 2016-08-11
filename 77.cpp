class Solution {
private:
    vector<vector<int>> res;
public:
    vector<vector<int>> combine(int n, int k) {
        vector<int> vec;
        dfs(n,k,1,vec);
        return res;
    }
    
    void dfs(int& n, int k, int pos, vector<int>&vec){
        if(k==0){
            res.push_back(vec);
            return;
        }
        
        for(int i=pos; i<=n; i++){
            if(n-i+1<k) break;
            vec.push_back(i);
            dfs(n,k-1,i+1,vec);
            vec.pop_back();
        }
    }
};
