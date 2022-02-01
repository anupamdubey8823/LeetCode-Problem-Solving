class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buy = prices[0], len = prices.size(), currProfit = 0, totalProfit = 0;
        for (int i = 1; i < len; i++) {
            currProfit = prices[i] - buy;
            totalProfit = max(totalProfit, currProfit);
            if (currProfit < 0) {
                buy = prices[i];
                currProfit = 0;
            }
        }
        return totalProfit;
    }
};