#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    string address;
    Node *next;
    Node(string addr) : address(addr), next(nullptr) {}
};

class SinglyList
{
public:
    Node *head;
    Node *tail;

    SinglyList() : head(nullptr), tail(nullptr) {}

    void insert(string address)
    {
        // Convert address to lowercase
        transform(address.begin(), address.end(), address.begin(), ::tolower);
        Node *newNode = new Node(address);
        if (!head)
        {
            head = tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
        }
    }

    Node *find(string address)
    {
        // Convert address to lowercase
        transform(address.begin(), address.end(), address.begin(), ::tolower);
        Node *current = head;
        while (current)
        {
            if (current->address == address)
            {
                return current;
            }
            current = current->next;
        }
        return nullptr;
    }

    Node *findPrev(Node *node)
    {
        if (!head || head == node)
        {
            return nullptr;
        }
        Node *current = head;
        while (current && current->next != node)
        {
            current = current->next;
        }
        return current;
    }
};

int main()
{
    SinglyList history;
    unordered_map<string, Node *> addressMap;
    string address;

    while (cin >> address && address != "end")
    {

        transform(address.begin(), address.end(), address.begin(), ::tolower);
        history.insert(address);
        addressMap[address] = history.tail;
    }

    int Q;
    cin >> Q;
    string command;
    Node *current = history.head;

    for (int i = 0; i < Q; ++i)
    {
        cin >> command;
        if (command == "visit")
        {
            cin >> address;

            transform(address.begin(), address.end(), address.begin(), ::tolower);
            if (addressMap.find(address) != addressMap.end())
            {
                current = addressMap[address];
                cout << current->address << endl;
            }
            else
            {
                cout << "Not Available" << endl;
            }
        }
        else if (command == "next")
        {
            if (current && current->next)
            {
                current = current->next;
                cout << current->address << endl;
            }
            else
            {
                cout << "Not Available" << endl;
            }
        }
        else if (command == "prev")
        {
            Node *prev = history.findPrev(current);
            if (prev)
            {
                current = prev;
                cout << current->address << endl;
            }
            else
            {
                cout << "Not Available" << endl;
            }
        }
    }

    return 0;
}
