#include <cstddef>
#include <vector>
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        // Solution: Use a left pointer and right pointer that increment respectively to the other
        // end. Check if the sum of the numbers pointed by the pointers is >, <, or = to the target.
        // If > then, we need a smaller right-side number, so we decrement the right pointer.
        // If < then, we need a larger left-side number, so we decrement the left pointer.
        // If = then, we found the return value.

        // This works because the vector is sorted and we know the right-most and left-most numbers
        // are the greatest and smallest numbers. Therefore, when we find a sum too large the only 
        // option is to not use the right-most number and vice-versa. This logic repeats until
        // a solution is found. 

        // Note: A binary search approach of taking a given number and finding its complement is
        // O(n log n) because for each number (n) you do a binary search n log n worse case. Realistically
        // This is O (n/2 * logn), which is still O(n log n)

        std::size_t left_pointer{0};
        std::size_t right_pointer_up_one{numbers.size()};

        while(true) { // We are guarenteed a solution
            int pointer_sum{numbers[left_pointer] + numbers[right_pointer_up_one - 1]}; // Calculate sum

            // Change pointers as needed when are sum is > or <, or we found the return value
            if(pointer_sum < target) {
                left_pointer++;
            } else if(pointer_sum > target) {
                right_pointer_up_one--;
            } else  {
                return std::vector<int>{static_cast<int>(left_pointer + 1), static_cast<int>(right_pointer_up_one)};
            }
        }

        return std::vector<int>{0, 0}; // Never ran because we are guarenteed a solution
        
    }
};
