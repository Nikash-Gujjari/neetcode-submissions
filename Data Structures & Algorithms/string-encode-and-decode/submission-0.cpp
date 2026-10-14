#include <string>
class Solution {
public:

    string encode(vector<string>& strs) {
        std::string ret;
        for(std::string& str : strs) {
            ret += std::to_string(str.size()) + "$" + str;
        }
        return ret;
    }

    vector<string> decode(string s) {
        std::vector<std::string> ret{};
        std::size_t curr_pos{0};
        while(curr_pos < s.size()) {
            std::size_t next_dollar_pos = s.find("$", curr_pos);
            std::size_t word_length{static_cast<std::size_t>(std::stoull(s.substr(curr_pos, next_dollar_pos - curr_pos)))};
            ret.push_back(s.substr(next_dollar_pos + 1, word_length));
            curr_pos = next_dollar_pos + 1 + word_length;
        }
        return ret;
    }
};