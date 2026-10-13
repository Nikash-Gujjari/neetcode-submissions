#include <array>
class Solution {
public:
    bool isAnagram(string s, string t) {
        std::array<int, 256> s_freq{0};
        std::array<int, 256> t_freq{0};
        for(unsigned char c : s) {
            s_freq[c]++;
        } 
        for(unsigned char c: t) {
            t_freq[c]++;
        }

        return s_freq == t_freq;

    }
};
