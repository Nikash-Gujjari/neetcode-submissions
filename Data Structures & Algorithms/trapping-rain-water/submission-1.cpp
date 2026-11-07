class Solution {
public:
    int trap(vector<int>& height) {
        // Approach
        // The amount of water stored at any position (p) between the left (l) and right (r) wall is
        // the difference between the shorter wall and p: min(l, r) - p. 
        // Use a two pointer approach at each end, while keeping track of the maximum height seen
        // on that side. We increment the pointer based upon which side's maximum height is 
        // smaller, since that is the limiting wall for a position's water capacity.
        // Note: Say maxLeft < maxRight, then we already know that any future value of 
        // maxRight will also be < maxLeft, so maxLeft will alwys be the bottleneck/limitation.
        // When incrementing, we update max Left or Right's value if a taller height is 
        // found and then max Left or Right - p as the water that is storable there

        if(height.size() <= 2) {
            return 0;
        }

        std::size_t l{0};
        std::size_t r{height.size() - 1};

        int maxLeft{height[l]};
        int maxRight{height[r]};

        int trapped_water{0};

        while(l < r) {
            if(maxLeft < maxRight) {
                maxLeft = std::max(maxLeft, height[++l]);
                trapped_water += maxLeft - height[l];
            } else {
                maxRight = std::max(maxRight, height[--r]);
                trapped_water += maxRight - height[r];
            }
        }
        return trapped_water;

    }
};