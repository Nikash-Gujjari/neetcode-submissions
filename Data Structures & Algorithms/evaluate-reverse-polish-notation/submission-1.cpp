#include <stack>
#include <string>
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        std::stack<int> operand_stack{}; // Keep track of operands to be processed
        int num{};

        for(string token : tokens) {
            // Attempt to convert the string to a number
            auto [ptr, ec] = from_chars(token.data(), token.data() + token.size(), num); 
            // If that is possibe (no error and all chars were processed)
            // then we have a new operand number, so push that number onto the stack
            if (ec == errc{} && ptr == token.data() + token.size()) { 
                operand_stack.push(num);  
            } else {
                // If we don't have a number, we must have an operator (+, -, /, *)
                // To execute the operator pop the last 2 numbers on the
                // operand stack as operands for the operation. 
                // Push the result of this operation as a new operand for the
                // operand stack
                int op2{operand_stack.top()};
                operand_stack.pop();
                int op1{operand_stack.top()};
                operand_stack.pop();
                if(token == "+") {
                    operand_stack.push(op1 + op2);
                } else if(token == "-") {
                    operand_stack.push(op1 - op2);
                } else if(token == "*") {
                    operand_stack.push(op1 * op2);
                } else if(token == "/") {
                    operand_stack.push(op1 / op2);
                }

            }
        }
        // The last value in the operand stack is the result of executing
        // the whole expression 
        return operand_stack.top();

    }
};
