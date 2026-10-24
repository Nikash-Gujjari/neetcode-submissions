#include <stack>
#include <string>
#include <vector>

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        std::stack<int> operands; // Holds a stack of operands to evaluate

        for (const string& token : tokens) {
            // We check if we get an operation instead of a number and if so
            // we pop 2 last two number on the stack as operands for the operation
            // and push the result of the operation on the stack
            if (token.size() == 1 &&
                (token[0] == '+' || token[0] == '-' ||
                 token[0] == '*' || token[0] == '/')) {

                int b{operands.top()}; 
                operands.pop();
                int a{operands.top()}; 
                operands.pop();
                int result{};

                switch (token[0]) {
                    case '+': result = a + b; break;
                    case '-': result = a - b; break;
                    case '*': result = a * b; break;
                    case '/': result = a / b; break;
                }

                operands.push(result);
            } else {
                // If we get a number, then we just have a new operand to push on 
                // the stack for later processing
                operands.push(std::stoi(token));
            }
        }
        
        // For valid expressions, after evalauting all expressions we would have
        // only one operand that represents the result of the full expression
        return operands.top();
    }
};