#include <unordered_set>
#include <print>
class Solution {
public:
    bool insert_if_absent(std::unordered_set<char>& my_set, char value) {
        // Inserts value; returns true if added, false if it already contained it
        return my_set.insert(value).second;
    }
    bool isValidSudoku(vector<vector<char>>& board) {
        std::vector<std::unordered_set<char>> rows(9);
        std::vector<std::unordered_set<char>> cols(9);
        std::vector<std::unordered_set<char>> squares(9);

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
