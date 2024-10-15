//#include<iostream>
//using namespace std;
//int main()
//{
 // cout<<"My first Experience";
//}
#include <iostream>
#include <stack>
#include <string>
#include <cctype>
#include <unordered_map>

int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    return 0;
}

bool isOperator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/';
}

std::string infixToPostfix(const std::string& infix) {
    std::stack<char> operators;
    std::string postfix;

    for (char c : infix) {
        if (isspace(c)) {
            continue; // Skip spaces
        }

        if (isalnum(c)) {
            postfix += c; // Append operand to output
        } else if (c == '(') {
            operators.push(c); // Push '(' onto stack
        } else if (c == ')') {
            // Pop from stack to output until '(' is found
            while (!operators.empty() && operators.top() != '(') {
                postfix += operators.top();
                operators.pop();
            }
            operators.pop(); // Remove '(' from stack
        } else if (isOperator(c)) {
            // Pop operators from stack to output based on precedence
            while (!operators.empty() && precedence(operators.top()) >= precedence(c)) {
                postfix += operators.top();
                operators.pop();
            }
            operators.push(c); // Push current operator onto stack
        }
    }

    // Pop all remaining operators in the stack
    while (!operators.empty()) {
        postfix += operators.top();
        operators.pop();
    }

    return postfix;
}

int main() {
    std::string infix;
    std::cout << "Enter infix expression: ";
    std::getline(std::cin, infix);

    std::string postfix = infixToPostfix(infix);
    std::cout << "Postfix expression: " << postfix << std::endl;

    return 0;
}
