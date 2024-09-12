#include <bits/stdc++.h>
using namespace std;
class Node
{

public:
    int value;
    Node *next;
    Node(int value)
    {
        this->value = value;
        this->next = NULL;
    }
};

class myQueue
{
public:
    Node *head = NULL;
    Node *tail = NULL;
    int sz = 0;
    void push(int val)
    {
        Node *newNode = new Node(val);
        sz++;
        if (head == NULL)
        {
            head = newNode;
            tail = newNode;
            return;
        }
        tail->next = newNode;
        tail = newNode;
    };

    void pop()
    {
        Node *deleteNode = head;
        head = head->next;
        if (head == NULL)
        {
            tail = NULL;
        }
        delete deleteNode;
        sz--;
    }

    int font()
    {
        if (head == NULL)
        {
            return 0;
        }

        return head->value;
    }
    int size()
    {
        return sz;
    }
};
int main()
{
    myQueue q;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        q.push(x);
    }

    while (q.size() != 0)
    {
        cout << q.font() << endl;
        q.pop();
    }

    return 0;
}