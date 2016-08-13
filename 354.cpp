class Solution {
public:
    static bool cmp(pair<int,int> a, pair<int,int> b){
        if(a.first!=b.first){
            return a.first<b.first;
        }else{
            return a.second>b.second;
        }
    }
    int maxEnvelopes(vector<pair<int, int>>& envelopes) {
        sort(envelopes.begin(), envelopes.end(), cmp);
        vector<int> dp;
        for(int i=0; i<envelopes.size(); i++){
            auto it = lower_bound(dp.begin(), dp.end(), envelopes[i].second);
            if(it==dp.end()){
                dp.push_back(envelopes[i].second);
            }else{
                *it = envelopes[i].second;
            }
        }
        return dp.size();
    }
};