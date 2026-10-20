#include <unordered_set>
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.empty()) {
            return 0;
        }

        std::unordered_set<int> set_of_nums{}; // Holds nums as a set
        std::unordered_set<int> possible_starts{}; // Holds possible starts of a sequence,
        // which is defined as a number n for which n - 1 does not exist in set of nums

        // populating set of nums
        for(int num : nums) {
            set_of_nums.insert(num);
        }

        // populating possible starts
        for(int num: set_of_nums) {
            if(!set_of_nums.contains(num - 1)) {
                possible_starts.insert(num);
            }

        }


        // Calculating longest sequence by trying to create a sequence
        // from each of the possible starts. This is still O(n) because
        // at most there are O(n) lookups
        int longest{1};

        for(int num : possible_starts) {
            int curr_longest{1};
            int curr{num};
            while(set_of_nums.contains(curr + 1)) {
                curr_longest++;
                curr++;
            }

            longest = (longest > curr_longest) ? longest : curr_longest;
        }

        return longest;

    }
};
