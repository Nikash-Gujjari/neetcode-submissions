class Solution {
public:
    int search(vector<int>& nums, int target) {
    // Classic Binary Search Algorithm using two pointers.
    // NOTE: Optimizations to use m = l + (r - l)/2 and setting l = m + 1 instead of m
    
    std::size_t l{0};
    std::size_t r{nums.size() - 1};

    while(l < r) {
        std::size_t m{l + (r - l ) / 2}; // Use this instead of (l + r) / 2 to avoid overflow
        if(nums[m] < target) {
            l = m + 1; // Prevents infinite m = l 
        } else if (nums[m] > target) {
            r = m;
        } else {
            return static_cast<int>(m);
        }
    }

    return (nums[l] == target) ? static_cast<int>(l) : -1; // If not found return - 1 

    }
};