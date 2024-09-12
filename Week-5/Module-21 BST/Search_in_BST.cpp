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
bool search(Node *root, int x)
{
    if (root == NULL)
        return false;
    if (root->val == x)
        return true;
    if (x < root->val)
        return search(root->left, x);
    else
        return search(root->right, x);
}

Node *insert_BST(Node *&root, int x)
{
    if (root == NULL)
    {

        return root = new Node(x);
    }

    if (x < root->val)
    {
        if (root->left == NULL)
            root->left = new Node(x);
        else
            insert_BST(root->left, x);
    }
    else
    {
        if (root->right == NULL)
            root->right = new Node(x);
        else
            insert_BST(root->right, x);
    }
    return root;
}
int main()
{
    Node *root = input_tree();
    insert_BST(root, 13);
    insert_BST(root, 32);
    insert_BST(root, 17);
    level_order(root);
    cout << endl
         << search(root, 8);
    return 0;
}