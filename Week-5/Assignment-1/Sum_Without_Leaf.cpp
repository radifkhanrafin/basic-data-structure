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

int sum_with_out_node(Node *root)
{
    if (!root)
        return 0;

    if (!root->left && !root->right)
        return 0;

    int left_sum = sum_with_out_node(root->left);
    int right_sum = sum_with_out_node(root->right);

    return root->val + left_sum + right_sum;
}

int main()
{
    Node *root = input_tree();
    int sum = sum_with_out_node(root);
    cout << sum << endl;
    return 0;
}
