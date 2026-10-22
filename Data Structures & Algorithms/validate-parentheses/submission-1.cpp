#include <stack>
#include <string>

class Solution {
public:
    bool isValid(std::string s) {
        std::stack<char> st; // The stack pushes all opening characters as they are found
        // when a closing character is found it checks if the top of the stack has the corresponding
        // opening character. If not, it returns false; if true it pops that opening character.
        // At the end there is verification for the stack being empty, which represents all 
        // opening characters are closed. 

        for (char c : s) {
            if (c == '(' || c == '{' || c == '[') { // Push opening characters
                st.push(c);
            } else {
                if (st.empty()) { // If we found a closing character and no opening character (empty stack)
                // this is invalid
                    return false;
                }  

                // Pop the top of the stack opening character and verify it correlates to the current 
                // closed character
                char t{st.top()};
                st.pop();

                if ((c == ')' && t != '(') || (c == '}' && t != '{') || (c == ']' && t != '[')) {
                    return false;
                }
                    
            }
        }

        return st.empty(); // Verifies that all opening characters were closed
    }
};