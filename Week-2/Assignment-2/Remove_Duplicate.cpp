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
void print_linked_list(Node *head)
{
    Node *tmp = head;
    while (tmp != NULL)
    {
        cout << tmp->val << " ";
        tmp = tmp->next;
    }
}
void remove_duplicates(Node* head) {
    Node* tmp = head;
    while (tmp != NULL && tmp->next != NULL) {
        Node* pointer = tmp;
        while (pointer->next != NULL) {
            if (tmp->val == pointer->next->val) {
                Node* duplicate = pointer->next;
                pointer->next = pointer->next->next;
                delete duplicate;
            } else {
                pointer = pointer->next;
            }
        }
        tmp = tmp->next;
    }
}
int main(){

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
    remove_duplicates(head);
    print_linked_list(head);
    return 0;
}