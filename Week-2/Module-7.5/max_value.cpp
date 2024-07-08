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
        cout << endl
             << endl
             << "New node insert at head" << endl
             << endl;
        return;
    }

    // Node *tmp = head;
    // while (tmp->next != NULL)
    // {
    //     tmp = tmp->next;
    // }

    tail->next = newNode;
    tail = newNode;
    cout << endl
         << endl
         << "New node insert at tail" << endl
         << endl;
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
    cout << endl
         << endl;
}
void insert_at_position(Node *head, int p, int v)
{
    Node *newNode = new Node(v);
    Node *tmp = head;
    for (int i = 1; i <= p - 1; i++)
    {
        tmp = tmp->next;
        if (tmp == NULL)
        {
            cout << endl
                 << endl
                 << "Invalid Index Input" << endl
                 << endl;
            return;
        }
    }
    newNode->next = tmp->next;
    tmp->next = newNode;

    cout << endl
         << endl
         << "New node insert at " << p << " position" << endl
         << endl;
}

void insert_at_head(Node *&head, int v)
{
    Node *newNode = new Node(v);
    newNode->next = head;
    head = newNode;
    cout << endl
         << endl
         << "New node insert at head" << endl
         << endl;
}
void delete_node(Node *head, int pos)
{

    Node *tmp = head;
    for (int i = 1; i <= pos - 1; i++)
    {
        tmp = tmp->next;
        if (tmp == NULL)
        {
            cout << endl
                 << endl
                 << "Invalid Index Input" << endl
                 << endl;
            return;
        }
    }
    if (tmp->next == NULL)
    {
        cout << endl
             << endl
             << "Invalid Index Input" << endl
             << endl;
        return;
    }
    Node *deleteNode = tmp->next;
    tmp->next = tmp->next->next;
    delete deleteNode;
    cout << endl
         << endl
         << "Node delete from " << pos << " position" << endl
         << endl;
}
void delete_head(Node *&head)
{
    if (head == NULL)
    {
        cout << endl
             << endl
             << "Head in not available" << endl
             << endl;
        return;
    }
    Node *deleteHead = head;
    head = head->next;
    delete deleteHead;
    cout << endl
         << endl
         << "Node delete from head" << endl
         << endl;
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

void find_minimum_value(Node *head)
{
    if (head == NULL)
    {
        cout << "This is a empty list";
        return;
    }

    int mini = INT_MAX;
    Node *tmp = head;

    while (tmp != NULL)
    {
        if (tmp->value < mini)
        {
            mini = tmp->value;
        }
        tmp = tmp->next;
    }
    cout << endl
         << endl
         << "minimum Value of this linked list is " << mini << endl
         << endl;
}

int main()
{
    Node *head = NULL;
    Node *tail = NULL;

    while (true)
    {
        cout << "Option 1: Insert at Tail" << endl;
        cout << "Option 2: Print Linked List" << endl;
        cout << "Option 3: Insert at Position" << endl;
        cout << "Option 4: Insert at head" << endl;
        cout << "Option 5: Delete from position" << endl;
        cout << "Option 6: Delete Head" << endl;
        cout << "Option 7: Find Maximum Value" << endl;
        cout << "Option 8: Find Minimum Value" << endl;
        cout << "Option 9: Terminate" << endl;

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
            insert_at_tail(head, tail, v);
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
            if (pos == 0)
            {
                insert_at_head(head, val);
            }
            else
            {
                insert_at_position(head, pos, val);
            }
        }
        else if (op == 4)
        {
            int val;
            cout << endl
                 << endl
                 << "Enter Value : ";
            cin >> val;

            insert_at_head(head, val);
        }
        else if (op == 5)
        {
            int pos;
            cout << endl
                 << "Enter position which do you want" << endl;
            cin >> pos;
            if (pos == 0)
            {
                delete_head(head);
            }
            else
                delete_node(head, pos);
        }
        else if (op == 6)
        {
            delete_head(head);
        }
        else if (op == 7)
        {
            find_maximum_value(head);
        }

        else if (op == 8)
        {
            find_minimum_value(head);
        }
        else if (op == 9)
        {
            break;
        }
    }

    return 0;
}