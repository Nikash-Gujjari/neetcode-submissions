#include <cstddef>
#include <cctype> 
class Solution {
public:
    bool isPalindrome(string s) {
        // Use a two pointer method: one from the left start and one from the right start.
        // When an ignored character (non-alphanumeric) shows up for either pointer, then shift the pointer
        // and continue. Otherwise, convert both characters to lower (if letters) and compare. If they
        // are not equal return false, since its not a valid palindrome. Otherwise, if all 
        // comparisons check out return true

        std::size_t left_pointer{0};
        std::size_t right_pointer_up_one{s.size()}; // Us right_pointer index + 1 to avoid getting -1 for size_t value
        while(left_pointer < right_pointer_up_one - 1) {

            // Shift left pointer if ignored character shows up
            if(!std::isalnum(s[left_pointer])) {
                left_pointer++;
                continue;
            }

            // Shift right pointer if ignored character show up
            if(!std::isalnum(s[right_pointer_up_one - 1])) {
                right_pointer_up_one--;
                continue;
            }

            // Check equality by comparing lowercase versions of characters. 
            // Note: For digits tolower() does nothing. 
            if(std::tolower(s[left_pointer]) != std::tolower(s[right_pointer_up_one - 1])) {
                return false;
            }

            // If comparison checks out, increment pointers for next comparison
            left_pointer++;
            right_pointer_up_one--;

        }

        // Returns true when no failed comparisons arise
        return true;
    }
};
