#include <bits/stdc++.h>
using namespace std;

class Node
{

public:
    int value;
    Node *next;
    Node *previous;
    Node(int value)
    {
        this->previous = NULL;
        this->value = value;
        this->next = NULL;
    }
};

void insert_at_tail(Node *&head, Node *&tail, int value)
{
    Node *newNode = new Node(value);

    if (head == NULL)
    {
        head = newNode;
        tail = newNode;
        return;
    }

    tail->next = newNode;
    newNode->previous = tail;
    tail = newNode;
}

void reverse_print(Node *head, Node *tail)
{

    Node *i = head;
    Node *j = tail;
    while (i != j && i->previous != j)
    {
        swap(i->value, j->value);
        i = i->next;
        j = j->previous;
    }
}

void print(Node *head)
{
    if (head == NULL)
        return;
    cout << head->value << " ";
    print(head->next);
}
int main()
{
    Node *head = NULL;
    Node *tail = NULL;
    int value;
    while (cin >> value && value != -1)
    {
        insert_at_tail(head, tail, value);
    }

    print(head);
    cout << endl;
    reverse_print(head, tail);
    print(head);
    return 0;
}