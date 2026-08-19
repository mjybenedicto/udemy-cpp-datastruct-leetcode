#include <stack>

using std::stack; // This line allows you to use 'stack' instead of 'std::stack'


void sortStack(stack<int>& inputStack) {    
    stack<int> additionalStack;
 
    while (!inputStack.empty()) {
        int temp = inputStack.top();
        inputStack.pop();
 
        while (!additionalStack.empty() && additionalStack.top() > temp) {
            inputStack.push(additionalStack.top());
            additionalStack.pop();
        }
 
        additionalStack.push(temp);
    }
 
    while (!additionalStack.empty()) {
        inputStack.push(additionalStack.top());
        additionalStack.pop();
    }

}
