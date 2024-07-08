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

void insert_at_tail(Node *&head, int val)
{
    Node *newNode = new Node(val);

    if (head == NULL)
    {
        head = newNode;
        return;
    }
    Node *tmp = head;
    while (tmp->next != NULL)
    {
        tmp = tmp->next;
    }
    tmp->next = newNode;
    // cout << endl
    //      << endl
    //      << "Node list insert Successfully" << endl
    //      << endl;
}

void print_linked_list(Node *head)
{

    Node *tmp = head;
    cout << endl
         << endl
         << "Linked Node List : ";
    while (tmp != NULL)
    {
        cout << tmp->value << " ";
        tmp = tmp->next;
    }

    cout << endl;
}

int main()
{
    Node *head = NULL;
    cout << "Input Linked List : ";
    int val;
    while (true)
    {

        cin >> val;

        if (val == -1)
        {
            break;
        }
        insert_at_tail(head, val);
    }

    print_linked_list(head);

    return 0;
}