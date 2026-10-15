class Solution {
public:
    // Solution: Calculate the prefix and suffix product vectors for any given index, where the prefix is all numbers before and the suffix consists of all number after
    // Then multiplying each corresponding index together gives a vector in which for a given index i
    // The value at that index is the product of all numbers before and after the index, excluding the number at that index

    // Visually,
    // input = [x_1, x_2, ..., x_n ]
    // prefix product = [1, x_1, x_2*x_1, x_3*x_2*x_1..., x_n-1 * x_n-2*... x_1]
    // suffix product = [x_n * x_n-1 ... x_2, x_n-1*... x_3, .... 1]
    // res = [x_n * x_n-1... *x_2, x_n-1*... x_3, .... x_n-1*x_n-2*...x_1]

    // **NOTE**: To make an O(1) solution we can use a single vector to hold the prefix product and go through and multiply it by a running suffix product, instead of making arrays for both, and then return
    // the single vector as the result
    vector<int> productExceptSelf(vector<int>& nums) {
        std::vector<int> res{};

        // Populating result with our prefix product array
        res.push_back(1);
        for(std::size_t i{1}; i < nums.size(); i++) {
            res.push_back(res[i-1] * nums[i - 1]);
        }

        // Multiplying the prefix product array by the continaully compute suffxi product
        int suffix_product{1};
        for (std::size_t i = nums.size(); i-- > 0;) { // Here a post-decrement comparison is used so that i never becomes -1
            res[i] *= suffix_product;
            suffix_product *= nums[i];
        }

        return res;
    }
};
