#include <stack>
#include <vector>
#include <tuple>
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        std::stack<std::tuple<int,std::size_t>> prev_temps{}; // Stack of tuple of temperature, index in temperatures vector
        std::vector<int> result(temperatures.size(), 0); // Returning vector 

        // Algorithm is to maintain a monotonically decreasing sequence in our stack until we find
        // an element that is greater than our stack top. When such a greater element (g) is found we
        // process all elements in the stack that are < g by popping them off the stack and putting
        // the difference of their index in the given element's index, which is kept track of in the
        // stack, in the result vector. 
        // After iterating through temperatures, any elements left in the stack are part of
        // a monotic decreasing sequence for which a g wasn't found so we put 0 at their index
        for(int index{0}; index < temperatures.size(); index++) {
            int temp{temperatures[index]};
            while(!prev_temps.empty()) {
                auto tup = prev_temps.top(); // Tuple of temperature, index

                if(std::get<0>(tup) >= temp) { // Found an element e in the sequence that is >= to g
                // and since e is part of a monotonicly decreasing sequence we can be assured that all
                // elements before e are also >= g
                    break;
                }
                result[std::get<1>(tup)] = index - std::get<1>(tup); // Putting the difference of index
                // in the result
                prev_temps.pop(); // Popping the element after doing this
            } 
            prev_temps.push(std::tuple<int, size_t>(temp, index)); // Push temp, index in temperatures 
            // into the stack
        }

        // Any elements left in the stack are part of a monotic decreasing sequence 
        // for which a g wasn't found so we put 0 at their index
        while(!prev_temps.empty()) {
            auto tup = prev_temps.top(); // Tuple of temperature, index
            result[std::get<1>(tup)] = 0;
            prev_temps.pop();
        }

        return result;
    }
};
