#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Function to generate all possible strings from a given number
void generateStrings(const string& digits, int index, string current, vector<string>& result) {
    if (index == digits.length()) {
        result.push_back(current);
        return;
    }

    // Consider single-digit mapping
    int singleDigit = digits[index] - '0';
    if (singleDigit >= 1 && singleDigit <= 9) {
        generateStrings(digits, index + 1, current + char('A' + singleDigit - 1), result);
    }

    // Consider double-digit mapping
    if (index < digits.length() - 1) {
        int doubleDigits = (digits[index] - '0') * 10 + (digits[index + 1] - '0');
        if (doubleDigits >= 10 && doubleDigits <= 26) {
            generateStrings(digits, index + 2, current + char('A' + doubleDigits - 1), result);
        }
    }
}

int main() {
    string digits;
    cin >> digits;

    vector<string> result;
    generateStrings(digits, 0, "", result);

    for (const string& s : result) {
        cout << s << endl;
    }

    return 0;
}