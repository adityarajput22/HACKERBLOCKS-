#include <iostream>
#include <vector>
#include <string>

using namespace std;

void generate_strings(const string& s, int idx, string current_str, vector<string>& result) {
    if (idx == s.length()) {
        result.push_back(current_str);
        return;
    }
    
    if (isalpha(s[idx])) {
        generate_strings(s, idx + 1, current_str + char(tolower(s[idx])), result);
        generate_strings(s, idx + 1, current_str + char(toupper(s[idx])), result);
    } else {
        generate_strings(s, idx + 1, current_str + s[idx], result);
    }
}

int main() {
    int t;
    cin >> t;
    
    for (int i = 0; i < t; ++i) {
        string s;
        cin >> s;
        
        vector<string> result;
        generate_strings(s, 0, "", result);
        
        for (const string& str : result) {
            cout << str << " ";
        }
        
        cout << endl;
    }
    
    return 0;
}