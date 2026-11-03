#include <utility>
#include <stack>
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        // Create a monotonic stack of increasing heights for a rectangle (height, left most index).
        // Left most index represents how far to the left that rectangle can be extended.  
        // When we find a height (current rectangle) that breaks the monotonic sequence we pop of all   
        // elements in the stack that are >= to the height of that rectangle. For each element, we use the 
        // element's index to find a width for a rectangle area from [popped_element] -> [curr rectangle].
        // This represents extending  that rectangle area to the right as far as possible. 
        // Thus, this area has height of element and width of index - popped_element_index. We check if
        // this area is greater than our current max area and update. Afrer popping of all elements we 
        // add the current rectangle's (height, last popped elements index) (represents extending
        // the current rectangle height as far left as possible) for continous processing

        std::stack<std::pair<std::size_t, int>> process_stack{};
        int max_area{0};
        for(std::size_t index{0}; index < heights.size(); index++) {
            if(process_stack.empty()) { // If we don't have any elements to compare to we push and continue
                process_stack.push({index, heights[index]});
            } else {
                std::size_t last_pop_index{index};
                // Popping elements and calculating their rectangular area by extending right towards
                // the current index
                while(!process_stack.empty() && heights[index] < process_stack.top().second) {
                    auto& [pop_index, pop_height] = process_stack.top();
                    int pop_area{static_cast<int>(index - pop_index) * pop_height};
                    process_stack.pop();
                    max_area =  std::max(pop_area, max_area);
                    last_pop_index = pop_index;
                }
                // Using the last popped element's index and the fact we popped off all elements with
                // height >= current rectangle's height to know how far to the left the current rectangle
                // can be extended and store this information
                process_stack.push({last_pop_index, heights[index]});
            }
        }

        // Repeat of earlier algorithm for all elements left in the stack. These elements all
        // represent rectangles that are extended all the way to the right
        while(!process_stack.empty()) {
            auto[pop_index, pop_height] = process_stack.top();
            int pop_area{static_cast<int>((heights.size() - pop_index) * pop_height)};
            max_area =  std::max(pop_area, max_area);
            process_stack.pop();
        }
        return max_area;

                       


    }
};
