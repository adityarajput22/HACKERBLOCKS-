#include <iostream>
#include <stack>

using namespace std;

class Queue {
private:
    stack<int> enqueueStack;
    stack<int> dequeueStack;

public:
    void enqueue(int value) {
        enqueueStack.push(value);
    }

    void dequeue() {
        if (dequeueStack.empty()) {
            while (!enqueueStack.empty()) {
                dequeueStack.push(enqueueStack.top());
                enqueueStack.pop();
            }
        }
        if (!dequeueStack.empty()) {
            dequeueStack.pop();
        }
    }

    bool isEmpty() {
        return enqueueStack.empty() && dequeueStack.empty();
    }

    int front() {
        if (dequeueStack.empty()) {
            while (!enqueueStack.empty()) {
                dequeueStack.push(enqueueStack.top());
                enqueueStack.pop();
            }
        }
        return dequeueStack.top();
    }
};

int main() {
    int n;
    cin >> n;

    Queue q;

    for (int i = 0; i < n; i++) {
        q.enqueue(i);
    }

    while (!q.isEmpty()) {
        cout << q.front() << " ";
        q.dequeue();
    }

    cout << endl;

    return 0;
}