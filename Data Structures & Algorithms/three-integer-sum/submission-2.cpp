#include <algorithm>
#include <vector>
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        // Approach:

        // Sort the input as an O(nlogn) operation. Then iterate through the vector
        // and for each element (i) employ the sorted TwoSum algorithm using twoPointers in which
        // l starts at index i + 1 and r starts at the right end (nums.size() - 1) and our condition
        // is to find nums[i], nums[l], nums[r] s.t. nums[i] + nums[l] + nums[r] = 0. If the sum is > 0
        // then we do r--, if the sum is < 0 we do l++, otherwise if the sum is 0 we found a 3sum. The
        // twoSum algorithm is O(n) so doing it n times is O(n^2), giving an overall complexity of
        // O(n^2) with O(1) space [note: sort() in C++ has O(logn) auxiliarry space]

        // To make sure no duplicates occur i is incremented to an i s.t. nums[new_i] != nums[prev_i]
        // and upon finding a {nums[i], nums[l], nums[r]} 3Sum, the l is incremeneted similary s.t.
        // nums[new_l] != nums[prev_l]. 


        std::sort(nums.begin(), nums.end()); // Sorting 
        std::vector<std::vector<int>> res{}; // Return
        for(std::size_t i{0}; i < nums.size() - 2; i++) {
            while(i != 0 && i < nums.size() - 2 && nums[i] == nums[i - 1]) { // Increment i to a new value not seen before
                i++;
            }

            std::size_t l{i + 1};
            std::size_t r{nums.size() - 1};

            while(l < r) {
                int threeSum{nums[i] + nums[l] + nums[r]};

                // TwoSum algorithm using two pointers l and r, which start after i and
                // at the end of the vector, respectively
                if(threeSum > 0) {
                    r--;
                } else if(threeSum < 0) {
                    l++;
                } else {
                    res.push_back(std::vector<int>{nums[i], nums[l], nums[r]});
                    l++;
                    // Making sure l is incremented to a unique value.
                    while(l < nums.size() - 1 && nums[l] == nums[l - 1]) {
                        l++;
                    }
                    r--;
                }
            }
        }
        return res;   
    }
};
