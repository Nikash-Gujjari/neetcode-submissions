#include <utility>
#include <stack>
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        std::stack<std::pair<std::size_t, int>> process_stack{};
        int max_area{0};
        for(std::size_t index{0}; index < heights.size(); index++) {
            if(process_stack.empty()) {
                process_stack.push({index, heights[index]});
            } else {
                std::size_t extend_left_width{1};
                std::size_t last_pop_index{index};
                while(!process_stack.empty() && heights[index] < process_stack.top().second) {
                    auto& [pop_index, pop_height] = process_stack.top();
                    int pop_area{static_cast<int>(index - pop_index) * pop_height};
                    process_stack.pop();
                    max_area =  std::max(pop_area, max_area);
                    extend_left_width++;
                    last_pop_index = pop_index;
                }
                process_stack.push({last_pop_index, heights[index]});
            }
        }

        while(!process_stack.empty()) {
            auto[pop_index, pop_height] = process_stack.top();
            int pop_area{static_cast<int>((heights.size() - pop_index) * pop_height)};
            max_area =  std::max(pop_area, max_area);
            process_stack.pop();
        }
        return max_area;

                       


    }
};
