

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

void insert_tail(Node *&head, Node *&tail, int val)
{

    Node *newNode = new Node(val);
    if (head == NULL)
    {
        head = newNode;
        tail = newNode;
        return;
    }
    tail->next = newNode;
    tail = newNode;
}

void print_data(Node *head)
{

    if (head == NULL)
    {
        return;
    }
    cout << head->value << " ";
    print_data(head->next);
    cout << endl;
}

int main()
{

    Node *head = NULL;
    Node *tail = NULL;
    Node *head2 = NULL;
    Node *tail2 = NULL;
    int val, flag = 1;

    while (true)
    {
        cin >> val;
        if (val == -1)
            break;

        insert_tail(head, tail, val);
    }
    // print_data(head);

    while (true)
    {
        cin >> val;
        if (val == -1)
            break;

        insert_tail(head2, tail2, val);
    }

    Node *a = head;
    Node *b = head2;
    while (a != NULL && b != NULL)
    {
        if (a->value == b->value)
        {
            flag = 1;
        }
        else
            flag = 0;

        a = a->next;
        b = b->next;
    }
    if (a != NULL || b != NULL)
    {
        flag = 0;
    }
    cout << (flag == 1 ? "YES" : "NO");
    return 0;
}