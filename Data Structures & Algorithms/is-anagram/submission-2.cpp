#include <array>
class Solution {
public:
    bool isAnagram(string s, string t) {
        std::array<int, 256> freq{0};
        for(unsigned char c : s) {
            freq[c]++;
        } 
        for(unsigned char c: t) {
            freq[c]--;
        }

        for(int i: freq) {
            if(i != 0) {
                return false;
            }
        }
        return true;

    }
};
