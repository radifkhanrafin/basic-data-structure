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

class mystack
{
public:
    Node *head = NULL;
    Node *tail = NULL;
    int cnt = 0;
    void push(int val)
    {
        cnt++;
        Node *newNode = new Node(val);

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
    void pop()
    {

        Node *deleteNode = tail;
        tail = tail->previous;

        if (tail->previous == NULL)
        {
            head = NULL;
        }
        else
            tail->next = NULL;
        delete deleteNode;
        cnt--;
    }
    int top()
    {
        return tail->value;
    }
    int size()
    {
        return cnt;
    }
    bool empty()
    {
        if (cnt == 0)
            return true;
        else
            return false;
    }
};
int main()
{
    mystack doublyList;

if (doublyList.size()==0)
{
   
}

    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cout << i << endl;
        int x;
        cin >> x;
        doublyList.push(x);
    }

    cout << doublyList.size() << endl;
    // cout << doublyList.top() << endl;
    // doublyList.pop();
    // cout << doublyList.top() << endl;

    cout << "Output from loop : " << endl;
    while (doublyList.empty() == false)
    {
        cout << doublyList.top() << endl;
        doublyList.pop();
    }
    return 0;
}