#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int data) : data(data), next(nullptr) {}
};

// Custom comparator to use with the priority queue
struct CompareNodes {
    bool operator()(const Node* a, const Node* b) const {
        return a->data > b->data; // Min-heap behavior
    }
};

Node* mergeKSortedLists(vector<Node*>& lists, int k) {
    // Initialize a min-heap (priority queue)
    priority_queue<Node*, vector<Node*>, CompareNodes> minHeap;

    // Push the heads of all K lists into the min-heap
    for (int i = 0; i < k; i++) {
        if (lists[i]) {
            minHeap.push(lists[i]);
            lists[i] = lists[i]->next; // Move to the next node
        }
    }

    Node* dummy = new Node(-1); // Dummy node to build the merged list
    Node* current = dummy;

    // Merge the lists using the min-heap
    while (!minHeap.empty()) {
        Node* smallest = minHeap.top();
        minHeap.pop();
        
        current->next = smallest;
        current = current->next;

        if (smallest->next) {
            minHeap.push(smallest->next);
        }
    }

    return dummy->next; // Return the merged sorted list
}

int main() {
    int k, n;
    cin >> k >> n;

    vector<Node*> lists(k);

    // Read the input and create linked lists
    for (int i = 0; i < k; i++) {
        Node* head = nullptr;
        Node* tail = nullptr;

        for (int j = 0; j < n; j++) {
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

        lists[i] = head;
    }

    // Merge the K sorted lists
    Node* mergedList = mergeKSortedLists(lists, k);

    // Print the merged list
    while (mergedList) {
        cout << mergedList->data << " ";
        mergedList = mergedList->next;
    }

    return 0;
}