class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size() == 0){
            return 0;
        }
        int tMin = prices[0];
        int tMax = INT_MIN;
        for (int i=0; i<prices.size(); i++){
            if(prices[i] < tMin ){
                tMin = prices[i];
            }
            if(prices[i]-tMin > tMax){
                tMax = prices[i] - tMin;
            }
        }
        return tMax;
    }
};