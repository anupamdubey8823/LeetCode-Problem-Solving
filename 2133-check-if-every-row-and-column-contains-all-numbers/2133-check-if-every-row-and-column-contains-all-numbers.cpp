class Solution {
public:
    bool checkValid(vector<vector<int>>& matrix) {
        int rows = matrix.size(), cols = matrix[0].size(), colsum = 0, rowsum = 0;
        int rowxor = 0, colxor = 0, requiredSum = rows*(rows+1)/2;
        for (int row = 0; row < rows; row++) {
            rowxor = 0, colxor = 0;
            rowsum = 0, colsum = 0;
            for (int col = 0; col < cols; col++) {
                rowxor = rowxor ^ (matrix[row][col] ^ (col+1));
                rowsum += matrix[row][col];
                
                colxor = colxor ^ (matrix[col][row] ^ (col+1));
                colsum += matrix[col][row];
            }
            if (rowxor || colxor || colsum != requiredSum || rowsum != requiredSum)
                return false;
        }
        return true;
    }
};