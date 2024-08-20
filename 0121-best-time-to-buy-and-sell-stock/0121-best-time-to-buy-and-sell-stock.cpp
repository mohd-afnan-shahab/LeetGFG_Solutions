class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int minPrice = prices[0];
        int maxProfit = 0;

        for(int i = 1; i < n; i++){
            int currentProfit = prices[i] - minPrice;
            maxProfit = max(maxProfit, currentProfit);

            minPrice = min(minPrice, prices[i]);
        }
        return maxProfit;
    }
};
