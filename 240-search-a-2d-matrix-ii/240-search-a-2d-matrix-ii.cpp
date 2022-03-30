class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rows = matrix.size(), cols = rows ? matrix[0].size() : 0;
        int currRow = 0, currCol = cols-1;
        while (currRow < rows && currCol >= 0) {
            if (matrix[currRow][currCol] == target)
                return true;
            matrix[currRow][currCol] > target ? currCol-- : currRow++;
        }
        return false;
    }
};