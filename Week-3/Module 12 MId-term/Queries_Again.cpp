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

int node_size(Node *head)
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

void insert_at_head(Node *&head, Node *&tail, int val)
{
    Node *newNode = new Node(val);
    if (head == NULL)
    {
        head = newNode;
        tail = newNode;
        return;
    }
    newNode->next = head;
    head->previous = newNode;
    head = newNode;
}

void insert_at_position(Node *&head, int pos, int val)
{
    Node *newNode = new Node(val);
    Node *tmp = head;
    for (int i = 1; i <= pos - 1; i++)
    {
        tmp = tmp->next;
    }
    newNode->next = tmp->next;
    tmp->next->previous = newNode;
    newNode->previous = tmp;
    tmp->next = newNode;
}

void insert_at_tail(Node *&head, Node *&tail, int val)
{
    Node *newNode = new Node(val);
    if (head == NULL)
    {
        head = newNode;
        tail = newNode;
        return;
    }
    newNode->previous = tail;
    tail->next = newNode;
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

void print_reverse(Node *tail)
{
    Node *tmp = tail;
    while (tmp != NULL)
    {
        cout << tmp->value << " ";
        tmp = tmp->previous;
    }
}

int main()
{
    Node *head = NULL;
    Node *tail = NULL;

    int n;
    cin >> n;
    int flag = 1;
    while (n > 0)
    {
        flag = 1;
        int index, value;
        cin >> index >> value;

        if (index > node_size(head))
        {
            cout << "Invalid" << endl;
            flag = 0;
        }
        else if (index == 0)
        {
            insert_at_head(head, tail, value);
        }
        else if (index == node_size(head))
        {
            insert_at_tail(head, tail, value);
        }
        else if (index > 0 && index < node_size(head))
        {
            insert_at_position(head, index, value);
        }

        //  if (flag==1)
        //  {
        //     /* code */
        //  }

        if (head != NULL && flag == 1)
        {
            cout << "L -> ";
            print_list(head);
            cout << endl;

            cout << "R -> ";
            print_reverse(tail);
            cout << endl;
        }
        n--;
    }

    return 0;
}
