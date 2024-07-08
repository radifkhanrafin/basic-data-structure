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

void insert_at_tail(Node *&head, int v)
{
    Node *newNode = new Node(v);

    if (head == NULL)
    {
        head = newNode;
        cout << endl
             << "Node insert at head" << endl
             << endl;
        return;
    }

    Node *tmp = head;
    while (tmp->next != NULL)
    {
        tmp = tmp->next;
    }

    tmp->next = newNode;

    cout << endl
         << "Node insert at tail" << endl
         << endl;
}

void print_linked_list(Node *head)
{

    cout << "your linked list : ";
    Node *tmp = head;
    while (tmp != NULL)
    {
        cout << tmp->value << " ";
        tmp = tmp->next;
    }
    cout << endl
         << endl;
};

void insert_at_position(Node *head, int pos, int val)
{

    Node *newNode = new Node(val);
    Node *tmp = head;

    for (int i = 1; i <= pos - 1; i++)
    {
        tmp = tmp->next; // aida last node
    }
    newNode->next = tmp->next; // last noder sathe new node linked
    tmp->next = newNode;
    cout << endl
         << "New node insert at " << pos << endl
         << endl;
};

int main()
{

    Node *head = NULL;

    while (true)
    {
        cout << "Option 1: Insert at Tail" << endl;
        cout << "Option 2: Print Linked List" << endl;
        cout << "Option 3: Insert at Position" << endl;
        cout << "Option 4: Terminate" << endl;

        int op;
        cout << endl
             << "Enter Option : ";
        cin >> op;
        if (op == 1)
        {
            cout << endl
                 << "Enter the value : ";
            int v;
            cin >> v;
            insert_at_tail(head, v);
        }
        else if (op == 2)
        {
            print_linked_list(head);
        }
        else if (op == 3)
        {
            int pos, val;
            cout << endl
                 << "Enter the position : ";
            cin >> pos;
            cout << endl
                 << "Enter the Value : ";
            cin >> val;
            insert_at_position(head, pos, val);
        }
        else if (op == 4)
        {
            break;
        }
    }

    return 0;
}