class Solution {
    struct compare {
        bool operator()(vector<int> &x, vector<int> &y) {
            return pow(x[0], 2) + pow(x[1], 2) > pow(y[0], 2) + pow(y[1], 2);
        }
    };
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<vector<int>> closestPoints(k);
        priority_queue <vector<int>, vector<vector<int>>, compare> minDist;
        for (auto &point: points) {
            minDist.push(point);
        }
        for (int i = 0; i < k; i++) {
            vector<int> point = minDist.top();
            minDist.pop();
            closestPoints[i] = point;
        }
        return closestPoints;
    }
};