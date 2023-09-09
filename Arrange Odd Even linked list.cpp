#include <iostream>

using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int data) : data(data), next(nullptr) {}
};

void groupOddEven(Node*& head) {
    if (!head || !head->next || !head->next->next) {
        return; // No need to rearrange if there are 0, 1 or 2 nodes
    }

    Node* oddHead = head;
    Node* evenHead = head->next;

    Node* oddCurrent = oddHead;
    Node* evenCurrent = evenHead;

    while (evenCurrent && evenCurrent->next) {
        oddCurrent->next = evenCurrent->next;
        oddCurrent = oddCurrent->next;

        evenCurrent->next = oddCurrent->next;
        evenCurrent = evenCurrent->next;
    }

    oddCurrent->next = evenHead;
    head = oddHead;
}

void printList(Node* head) {
    while (head) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    int n;
    cin >> n;

    Node* head = nullptr;
    Node* tail = nullptr;

    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;

        Node* newNode = new Node(num);
        if (!head) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    cout << "Original List: ";
    printList(head);

    groupOddEven(head);

    cout << "Modified List: ";
    printList(head);

    return 0;
}