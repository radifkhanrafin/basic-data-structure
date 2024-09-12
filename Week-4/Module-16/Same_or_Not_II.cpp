#include <iostream>
using namespace std;

class Node {
public:
    int value;
    Node* next;
    Node* previous;
    Node(int value) {
        this->previous = NULL;
        this->value = value;
        this->next = NULL;
    }
};

class myStack {
public:
    Node* head = NULL;
    Node* tail = NULL;
    int cnt = 0;

    void push(int val) {
        cnt++;
        Node* newNode = new Node(val);
        if (head == NULL) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            newNode->previous = tail;
            tail = newNode;
        }
    }

    void pop() {
        if (cnt == 0) return; // Handle empty stack
        Node* deleteNode = tail;
        tail = tail->previous;
        if (tail == NULL) {
            head = NULL; // Stack is now empty
        } else {
            tail->next = NULL; // Remove reference to the deleted node
        }
        delete deleteNode;
        cnt--;
    }

    int top() {
        return tail->value;
    }

    int size() {
        return cnt;
    }

    bool empty() {
        return cnt == 0;
    }
};

class myQueue {
public:
    Node* head = NULL;
    Node* tail = NULL;
    int cnt = 0;

    void push(int val) {
        cnt++;
        Node* newNode = new Node(val);
        if (head == NULL) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode; 
            newNode->previous = tail;
            tail = newNode; 
        }
    }

    void pop() {
        if (cnt == 0) return; 
        Node* deleteNode = head; 
        head = head->next; 
        if (head == NULL) {
            tail = NULL; 
        } else {
            head->previous = NULL; 
        }
        delete deleteNode;
        cnt--;
    }

    int front() {
        return head->value;
    }

    int size() {
        return cnt;
    }

    bool empty() {
        return cnt == 0;
    }
};

int main() {
    myStack list_1;
    myQueue list_2;

    int m, n, val;
    bool flag = true;

    cin >> m >> n;
    for (int i = 0; i < m; i++) {
        cin >> val;
        list_1.push(val);
    }

    for (int i = 0; i < n; i++) {
        cin >> val;
        list_2.push(val);
    }

    if (list_1.size() != list_2.size()) {
        flag = false;
    } else {
        while (!list_1.empty() && !list_2.empty()) {
            if (list_1.top() != list_2.front()) {
                flag = false;
                break;
            }
            list_1.pop();
            list_2.pop();
        }
    }

    cout << (flag ? "YES" : "NO") << endl;

    return 0;
}
