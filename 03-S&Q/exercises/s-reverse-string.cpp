#include <string>
#include <stack>

using std::string; // Allows the use of 'string' instead of 'std::string'
using std::stack; // Allows the use of 'stack' instead of 'std::stack'

string reverseString(const string& str) {
    stack<char> charStack;
    string reversedString;
 
    for (char c : str) {
        charStack.push(c);
    }
 
    while (!charStack.empty()) {
        reversedString += charStack.top();
        charStack.pop();
    }
 
    return reversedString;
}
