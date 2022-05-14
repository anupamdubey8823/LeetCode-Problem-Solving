class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        int center = edges[0][0];
        if (edges[0][0] == edges[1][0] || edges[0][0] == edges[1][1])
            return edges[0][0];
        return edges[0][1];
    }
};