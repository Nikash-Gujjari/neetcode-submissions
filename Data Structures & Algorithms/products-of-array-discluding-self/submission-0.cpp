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
    //  **NOTE**: in code implementation suffix product is stored in reverse for faster creation operation

    vector<int> productExceptSelf(vector<int>& nums) {
        std::vector<int> prefix_products{}; // The product of all numbers before the current index. The first index gets value 1
        std::vector<int> suffix_products{}; // The product of all numbers after the current index. The last index gets value 1. To use O(1) push_back operations 
        std::vector<int> res{};

        prefix_products.push_back(1);
        for(std::size_t i{1}; i < nums.size(); i++) {
            prefix_products.push_back(prefix_products[i-1] * nums[i - 1]);
        }

        // **NOTE**: Suffix product is built in reverse to take advantage of O(1) push_back operations for vectors
        // Alternaitvely it could have been implemented using the <deque> library
        suffix_products.push_back(1);
        for(std::size_t i{nums.size() - 1}; i > 0; i--) {
            suffix_products.push_back(suffix_products.back() * nums[i]);
        }

        for(std::size_t i{0}; i < prefix_products.size(); i++) {
            res.push_back(prefix_products[i] * suffix_products[suffix_products.size() - 1 - i]);
            // Suffix_products indexing is based on the fact it is stored in reverse
        }

        return res;
    }
};
