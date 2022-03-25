class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        sort(costs.begin(), costs.end(), [](vector<int> &person1, vector<int> &person2) {
            return (person1[1] - person1[0] > person2[1] - person2[0]);
        });
        
        int len = costs.size(), mid = len / 2;
        int i = 0, j = mid, minCost = 0;
        while (i < j && j < len) {
            minCost += costs[i][0] + costs[j][1];
            i++, j++;
        }
        return minCost;
    }
};