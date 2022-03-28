class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int sell=0, buy=INT_MIN;
        int preBuy=0, preSell=0;
        for(int i=0; i<prices.size(); i++){
            preBuy = buy;
            buy = max(buy, preSell-prices[i]);
            preSell = sell;
            sell = max(sell, preBuy+prices[i]);
        }
        return sell;
    }
};