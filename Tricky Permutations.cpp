#include <iostream>
#include <algorithm>
using namespace std;

void permuteUnique(string str, int l, int r) {
    if (l == r) {
        cout << str << endl;
        return;
    }

    for (int i = l; i <= r; i++) {
        if (i != l && str[i] == str[l]) {
            continue; // Skip duplicates
        }

        swap(str[l], str[i]);
        permuteUnique(str, l + 1, r);
    }
}

int main() {
    string str;
    cin >> str;

    sort(str.begin(), str.end()); 
    permuteUnique(str, 0, str.length() - 1);

    return 0;
}