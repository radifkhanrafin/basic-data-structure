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

void print_list(Node *head)
{

    Node *tmp = head;
    while (tmp != NULL)
    {
        cout << tmp->value << " ";
        tmp = tmp->next;
    }
}

bool check_equal(Node *head1, Node *head2)
{

    while (head1 != NULL && head2 != NULL)
    {
        if (head1->value == head2->value)
        {
            return true;
        }
        else
            return false;
    }
}
int main()
{

    Node *head = NULL;
    Node *tail = NULL;
    Node *head2 = NULL;
    Node *tail2 = NULL;
    int value;
    while (cin >> value && value != -1)
    {
        insert_at_tail(head, tail, value);
    }

    // Input for the second list
    while (cin >> value && value != -1)
    {
        insert_at_tail(head2, tail2, value);
    }
    print_list(head);
    cout << endl;
    print_list(head2);
    cout << endl;
    cout << (check_equal(head, head2) == 1 ? "YES" : "NO");
    return 0;
}