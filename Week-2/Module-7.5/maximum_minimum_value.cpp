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

void insert_at_tail(Node *&head, Node *&tail, int val)
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
};

void print_list(Node *n)
{
    if (n == NULL)
    {
        return;
    }

    print_list(n->next);
    cout << n->value << " ";
};
void find_maximum_value(Node *head)
{
    if (head == NULL)
    {
        cout << "This is a empty list";
        return;
    }

    int maxi = INT_MIN;
    Node *tmp = head;

    while (tmp != NULL)
    {
        if (tmp->value > maxi)
        {
            maxi = tmp->value;
        }
        tmp = tmp->next;
    }
    cout << endl
         << endl
         << "Maximum Value of this linked list is " << maxi << endl
         << endl;
}
int main()
{
    Node *head = NULL;
    Node *tail = NULL;

    int val;
    while (true)
    {
        cin >> val;
        if (val == -1)
        {
            break;
        }
        insert_at_tail(head, tail, val);
    }
    print_list(head);
    find_maximum_value(head);
    return 0;
}