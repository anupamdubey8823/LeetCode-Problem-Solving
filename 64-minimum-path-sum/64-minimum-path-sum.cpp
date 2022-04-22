#define vi vector<int>
#define vvi vector<vi>
class Solution {
    int minPathHelper(vvi &grid, int rowIndex, int colIndex, int rows, int cols, vvi &minPathDP) {
        if (rowIndex < 0 || colIndex < 0)
            return INT_MAX;
        else if (rowIndex == 0 && colIndex == 0)
            return grid[rowIndex][colIndex];
        if (minPathDP[rowIndex][colIndex] != -1)
            return minPathDP[rowIndex][colIndex];
        return minPathDP[rowIndex][colIndex] = grid[rowIndex][colIndex] + min(minPathHelper(grid, rowIndex-1, colIndex, rows, cols, minPathDP), minPathHelper(grid, rowIndex, colIndex-1, rows, cols, minPathDP));
    }
public:
    int minPathSum(vector<vector<int>>& grid) {
        int rows = grid.size(), cols = grid[0].size();
        vvi minPathDP(rows, vi(cols, -1));
        return minPathHelper(grid, rows-1, cols-1, rows, cols, minPathDP);
    }
};