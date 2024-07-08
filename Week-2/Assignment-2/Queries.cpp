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
void insert_at_head(Node *&head, int v)
{
    Node *newNode = new Node(v);
    newNode->next = head;
    head = newNode;
}
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
void delete_from_position(Node *head, int pos)
{
    if (head==NULL | pos < 0) return;

    Node *tmp = head;
    for (int i = 1; i <= pos - 1; i++)
    {
        tmp = tmp->next;
        if (tmp == NULL) return;
    }
    if (tmp->next == NULL) return;
    Node *deleteNode = tmp->next;
    tmp->next = tmp->next->next;
    delete deleteNode;
}
void delete_head(Node *&head)
{
    Node *deleteNode = head;
    head = head->next;
    delete deleteNode;
}
void print_linked_list(Node *head)
{
    Node *tmp = head;
    while (tmp != NULL)
    {
        cout << tmp->val << " ";
        tmp = tmp->next;
    }
    cout<< endl;
}
int main(){
    int n;
    cin >> n;
    Node *head = NULL;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        int v;
        cin >> v;
        if (x == 0)
        {
            insert_at_head(head, v);
        }
        else if (x == 1)
        {
            insert_at_tail(head, v);
        }
        else if(head == NULL && x==2 && v==0){
            cout<< ""<< endl;
            continue;
        }
        else if (x == 2)
        {
            if(v== 0){
                delete_head(head);
            }
            else{
                delete_from_position(head, v);
            }
        }

            print_linked_list(head);

    }
    
    return 0;
}