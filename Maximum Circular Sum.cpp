#include <iostream>
#include <climits>
using namespace std;

int kadaneLinear(int arr[], int n) {
    int maxSum = arr[0];
    int currentSum = arr[0];
    for (int i = 1; i < n; i++) {
        currentSum = max(arr[i], currentSum + arr[i]);
        maxSum = max(maxSum, currentSum);
    }
    return maxSum;
}

int kadaneCircular(int arr[], int n) {
    int linearMax = kadaneLinear(arr, n);
    int circularMax = 0;
    for (int i = 0; i < n; i++) {
        circularMax += arr[i];
        arr[i] = -arr[i];
    }
    circularMax += kadaneLinear(arr, n);
    return max(linearMax, circularMax);
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n; 
        int arr[n];

        for (int i = 0; i < n; i++) {
            cin >> arr[i]; 
        }

        int maxSum = kadaneCircular(arr, n);
        cout << maxSum << endl;
    }

    return 0;
}