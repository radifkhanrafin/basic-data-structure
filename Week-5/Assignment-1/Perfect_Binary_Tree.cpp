#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int val;
    Node *left;
    Node *right;

    Node(int val) {
        this->val = val;
        this->left = NULL;
        this->right = NULL;
    }
};


Node *input_tree() {
    int val;
    cin >> val;

    if (val == -1) {
        return NULL;
    }

    Node *root = new Node(val);
    queue<Node *> q;
    q.push(root);

    while (!q.empty()) {
        Node *parent = q.front();
        q.pop();

        int l, r;
        cin >> l >> r;

        if (l != -1) {
            parent->left = new Node(l);
            q.push(parent->left);
        }

        if (r != -1) {
            parent->right = new Node(r);
            q.push(parent->right);
        }
    }

    return root;
}


int depth_node(Node *root) {
    if (!root) return 0;
    return max(depth_node(root->left), depth_node(root->right)) + 1;
}


int count_nodes(Node *root) {
    if (!root) return 0;
    return count_nodes(root->left) + count_nodes(root->right) + 1;
}
 
bool is_perfect_tree(Node *root) {
    if (!root) return true;

    int depth = depth_node(root) - 1;  
    int total_nodes = count_nodes(root);

    return total_nodes == (1 << (depth + 1)) - 1;
}

int main() {
    Node *root = input_tree();

    if (is_perfect_tree(root)) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }

    return 0;
}
