#include <iostream>
using namespace std;

void print_lexicographical_order(int current, int N) {
    if (current > N) {
        return;
    }
    
    cout << current << " ";
    
    if (current == 0) {
        for (int i = 1; i <= 9; i++) {
            print_lexicographical_order(i, N);
        }
    } else {
        for (int i = 0; i <= 9; i++) {
            print_lexicographical_order(current * 10 + i, N);
        }
    }
}

int main() {
    int N;
    cin >> N;
    
    print_lexicographical_order(0, N);
    
    return 0;
}