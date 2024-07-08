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
        return;
    }
    Node *tmp = head;
    while (tmp->next != NULL)
    {
        tmp = tmp->next;
    }
    tmp->next = newNode;
}

void print_linked_list(Node *head)
{
    Node *tmp = head;
    while (tmp != NULL)
    {
        cout << tmp->value << " ";
        tmp = tmp->next;
    }
    cout << endl;
}

bool find_duplicate(Node *head)
{
    bool duplicate[101] = {false};
    Node *tmp = head;
    while (tmp != NULL)
    {
        if (duplicate[tmp->value])
        {
            return true;
        }
        duplicate[tmp->value] = true;
        tmp = tmp->next;
    }
    return false;
}

/*
bool has_duplicates(Node *head) {
    bool seen[101] = {false}; // Array to track values from 0 to 100

    Node *tmp = head;
    while (tmp != NULL) {
        if (seen[tmp->value]) {
            return true; // Duplicate found
        }
        seen[tmp->value] = true; // Mark the value as seen
        tmp = tmp->next;
    }
    return false; // No duplicates found
}
*/

int main()
{

    Node *head = NULL;

    cout << "Enter Linked List : ";
    int value;
    while (true)
    {
        cin >> value;
        if (value == -1)
        {
            break;
        }
        insert_at_tail(head, value);
    }

    print_linked_list(head);
    bool duplicate = find_duplicate(head);
    // cout << ;
    if (duplicate == 1)
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }

    return 0;
}