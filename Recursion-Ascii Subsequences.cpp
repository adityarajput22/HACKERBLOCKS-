#include <iostream>
using namespace std;

int count_ascii_subsequences(string str) {
    if (str.empty())
        return 1;

    int count = count_ascii_subsequences(str.substr(1));
    count += count_ascii_subsequences(str.substr(1)) + count_ascii_subsequences(str.substr(1)); 
    return count;
}

void print_ascii_subsequences(string str, string curr = "", int index = 0) {
    if (index == str.length()) {
        cout << curr << " ";
        return;
    }
    
    print_ascii_subsequences(str, curr, index + 1); 
    print_ascii_subsequences(str, curr + str[index], index + 1); 
    print_ascii_subsequences(str, curr + to_string(int(str[index])), index + 1);
}

int main() {
    string str;
    cin >> str;
    
    print_ascii_subsequences(str);
    cout << endl; 
    cout<<count_ascii_subsequences(str) << endl;

    return 0;
}