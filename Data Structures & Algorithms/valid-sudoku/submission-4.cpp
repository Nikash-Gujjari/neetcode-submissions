#include <unordered_set>
class Solution {
public:
    // Use bitmask instead of hashset for space eficiency
    bool insert_if_absent(int& my_set, char value) {
        int mask{1 << (value - '1')}; // '1' -> 0, '2' -> 1, ... char -> index in set
        int new_set{my_set | mask}; // Using the mask to update our set
        if(my_set == new_set) { // If our set didn't change then we attempted to add a value already present
            return false;
        } 
        my_set = new_set;
        return true;

    }
    bool isValidSudoku(vector<vector<char>>& board) {

        // Each index of the vector is an int that represents a bitmask. This bitmask
        // is used as set to see if duplicate values are found within a row, column, or 3x3 square
        std::vector<int> rows(9);
        std::vector<int> cols(9);
        std::vector<int> squares(9);

        for(std::size_t i{0}; i < board.size(); i++) {
            for(std::size_t j{0}; j < board[0].size(); j++) {
                if(char value{board[i][j]}; value != '.') { // Ignore '.', which represents empty
                    // FORCE all 3 insertions to run completely independent of each other
                    bool row_inserted{insert_if_absent(rows[i], value)};
                    bool col_inserted{insert_if_absent(cols[j], value)};
                    bool sqr_inserted{insert_if_absent(squares[(i / 3) * 3 + j / 3], value)};

                    // If ANY insertion failed (returned false), it's an invalid board
                    if (!row_inserted || !col_inserted || !sqr_inserted) {
                        return false;
                    }
                }
            }
        }

        return true;
    }
};
