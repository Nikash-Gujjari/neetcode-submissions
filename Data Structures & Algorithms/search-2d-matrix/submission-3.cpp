class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {

        // Approach: use standard two pointer binary search with a conversion function of
        // index x,y -> z = x*matrix[0].size() + y. To convert back, 
        // x = z / matrix[0].size() and y = z % matrix[0].size()

        std::size_t l{0};
        std::size_t r{(matrix.size() - 1)*matrix[0].size() + (matrix[0].size() - 1)};

        while(l < r) {
            std::size_t m{l + (r - l)/2}; // Avoid overflow

            // Conversion of m number -> row, column in matrix
            std::size_t row{m / matrix[0].size()};
            std::size_t column{m % matrix[0].size()};

            if(matrix[row][column] < target) {
                l = m + 1; // Avoids infinite loop in case target is not in the matrix
            } else if(matrix[row][column] > target) {
                r = m;
            } else {
                return true;
            }
        }

        return matrix[l / matrix[0].size()][l % matrix[0].size()] == target; // Handles l = r check

    }
};
