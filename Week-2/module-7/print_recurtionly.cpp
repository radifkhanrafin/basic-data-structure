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

void print_reverse_soja(Node *n)
{

    if (n == NULL)
    {
        return;
    }

    cout << n->value << " ";
    print_reverse_soja(n->next);
}
void print_reverse_ulta(Node *n)
{

    if (n == NULL)
    {
        return;
    }

    print_reverse_ulta(n->next);
    cout << n->value << " ";
}

int main()
{
    Node *head = new Node(10);
    Node *a = new Node(20);
    Node *b = new Node(30);
    Node *c = new Node(40);
    Node *d = new Node(50);
    head->next = a;
    a->next = b;
    b->next = c;
    c->next = d;
    print_reverse_soja(head);
    cout << endl
         << endl;
    print_reverse_ulta(head);
    return 0;
}