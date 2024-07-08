#include<bits/stdc++.h>
using namespace std;
class Node
{
    public:
        int val;
        Node* next;
    Node(int val)
    {
        this->val=val;
        this->next=NULL;
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
int main(){
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        Node *head = NULL;
        Node *tail = NULL;
        int val;
        while (true)
        {
            cin >> val;
            if (val == -1)
                break;
            insert_tail(head, tail, val);
        }

        
        int v, index=-1, ind=0;
        cin >> v;
        for (Node *i = head; i != NULL; i = i->next, ind++)
        {
            if (i->val == v)
            {
                index = ind;
                break;
            }
        }
        cout<< index<< endl;
    }
    
    return 0;
}