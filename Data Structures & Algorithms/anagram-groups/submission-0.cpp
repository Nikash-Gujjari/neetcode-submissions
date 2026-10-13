#include <unordered_map>
#include <array>
class Solution {
public:

    // Use Serialization of a freq map to a string in which 'a' -> 1, 'b' -> 2, ...
    // is converted to 1#2#... so that this is hashable in an unordered_map. Containers
    // in C++ don't have default hash functions to be used in unordered_map.
    std::string freq_map(const std::string& str) {
        std::array<int, 26> freq_map = {};
        for(char c: str) {
            freq_map[c - 'a']++;
        }
        std::string serialize_freq_map{};
        for(int count : freq_map) {
            serialize_freq_map += std::to_string(count) + "!";
        }
        return serialize_freq_map;

    } 
    
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
    std::vector<std::vector<string>> ret_list{};
    std::unordered_map<std::string, std::size_t> unique_freq_maps_to_ret_list_index{}; // Map of unique freq map -> index in the ret list that has the group of string of the same freq_map
    for(std::string& s : strs) {
        std::string curr_freq_map = freq_map(s);
        if(unique_freq_maps_to_ret_list_index.contains(curr_freq_map)) {
            ret_list[unique_freq_maps_to_ret_list_index[curr_freq_map]].push_back(s);
        } else {
            unique_freq_maps_to_ret_list_index[curr_freq_map] = ret_list.size();
            ret_list.push_back({s});
        }
    }

    return ret_list;

    }
};
