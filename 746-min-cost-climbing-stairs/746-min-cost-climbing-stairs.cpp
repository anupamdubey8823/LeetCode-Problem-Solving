class Solution {
    int minCostUtil(vector<int> &cost, int index, vector<int> &minCost) {
        if (index == 0 || index == 1)
            return cost[index];
        if (minCost[index] != -1)
            return minCost[index];
        return minCost[index] = min(minCostUtil(cost, index-1, minCost), minCostUtil(cost, index-2, minCost)) + cost[index];
    }
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int len = cost.size();
        vector<int> minCost(len+1, -1);
        return min(minCostUtil(cost, len-1, minCost), minCostUtil(cost, len-2, minCost));
    }
};