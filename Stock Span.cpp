#include <iostream>
#include <stack>
#include <vector>
using namespace std;

vector<int> calculateStockSpan(vector<int>& prices) {
    int n = prices.size();
    vector<int> spans(n, 0);
    stack<int> indices;

    for (int i = 0; i < n; ++i) {
        while (!indices.empty() && prices[i] >= prices[indices.top()]) {
            indices.pop();
        }

        spans[i] = (indices.empty() ? i + 1 : i - indices.top());
        indices.push(i);
    }

    return spans;
}

int main() {
    int N;
    cin >> N;

    vector<int> prices(N);
    for (int i = 0; i < N; ++i) {
        cin >> prices[i];
    }

    vector<int> spans = calculateStockSpan(prices);

    for (int span : spans) {
        cout << span << " ";
    }
    cout << "END" << endl;

    return 0;
}