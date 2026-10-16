#include <unordered_set>
class Solution {
public:
    // Use bitmask instead of hashset for space eficiency
    bool insert_if_absent(int& my_set, char value) {
        int mask{1 << (value - '1')};
        int new_set{my_set | mask};
        if(my_set == new_set) {
            return false;
        } 
        my_set = new_set;
        return true;

    }
    bool isValidSudoku(vector<vector<char>>& board) {
        std::vector<int> rows(9);
        std::vector<int> cols(9);
        std::vector<int> squares(9);

        for(std::size_t i{0}; i < board.size(); i++) {
            for(std::size_t j{0}; j < board[0].size(); j++) {
                if(char value{board[i][j]}; value != '.') {
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
