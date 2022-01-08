class Solution {
    int cherrypickUtil(int row, int col1, int col2, vector<vector<int>> &grid, vector<vector<vector<int>>> & dpCache) {
        if (row < 0 || row >= grid.size() || col1 < 0 || col1 >= grid[0].size() || col2 < 0 || col2 >= grid[0].size())
            return 0;
        if (dpCache[row][col1][col2] != -1)
            return dpCache[row][col1][col2];
//         Computing the max cherries of the current grid co-ordinate
        int result = 0;
        result += grid[row][col1];
        if (col1 != col2) {
            result += grid[row][col2];
        }
        if (row != grid.size()-1) {
            int maxCherries = 0;
            for (int nextCol1 = col1-1; nextCol1 <= col1+1; nextCol1++) {
                for (int nextCol2 = col2-1; nextCol2 <= col2+1; nextCol2++) {
                    int nextRow = row+1;
                    maxCherries = max(maxCherries, cherrypickUtil(nextRow, nextCol1, nextCol2, grid, dpCache));
                }
            }
            result += maxCherries;
        }
        return dpCache[row][col1][col2] = result;
    }
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<vector<int>>> dpCache(m, vector<vector<int>>(n, vector<int>(n, -1)));
        return cherrypickUtil(0, 0, n-1, grid, dpCache);
    }
};