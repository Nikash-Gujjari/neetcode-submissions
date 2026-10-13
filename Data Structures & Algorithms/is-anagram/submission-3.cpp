#include <array>
class Solution {
public:
    bool isAnagram(string s, string t) {
        std::array<int, 26> freq{0};
        for(unsigned char c : s) {
            freq[c - 97]++;
        } 
        for(unsigned char c: t) {
            freq[c - 97]--;
        }

        for(int i: freq) {
            if(i != 0) {
                return false;
            }
        }
        return true;

    }
};
