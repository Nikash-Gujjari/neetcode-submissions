#include <unordered_set>
class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_set<int> seen;
        for (int num : nums) {
            if(seen.contains(num)) {
                return true;
            }
            seen.insert(num);
        }
        return false;
    }
};