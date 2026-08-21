#include<iostream>
#include<stack>
#include<sstream>
using namespace std;
int solve ( string expression ) {

    int length = expression.length();
    stack<int>st;
    string token;
    stringstream ss(expression);

    while ( ss >> token ) {

        if ( isdigit( token[0] ) ) {
            st.push( stoi(token) );
        }
        else{

            int top1 = st.top();
            st.pop();
            int top2 = st.top();
            st.pop();

            if ( token == "+" ) st.push ( top2 + top1 );
            else if ( token == "-" ) st.push ( top2 - top1 );
            else if ( token == "*" ) st.push ( top2 * top1 );
            else {
                st.push ( top2 / top1 );
            }
        }
    }
    return st.top();
}
int main() {

    string expression;
    cout << "Enter postfix expression: ";
    getline(cin, expression);

    int result = solve(expression);
    cout << "Result of expression after evaluating: " << result <<"\n";
    return 0;
}