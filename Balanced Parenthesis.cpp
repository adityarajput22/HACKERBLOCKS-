#include <iostream>
#include <stack>

using namespace std;

bool isBalanced(const string& s) {
    stack<char> st;

    for (char c : s) {
        if (c == '(' || c == '{' || c == '[') {
            st.push(c);
        } else if (c == ')' || c == '}' || c == ']') {
            if (st.empty()) {
                return false; // No matching opening bracket
            }

            char top = st.top();
            st.pop();

            if ((c == ')' && top != '(') || 
                (c == '}' && top != '{') || 
                (c == ']' && top != '[')) {
                return false; // Mismatched brackets
            }
        }
    }

    return st.empty(); // All brackets should be balanced
}

int main() {
    string input;
    cin >> input;

    if (isBalanced(input)) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }

    return 0;
}