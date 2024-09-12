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

    if (val == -1)
    {
        return NULL;
    }

    Node *root = new Node(val);
    queue<Node *> q;
    q.push(root);

    while (!q.empty())
    {
        Node *parent = q.front();
        q.pop();

        int l, r;
        cin >> l >> r;

        if (l != -1)
        {
            parent->left = new Node(l);
            q.push(parent->left);
        }

        if (r != -1)
        {
            parent->right = new Node(r);
            q.push(parent->right);
        }
    }

    return root;
}

void print_level(Node *root, int level)
{
    if (!root)
    {
        cout << "Invalid" << endl;
        return;
    }

    queue<Node *> q;
    q.push(root);
    int current_level = 0;

    while (!q.empty())
    {
        int node_count = q.size();
        if (current_level == level)
        {
            vector<int> nodes_at_level;
            while (node_count--)
            {
                Node *node = q.front();
                q.pop();
                nodes_at_level.push_back(node->val);
            }
            for (int val : nodes_at_level)
            {
                cout << val << " ";
            }
            cout << endl;
            return;
        }

        while (node_count--)
        {
            Node *node = q.front();
            q.pop();
            if (node->left)
                q.push(node->left);
            if (node->right)
                q.push(node->right);
        }
        current_level++;
    }
    cout << "Invalid" << endl;
}

int main()
{
    Node *root = input_tree();
    int level;
    cin >> level;

    print_level(root, level);

    return 0;
}
