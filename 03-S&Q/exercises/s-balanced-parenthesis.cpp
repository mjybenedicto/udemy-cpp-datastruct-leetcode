#include <string>
#include <stack>

using namespace std;

bool isBalancedParentheses(const string& parentheses) {
    stack<char> charStack;
    
    for (char p : parentheses) {
        if(p == '('){
            charStack.push(p);
        }
        else{
            if(charStack.empty() || charStack.top() != '(') {
                return false;
            }
            charStack.pop();
        }
    }
    if(charStack.empty()) {
        return true;
    }
    return false;
    
}
