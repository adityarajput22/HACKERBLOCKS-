#include <iostream>
#include <algorithm>
using namespace std;
int main() {
	int n;
	cin >> n;
	int a[n];
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	int t;
	cin >> t;

	//OPERATIONS
	int sum = 0;

	// SORT THIS BEFORE SEARCHING FOR TARGET SUM, SO YOU DONT NEED TO SORT AT END :)
	// I USE IN BUILD FUNC BUT YOU CAN BUILD YOUR OWN
	sort(a, a + n);

	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			for (int k = j + 1; k < n; k++) {
				sum = a[i] + a[j] + a[k];
				if ( sum == t ) {
					//PrintMe(i, j, k, a);
					cout << a[i] << ", " << a[j] << " " << "and " << a[k] << endl;
				}
			}
		}
	}

}