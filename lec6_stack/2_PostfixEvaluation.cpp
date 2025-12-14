#include <iostream>
#include <string>
#include <stack>
#include <cctype>

using namespace std;

int evaluatePostfix(string expr) {
    stack<int> s;
    
    for (int i = 0; i < expr.length(); i++) {
        char ch = expr[i];
        
        // Skip spaces
        if (ch == ' ') {
            continue;
        }
        
        // If digit, push to stack
        if (isdigit(ch)) {
            s.push(ch - '0');  // Convert char to int
        }
        // If operator, pop two operands and apply operation
        else if (ch == '+' || ch == '-' || ch == '*' || ch == '/') {
            int operand2 = s.top();
            s.pop();
            int operand1 = s.top();
            s.pop();
            int result;
            
            if (ch == '+') {
                result = operand1 + operand2;
            } else if (ch == '-') {
                result = operand1 - operand2;
            } else if (ch == '*') {
                result = operand1 * operand2;
            } else if (ch == '/') {
                result = operand1 / operand2;
            }
            
            s.push(result);
        }
    }
    
    // Final result is the only element left in stack
    int result = s.top();
    s.pop();
    return result;
}

int main() {
    cout << "=== Postfix Expression Evaluation ===" << endl << endl;
    
    string expr1 = "23+";           // 2 + 3 = 5
    string expr2 = "23*";           // 2 * 3 = 6
    string expr3 = "234*+";         // 2 + (3 * 4) = 14
    string expr4 = "53+82-*";       // (5 + 3) * (8 - 2) = 48
    string expr5 = "62/3-42*+";     // (6 / 2) - 3 + (4 * 2) = 8
    string expr6 = "23+45+*";       // (2 + 3) * (4 + 5) = 45
    
    cout << "Expression: \"" << expr1 << "\" = " << evaluatePostfix(expr1) << endl;
    cout << "Expression: \"" << expr2 << "\" = " << evaluatePostfix(expr2) << endl;
    cout << "Expression: \"" << expr3 << "\" = " << evaluatePostfix(expr3) << endl;
    cout << "Expression: \"" << expr4 << "\" = " << evaluatePostfix(expr4) << endl;
    cout << "Expression: \"" << expr5 << "\" = " << evaluatePostfix(expr5) << endl;
    cout << "Expression: \"" << expr6 << "\" = " << evaluatePostfix(expr6) << endl;
    
    cout << "\nDone!" << endl;
    
    return 0;
}
