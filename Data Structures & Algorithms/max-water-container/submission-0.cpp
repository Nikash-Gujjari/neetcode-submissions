class Solution {
public:
    int maxArea(vector<int>& heights) {

        // Approach:
        // Use a two pointer approach one at each end. For each given l, r compute the maximum
        // amount of water that it can store, which is (r - l) * min(heights[l], heights[r]).
        // Afterwards, move the pointer to the smaller bar forward. We should move the smaller
        // bar pointer because the shorter bar is what dictates the height
        // [Note: min(heights[l], heights[r])] of the area and therefore moving the taller pointer 
        // instead never increases the area and can cause the algorithm to miss the optimal solution.

        std::size_t l{0};
        std::size_t r{heights.size() - 1};

        int max{0};

        while(l < r) {
            int currArea{static_cast<int>(r - l) * std::min(heights[l], heights[r])};
            max = std::max(currArea, max);

            if(heights[l] < heights[r]) {
                l++;
            } else {
                r--;
            }
        }

        return max;

    }
};
