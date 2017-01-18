class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.empty()) 
            return 0;

        int tMin = prices[0], tMax = INT_MIN;
        for (int i=0; i<prices.size(); i++){
            tMin = min(tMin, prices[i]);
            tMax = max(tMax, prices[i]-tMin);
        }
        return tMax;
    }
};