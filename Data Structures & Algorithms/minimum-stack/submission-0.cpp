#include <stack>
class MinStack {
public:
    std::stack<int> order_stack; // Stack to keep track of order of elements and always pushes the next 
    // element
    std::stack<int> min_stack; // Stack that keeps track of the minimum element and pushes when a new 
    // minimum element is found 
    MinStack() {}
    
    void push(int val) {
        order_stack.push(val);
        if(min_stack.empty() || val <= min_stack.top()) { // When a new minimum element is found the
        // min_stack pushes. <= is used because removal of one number in a set of duplicates minimums
        // should not change the min, but our MinStack pop() function is set to always remove the 
        // top of min_stack if the order_stack element is the same. 
        // Therefore after popping a minimum element that is
        // duplicated, we should have the same number (a duplicate) ready to be on the top of the min_stack
            min_stack.push(val);
        }
    }
    
    void pop() {
        if(order_stack.top() == min_stack.top()) { // If the top element is the min then
             // we remove the same element from min_stack. Otherwise we only pop from order_stack
            min_stack.pop();
        }
        order_stack.pop();
    }
    
    int top() {
        return order_stack.top();
    }
    
    int getMin() {
        return min_stack.top();
    }
};
