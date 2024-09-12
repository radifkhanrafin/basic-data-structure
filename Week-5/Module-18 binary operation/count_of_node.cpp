#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int val;
    Node *left;
    Node *right;

    Node(int val)
    {
        this->val = val;
        this->left = NULL;
        this->right = NULL;
    }
};

Node *input_tree()
{
    int val;
    cin >> val;

    Node *root;
    if (val == -1)
    {
        root = NULL;
    }
    else
    {
        root = new Node(val);
    }

    queue<Node *> q;

    if (root)
    {
        q.push(root);
    }

    while (!q.empty())
    { // Fixed condition
        Node *parent = q.front();
        q.pop();

        int l, r;
        cin >> l >> r;

        Node *left = NULL;  // Initialize to NULL
        Node *right = NULL; // Initialize to NULL

        if (l != -1)
        {
            left = new Node(l);
        }
        if (r != -1)
        {
            right = new Node(r);
        }

        parent->left = left;
        parent->right = right;

        if (parent->left)
        {
            q.push(parent->left);
        }
        if (parent->right)
        {
            q.push(parent->right);
        }
    }
    return root;
}

void level_order(Node *root)
{
    if (!root)
        return;

    queue<Node *> p;
    p.push(root);
    while (!p.empty())
    {
        Node *n = p.front();
        p.pop();

        cout << n->val << " ";

        if (n->left)
        {
            p.push(n->left);
        }
        if (n->right)
        {
            p.push(n->right);
        }
    }
}

int count(Node *root)
{
    if (root == NULL)
        return 0;

    int l = count(root->left);
    int r = count(root->right);
    return l + r + 1;
}
int main()
{
    Node *root = input_tree();
    level_order(root);
    int nodes = count(root);
    cout <<endl<< nodes << " ";
    return 0;
}
