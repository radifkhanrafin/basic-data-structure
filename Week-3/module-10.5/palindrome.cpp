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

bool is_palindrome(Node *head, Node *tail)
{
    Node *i = head;
    Node *j = tail;
    while (i != j && i->previous != j)
    {
        if (i->value != j->value)
        {
            return false;
        }
        i = i->next;
        j = j->previous;
    }
    return true;
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
    cout << (is_palindrome(head, tail)?"YES":"NO");
    // print(head);
    return 0;
}