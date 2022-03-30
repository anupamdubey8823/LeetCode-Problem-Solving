class Solution {
    bool searchTarget(int row, int startCol, int endCol, vector<vector<int>> &matrix, int target) {
        while (startCol <= endCol) {
            int mid = startCol + (endCol - startCol)/2;
            if (target == matrix[row][mid])
                return true;
            else if (target > matrix[row][mid])
                startCol = mid+1;
            else
                endCol = mid-1;
        }
        return false;
    }
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rows = matrix.size(), cols = matrix[0].size();
        int rowIndex = 0;
        for (; rowIndex < rows-1; rowIndex++) {
            if (target >= matrix[rowIndex][0] && target < matrix[rowIndex+1][0])
                break;
        }
        return searchTarget(rowIndex, 0, cols-1, matrix, target);;
    }
};