#include <array>
#include <unordered_map>
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // Frequency Map of num -> freq
        std::unordered_map<int, std::size_t> freq_map{};
        for(int& num : nums) {
            freq_map[num]++;
        }

        // Freq_vector represents buckets of frequency of 0 -> nums.size()
        // Each bucket contains all number in nums that have a frequency equal
        // to the bucket index
        std::vector<std::vector<int>> freq_vector(nums.size() + 1);
        for(const auto&[key, value] : freq_map) {
            freq_vector[value].push_back(key);
        }

        std::vector<int> ret{};

        // Starting at the bucket for highest frequency and going backwards
        // add all numbers until k numbers are found
        for(std::size_t i{freq_vector.size() - 1}; i > 0; i--) {
            if(!freq_vector[i].empty()) {
                ret.insert(ret.end(), freq_vector[i].begin(), freq_vector[i].end());
                k = k - freq_vector[i].size();
            }

            if(k <= 0) {
                return ret;
            }
        }
        return ret;

    }
};
