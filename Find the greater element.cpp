#include <iostream>
#include <vector>
#include <stack>

using namespace std;

vector<int> nextGreaterCircularArray(const vector<int>& arr) {
    int n = arr.size();
    vector<int> result(n, -1);
    stack<int> st; // Stack to store indices

    for (int i = 0; i < 2 * n; i++) {
        int num = arr[i % n];
        while (!st.empty() && arr[st.top()] < num) {
            result[st.top()] = num;
            st.pop();
        }
        if (i < n) {
            st.push(i);
        }
    }

    return result;
}

int main() {
    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    vector<int> result = nextGreaterCircularArray(arr);
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}