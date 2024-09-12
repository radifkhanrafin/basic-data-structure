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

Node *inputTree()
{

    int val;
    cin >> val;
    Node *root;
    if (val == -1)
        root = NULL;
    else
        root = new Node(val);

    queue<Node *> q;
    if (root)
    {
        q.push(root);
    }
    while (!q.empty())
    {

        Node *parent = q.front();
        q.pop();
        int l, r;
        Node *left;
        Node *right;

        cin >> l >> r;

        if (l == -1)
        {
            left = NULL;
        }
        else
            left = new Node(l);
        if (r == -1)
        {
            right = NULL;
        }
        else
            right = new Node(r);

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

int count_left_node(Node *root)
{
    if (root==NULL)
        return 0;

    if (root->left == NULL && root->right == NULL)
        return 1;
    else
    {
        int l = count_left_node(root->left);
        int r = count_left_node(root->right);
        return l + r;
    }
}

int main()
{
    Node *root = inputTree();
    level_order(root);
    cout << count_left_node(root);
    return 0;
}