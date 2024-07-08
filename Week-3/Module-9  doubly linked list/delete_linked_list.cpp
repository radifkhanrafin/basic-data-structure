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
    if (tail == NULL)
    {
        head = newNode;
        tail = newNode;
        return;
    }
    tail->next = newNode;
    newNode->previous = tail;
    tail = newNode;
}
void print_normally(Node *head)
{
    Node *tmp = head;
    while (tmp != NULL)
    {
        cout << tmp->value << " ";
        tmp = tmp->next;
    }
    cout << endl;
}
void print_reverse(Node *tail)
{
    Node *tmp = tail;
    while (tmp != NULL)
    {
        cout << tmp->value << " ";
        tmp = tmp->previous;
    }
    cout << endl;
}
int size(Node *head)
{
    Node *tmp = head;
    int cnt = 0;
    while (tmp != NULL)
    {
        cnt++;
        tmp = tmp->next;
    }
    return cnt;
}

void delete_list(Node *head, int pos)
{

    Node *tmp = head;
    for (int i = 1; i <= pos - 1; i++)
    {
        tmp = tmp->next;
    }

    Node *deleteNode = tmp->next;
    tmp->next = deleteNode->next;
    deleteNode->next->previous = tmp;
    delete deleteNode;
}

void delete_head(Node *&head)
{
    Node *deleteNode = head;
    head = deleteNode->next;
    head->previous = NULL;
    delete deleteNode;
}
void delete_tail(Node *&tail)
{
    Node *deleteNode = tail;
    tail = deleteNode->previous;
    delete deleteNode;
    tail->next = NULL;
}
int main()
{

    // Node *head = NULL;
    // Node *tail = NULL;
    Node *head = new Node(10);
    Node *a = new Node(20);
    Node *b = new Node(30);
    Node *c = new Node(40);
    Node *tail = c;

    // connection
    head->next = a;
    a->previous = head;
    a->next = b;
    b->previous = a;
    b->next = c;
    c->previous = b;
    // insert_at_tail(head, tail, 560);
    print_normally(head);
    print_reverse(tail);

    int pos;
    cin >> pos;
    if (pos >= size(head))
    {
        cout << "Invalid Position";
    }
    else if (pos == 0)
        delete_head(head);
    else if (pos == size(head)-1)
        delete_tail(tail);
    else
        delete_list(head, pos);

    cout << endl;

    print_normally(head);
    print_reverse(tail);

    return 0;
}