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

Node *convert(int arr[], int n, int l, int r)
{
    if (l > r)
        return NULL;
    int mid = (l + r) / 2;
    Node *root = new Node(arr[mid]);

    Node *leftRoot = convert(arr, n, l, mid - 1);
    Node *rightRoot = convert(arr, n, mid + 1, r);
    root->left = leftRoot;
    root->right = rightRoot;
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
int main()
{

    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    Node *root = convert(arr, n, 0, n - 1);

    level_order(root);
    cout << "";
    return 0;
}