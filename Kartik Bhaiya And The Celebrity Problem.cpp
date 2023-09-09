#include <iostream>
#include <vector>

using namespace std;

int findCelebrity(const vector<vector<int>>& matrix) {
    int n = matrix.size();
    int left = 0;
    int right = n - 1;

    while (left < right) {
        if (matrix[left][right]) {
            left++;
        } else {
            right--;
        }
    }

    // At this point, left and right both point to the same potential celebrity
    for (int i = 0; i < n; i++) {
        if (i != left && (matrix[left][i] || !matrix[i][left])) {
            return -1; // No celebrity
        }
    }

    return left; // The left pointer points to the celebrity
}

int main() {
    int n;
    cin >> n;

    vector<vector<int>> matrix(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> matrix[i][j];
        }
    }

    int celebrity = findCelebrity(matrix);

    if (celebrity != -1) {
        cout << celebrity << endl;
    } else {
        cout << "No Celebrity" << endl;
    }

    return 0;
}