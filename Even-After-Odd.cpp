#include <iostream>

using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int data) : data(data), next(nullptr) {}
};

class LinkedList {
public:
    Node* head;
    
    LinkedList() : head(nullptr) {}
    
    void insert(int data) {
        Node* newNode = new Node(data);
        if (!head) {
            head = newNode;
        } else {
            Node* current = head;
            while (current->next) {
                current = current->next;
            }
            current->next = newNode;
        }
    }
    
    void arrangeOddEven() {
        if (!head || !head->next) {
            return; // No need to arrange if there are 0 or 1 elements
        }
        
        Node* oddHead = nullptr;
        Node* oddTail = nullptr;
        Node* evenHead = nullptr;
        Node* evenTail = nullptr;
        
        Node* current = head;
        
        while (current) {
            if (current->data % 2 == 0) {
                // Even number
                if (!evenHead) {
                    evenHead = current;
                    evenTail = current;
                } else {
                    evenTail->next = current;
                    evenTail = current;
                }
            } else {
                // Odd number
                if (!oddHead) {
                    oddHead = current;
                    oddTail = current;
                } else {
                    oddTail->next = current;
                    oddTail = current;
                }
            }
            current = current->next;
        }
        
        // Combine odd and even lists
        if (oddHead) {
            oddTail->next = evenHead;
            head = oddHead;
            if (evenTail) {
                evenTail->next = nullptr;
            }
        } else {
            head = evenHead;
        }
    }
    
    void display() {
        Node* current = head;
        while (current) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }
};

int main() {
    int n;
    cin >> n;
    
    LinkedList linkedList;
    
    for (int i = 0; i < n; i++) {
        int data;
        cin >> data;
        linkedList.insert(data);
    }
    
    linkedList.arrangeOddEven();
    linkedList.display();
    
    return 0;
}