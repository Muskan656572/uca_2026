#include<iostream>
#include<stack>
using namespace std; 
bool checkParenthesis ( string expression ) { 
    int length = expression.length(); 
    stack<char> st; 
    for ( int i = 0; i < length; i++ ) { 
        char ch = expression[i]; 
        if ( ch == '(' || ch == '[' || ch == '{' ) { 
            st.push(ch); 
        } 
        else { 
            if ( st.empty() ) return false; 
            else if ( ch == ')' && st.top() == '(' ) st.pop(); 
            else if ( ch== ']' && st.top() == '[' ) st.pop(); 
            else if ( ch == '}' && st.top() == '{' ) st.pop(); 
            else return false; 
        } 
    } 
    if ( st.empty() ) return true; 
    return false; 
} 
int main() { 
    string expression; 
    cout << "Enter a string expression: "; 
    cin >> expression; 
    bool result = checkParenthesis(expression); 
    cout << "checking parenthesis in an expression are balanced or not: " << result <<"\n"; 
    return 0; 
}