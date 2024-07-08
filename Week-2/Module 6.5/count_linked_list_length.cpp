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

void insert_at_tail(Node *&head, int value)
{

    Node *newNode = new Node(value);
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
};

void print_Linked_list(Node *head)
{
    Node *tmp = head;

    while (tmp != NULL)
    {
        cout << tmp->value << " ";
        tmp = tmp->next;
    }
    cout << endl;
};

int count_length(Node *head)
{
    Node *tmp = head;
    int count = 0;
    while (tmp != NULL)
    {
        count++;
        tmp = tmp->next;
    }
    return count;
}

int main()
{
    Node *head = NULL;
    int value;
    // cout << "Enter Linked List : ";
    while (true)
    {

        cin >> value;
        if (value == -1)
        {
            // cout << "-1";
            break;
        }
        insert_at_tail(head, value);
    }
    print_Linked_list(head);
    int length = count_length(head);
    // cout << endl
    //      << "Length of Linked List : " << length << endl
    //      << endl;
    cout << length;
    return 0;
}