#include <iostream>
#include <stack>
#include <string>

using namespace std;

bool isMatchingParenthesis(string str) {
    stack<char> s;
    
    for (int i = 0; i < str.length(); i++) {
        char ch = str[i];
        
        // Push opening brackets
        if (ch == '(' || ch == '[' || ch == '{') {
            s.push(ch);
        }
        // Check closing brackets
        else if (ch == ')' || ch == ']' || ch == '}') {
            // No matching opening bracket
            if (s.empty()) {
                return false;
            }
            
            char top = s.top();
            s.pop();
            
            // Check if brackets match
            if ((ch == ')' && top != '(') ||
                (ch == ']' && top != '[') ||
                (ch == '}' && top != '{')) {
                return false;
            }
        }
    }
    
    // All brackets should be matched (stack should be empty)
    return s.empty();
}

int main() {
    cout << "=== Parenthesis Matching Demo ===" << endl << endl;
    
    string test1 = "()";
    string test2 = "()[]{}";
    string test3 = "(]";
    string test4 = "([)]";
    string test5 = "{[()]}";
    string test6 = "((())";
    string test7 = "())";
    string test8 = "";
    string test9 = "{[}]";
    string test10 = "a(b[c{d}e]f)g";
    
    cout << "Test 1: \"" << test1 << "\" -> " 
         << (isMatchingParenthesis(test1) ? "Valid" : "Invalid") << endl;
    
    cout << "Test 2: \"" << test2 << "\" -> " 
         << (isMatchingParenthesis(test2) ? "Valid" : "Invalid") << endl;
    
    cout << "Test 3: \"" << test3 << "\" -> " 
         << (isMatchingParenthesis(test3) ? "Valid" : "Invalid") << endl;
    
    cout << "Test 4: \"" << test4 << "\" -> " 
         << (isMatchingParenthesis(test4) ? "Valid" : "Invalid") << endl;
    
    cout << "Test 5: \"" << test5 << "\" -> " 
         << (isMatchingParenthesis(test5) ? "Valid" : "Invalid") << endl;
    
    cout << "Test 6: \"" << test6 << "\" -> " 
         << (isMatchingParenthesis(test6) ? "Valid" : "Invalid") << endl;
    
    cout << "Test 7: \"" << test7 << "\" -> " 
         << (isMatchingParenthesis(test7) ? "Valid" : "Invalid") << endl;
    
    cout << "Test 8: \"" << test8 << "\" -> " 
         << (isMatchingParenthesis(test8) ? "Valid" : "Invalid") << endl;
    
    cout << "Test 9: \"" << test9 << "\" -> " 
         << (isMatchingParenthesis(test9) ? "Valid" : "Invalid") << endl;
    
    cout << "Test 10: \"" << test10 << "\" -> " 
         << (isMatchingParenthesis(test10) ? "Valid" : "Invalid") << endl;
    
    cout << "\nDone!" << endl;
    
    return 0;
}
