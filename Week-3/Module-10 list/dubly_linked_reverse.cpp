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

void print_list(Node *head)
{
    if (head == NULL)
    {
        return;
    }

    cout << head->value << " ";
    print_list(head->next);
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
    // swap(i->value, j->value);
}

int main()
{
    Node *head = new Node(5);

    Node *a = new Node(10);
    Node *b = new Node(20);
    Node *c = new Node(30);
    Node *d = new Node(40);
    Node *e = new Node(50);
    Node *tail = e;

    head->next = a;
    a->previous = head;
    a->next = b;
    b->previous = a;
    b->next = c;
    c->previous = b;
    c->next = d;
    d->previous = c;
    d->next = e;
    e->previous = d;

    print_list(head);
    cout << endl;

    reverse_print(head, tail);

    print_list(head);
    cout << endl;

    return 0;
}
