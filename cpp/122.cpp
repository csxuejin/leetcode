class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buy = INT_MIN, sell=0;
        for(int i=0; i<prices.size(); i++){
            int t = buy;
            buy = max(sell-prices[i], buy);
            sell = max(t+prices[i], sell);
        }
        return sell;
    }
};