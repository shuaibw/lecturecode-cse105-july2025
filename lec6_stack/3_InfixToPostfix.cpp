#include <iostream>
#include <string>
#include <stack>
#include <cctype>

using namespace std;

// Get precedence of operators
int precedence(char op) {
    if (op == '+' || op == '-') {
        return 1;
    }
    if (op == '*' || op == '/') {
        return 2;
    }
    return 0;
}

// Check if character is an operator
bool isOperator(char ch) {
    return ch == '+' || ch == '-' || ch == '*' || ch == '/';
}

string infixToPostfix(string infix) {
    stack<char> s;
    string postfix = "";
    
    for (int i = 0; i < infix.length(); i++) {
        char ch = infix[i];
        
        // Skip spaces
        if (ch == ' ') {
            continue;
        }
        
        // If operand, add to output
        if (isalnum(ch)) {
            postfix += ch;
        }
        // If '(', push to stack
        else if (ch == '(') {
            s.push(ch);
        }
        // If ')', pop until '('
        else if (ch == ')') {
            while (!s.empty() && s.top() != '(') {
                postfix += s.top();
                s.pop();
            }
            s.pop();  // Remove '('
        }
        // If operator
        else if (isOperator(ch)) {
            // Pop operators with higher or equal precedence
            while (!s.empty() && s.top() != '(' && 
                   precedence(s.top()) >= precedence(ch)) {
                postfix += s.top();
                s.pop();
            }
            s.push(ch);
        }
    }
    
    // Pop remaining operators
    while (!s.empty()) {
        postfix += s.top();
        s.pop();
    }
    
    return postfix;
}

int main() {
    cout << "=== Infix to Postfix Conversion ===" << endl << endl;
    
    string expr1 = "2+3";
    string expr2 = "2+3*4";
    string expr3 = "(2+3)*4";
    string expr4 = "5+3*8-2";
    string expr5 = "(5+3)*(8-2)";
    string expr6 = "6/2-3+4*5";
    string expr7 = "((2+3)*4-5)/6";
    string expr8 = "2+3-4*5/6";
    
    cout << "Infix:    " << expr1 << endl;
    cout << "Postfix:  " << infixToPostfix(expr1) << endl << endl;
    
    cout << "Infix:    " << expr2 << endl;
    cout << "Postfix:  " << infixToPostfix(expr2) << endl << endl;
    
    cout << "Infix:    " << expr3 << endl;
    cout << "Postfix:  " << infixToPostfix(expr3) << endl << endl;
    
    cout << "Infix:    " << expr4 << endl;
    cout << "Postfix:  " << infixToPostfix(expr4) << endl << endl;
    
    cout << "Infix:    " << expr5 << endl;
    cout << "Postfix:  " << infixToPostfix(expr5) << endl << endl;
    
    cout << "Infix:    " << expr6 << endl;
    cout << "Postfix:  " << infixToPostfix(expr6) << endl << endl;
    
    cout << "Infix:    " << expr7 << endl;
    cout << "Postfix:  " << infixToPostfix(expr7) << endl << endl;
    
    cout << "Infix:    " << expr8 << endl;
    cout << "Postfix:  " << infixToPostfix(expr8) << endl << endl;
    
    cout << "Done!" << endl;
    
    return 0;
}
