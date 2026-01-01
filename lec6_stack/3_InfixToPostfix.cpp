#include <iostream>
#include <string>
#include <stack>
#include <cctype>

using namespace std;

/*
 * ============================================================================
 * INFIX TO POSTFIX CONVERSION ALGORITHM (Shunting Yard)
 * ============================================================================
 * 
 * RULES:
 * 1. If OPERAND (number/letter):
 *    → Add directly to output
 * 
 * 2. If OPENING PARENTHESIS '(':
 *    → Push to stack
 * 
 * 3. If CLOSING PARENTHESIS ')':
 *    → Pop operators from stack to output until '(' is found
 *    → Remove the '(' from stack (don't add to output)
 * 
 * 4. If OPERATOR (+, -, *, /):
 *    → While stack is not empty AND top is not '(' AND 
 *      top has HIGHER OR EQUAL precedence than current operator:
 *        • Pop operator from stack to output
 *    → Push current operator to stack
 * 
 * 5. At END of expression:
 *    → Pop all remaining operators from stack to output
 * 
 * PRECEDENCE:
 *    * and / have precedence 2 (higher)
 *    + and - have precedence 1 (lower)
 * 
 * ============================================================================
 * EXAMPLE: Convert "(2+3)*4" to postfix
 * ============================================================================
 * 
 * Symbol | Action                    | Stack     | Output
 * -------|---------------------------|-----------|--------
 * (      | Push '(' to stack         | (         | 
 * 2      | Add operand to output     | (         | 2
 * +      | Push '+' to stack         | ( +       | 2
 * 3      | Add operand to output     | ( +       | 23
 * )      | Pop until '('             |           | 23+
 *        | ('+' popped, '(' removed) |           |
 * *      | Push '*' to stack         | *         | 23+
 * 4      | Add operand to output     | *         | 23+4
 * END    | Pop remaining operators   |           | 23+4*
 * 
 * Result: "23+4*"
 * 
 * ============================================================================
 * EXAMPLE: Convert "2+3*4" to postfix
 * ============================================================================
 * 
 * Symbol | Action                    | Stack     | Output
 * -------|---------------------------|-----------|--------
 * 2      | Add operand to output     |           | 2
 * +      | Push '+' to stack         | +         | 2
 * 3      | Add operand to output     | +         | 23
 * *      | '*' has higher precedence | + *       | 23
 *        | than '+', so push '*'     |           |
 * 4      | Add operand to output     | + *       | 234
 * END    | Pop '*' then '+'          |           | 234*+
 * 
 * Result: "234*+"
 * 
 * ============================================================================
 */

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
