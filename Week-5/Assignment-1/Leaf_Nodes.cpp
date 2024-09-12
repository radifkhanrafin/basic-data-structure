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
        return NULL;
    }
    else
    {
        root = new Node(val);
    }

    queue<Node *> q;
    q.push(root);

    while (!q.empty())
    {
        Node *parent = q.front();
        q.pop();

        int l, r;
        cin >> l >> r;

        Node *left = NULL;
        Node *right = NULL;

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

void collect_leaves(Node *root, vector<int> &leaves)
{
    if (!root)
        return;
    if (!root->left && !root->right)
    {
        leaves.push_back(root->val);
    }
    collect_leaves(root->left, leaves);
    collect_leaves(root->right, leaves);
}

int main()
{
    Node *root = input_tree();

    vector<int> leaves;
    collect_leaves(root, leaves);

    sort(leaves.rbegin(), leaves.rend());

    for (int val : leaves)
    {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}
